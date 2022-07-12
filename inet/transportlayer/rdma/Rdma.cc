/*
 * Rdma.cc
 *
 *  Created on: Aug 10, 2021
 *      Author: vr4
 */

#include <algorithm>
#include <string>

#include "inet/common/IProtocolRegistrationListener.h"
#include "inet/common/LayeredProtocolBase.h"
#include "inet/common/ModuleAccess.h"
#include "inet/common/ProtocolTag_m.h"
#include "inet/common/checksum/TcpIpChecksum.h"
#include "inet/common/lifecycle/ModuleOperations.h"
#include "inet/common/lifecycle/NodeStatus.h"
#include "inet/common/packet/Packet.h"
#include "inet/linklayer/common/InterfaceTag_m.h"
#include "inet/networklayer/common/DscpTag_m.h"
#include "inet/networklayer/common/HopLimitTag_m.h"
#include "inet/networklayer/common/L3AddressTag_m.h"
#include "inet/networklayer/common/L3Tools.h"
#include "inet/networklayer/common/MulticastTag_m.h"
#include "inet/networklayer/common/NetworkInterface.h"
#include "inet/networklayer/common/TosTag_m.h"
#include "inet/networklayer/contract/IInterfaceTable.h"
#include "inet/networklayer/contract/IL3AddressType.h"
#include "inet/networklayer/contract/IInterfaceTable.h"
#include "inet/linklayer/common/MacAddressTag_m.h"

#ifdef INET_WITH_IPv4
#include "inet/networklayer/ipv4/Icmp.h"
#include "inet/networklayer/ipv4/IcmpHeader.h"
#include "inet/networklayer/ipv4/Ipv4Header_m.h"
#include "inet/networklayer/ipv4/Ipv4InterfaceData.h"
#endif // ifdef INET_WITH_IPv4

#ifdef INET_WITH_IPv6
#include "inet/networklayer/icmpv6/Icmpv6.h"
#include "inet/networklayer/icmpv6/Icmpv6Header_m.h"
#include "inet/networklayer/ipv6/Ipv6ExtensionHeaders_m.h"
#include "inet/networklayer/ipv6/Ipv6Header.h"
#include "inet/networklayer/ipv6/Ipv6InterfaceData.h"
#endif // ifdef INET_WITH_IPv6

#include "inet/transportlayer/common/L4PortTag_m.h"
#include "inet/transportlayer/common/L4Tools.h"
#include "inet/transportlayer/rdma/Rdma.h"
#include "inet/transportlayer/rdma/RdmaHeader_m.h"
#include "inet/clock/contract/ClockTime.h"
#include "inet/common/TimeTag_m.h"
namespace inet {

Define_Module(Rdma);

Rdma::Rdma()
{
}

Rdma::~Rdma()
{
    //clearAllSockets();
}

void Rdma::initialize(int stage)
{
    OperationalBase::initialize(stage);

    if (stage == INITSTAGE_LOCAL) {
        const char *crcModeString = par("crcMode");
        crcMode = parseCrcMode(crcModeString, true);
        lastEphemeralPort = EPHEMERAL_PORTRANGE_START;
        ift = getModuleFromPar<IInterfaceTable>(par("interfaceTableModule"), this);

        numSent = 0;
        numPassedUp = 0;
        numDroppedWrongPort = 0;
        numDroppedBadChecksum = 0;

        lowerLayerOut = gate("lowerLayerOut");
        transmissionChannel = lowerLayerOut->findTransmissionChannel();
        endTxTimer = new cMessage("EndTransmission", 103);

        WATCH(numSent);
        WATCH(numPassedUp);
        WATCH(numDroppedWrongPort);
        WATCH(numDroppedBadChecksum);

    }
    else if (stage == INITSTAGE_TRANSPORT_LAYER) {
        if (crcMode == CRC_COMPUTED) {
#ifdef INET_WITH_IPv4
            auto ipv4 = dynamic_cast<INetfilter *>(findModuleByPath("^.ipv4.ip"));
            if (ipv4 != nullptr)
                ipv4->registerHook(0, &crcInsertion);
#endif
#ifdef INET_WITH_IPv6
            auto ipv6 = dynamic_cast<INetfilter *>(findModuleByPath("^.ipv6.ipv6"));
            if (ipv6 != nullptr)
                ipv6->registerHook(0, &crcInsertion);
#endif
        }
        registerService(Protocol::rdma, gate("appIn"), gate("appOut"));
        registerProtocol(Protocol::rdma, gate("lowerLayerOut"), gate("lowerLayerIn"));
    }

}

void Rdma::handleMessageWhenUp(cMessage *msg)
{
    if (msg->isSelfMessage())
        handleSelfMessage(msg);
    else if (msg->getArrivalGateId() == findGate("appIn"))
        handleUpperPacket(check_and_cast<Packet *>(msg));
    else
        throw cRuntimeError("Message received from unknown gate!");
}

void Rdma::handleLowerPacket(Packet *packet)
{
    ASSERT(packet->getControlInfo() == nullptr);
    auto protocol = packet->getTag<PacketProtocolTag>()->getProtocol();
    if (protocol == &Protocol::rdma) {
        processRdmaPacket(packet);
    }
    else
        throw cRuntimeError("Unknown protocol: %s(%d)", protocol->getName(), protocol->getId());
}

void Rdma::handleSelfMessage(cMessage *msg){
    if (msg == endTxTimer)
            handleEndTxPeriod();
}

ushort Rdma::getEphemeralPort()
{
    // start at the last allocated port number + 1, and search for an unused one
    //ushort searchUntil = lastEphemeralPort++;
    if (lastEphemeralPort == EPHEMERAL_PORTRANGE_END) // wrap
        lastEphemeralPort = EPHEMERAL_PORTRANGE_START;

    // found a free one, return it
    return lastEphemeralPort;
}


// ###############################################################
// ####################### set options end #######################
// ###############################################################
//Handle a msg from application-layer and send it to the next layer
void Rdma::handleUpperPacket(Packet *p)
{
    EV_INFO << "Receive packet " << p << " from upper layer\n";
    packet = p;
    emit(packetReceivedFromUpperSignal, packet); //emit a signal indicating the arrival of a msg from app-layer

    //L3Address srcAddr, destAddr;
    auto addressReq = packet->addTagIfAbsent<L3AddressReq>();
    destAddr = addressReq->getDestAddress();
    auto time = packet->addTagIfAbsent<CreationTimeTag>();



    int srcPort = -1, destPort = -1;

    if (auto& portsReq = packet->removeTagIfPresent<L4PortReq>()) {
        srcPort = portsReq->getSrcPort();
        destPort = portsReq->getDestPort();
    }

    if(srcPort == -1)
        srcPort = rand() % 65535;
    if(destPort == -1)
        destPort = rand() % 65535;

    const auto& interfaceReq = packet->findTag<InterfaceReq>();
    ASSERT(interfaceReq == nullptr || interfaceReq->getInterfaceId() != -1);

    if (destAddr.isUnspecified())
        throw cRuntimeError("send: unspecified destination address");
    if (destPort <= 0 || destPort > 65535)
        throw cRuntimeError("send: invalid remote port number %d", destPort);

    //const Protocol *l3Protocol = nullptr;
    // TODO apps use ModuleIdAddress if the network interface doesn't have an IP address configured, and UDP uses NextHopForwarding which results in a weird error in MessageDispatcher
    if (destAddr.getType() == L3Address::IPv4)
        l3Protocol = &Protocol::ipv4;
    else if (destAddr.getType() == L3Address::IPv6)
        l3Protocol = &Protocol::ipv6;
    else
        l3Protocol = &Protocol::nextHopForwarding;

    rdmaHeader = makeShared<RdmaHeader>();

    // set source and destination port
    rdmaHeader->setSourcePort(srcPort);
    rdmaHeader->setDestinationPort(destPort);
    rdmaHeader->setIdentification(getParentModule()->getId() *10 + numSent);

    B totalLength = rdmaHeader->getChunkLength() + packet->getTotalLength();

    if (totalLength.get() <= RDMA_MAX_MESSAGE_SIZE) {
        rdmaHeader->setTotalLengthField(totalLength);
        if (crcMode == CRC_COMPUTED) {
            rdmaHeader->setCrcMode(CRC_COMPUTED);
            rdmaHeader->setCrc(0x0000);
        } else {
            rdmaHeader->setCrcMode(crcMode);
            insertCrc(l3Protocol, srcAddr, destAddr, rdmaHeader, packet);
        }

        insertTransportProtocolHeader(packet, Protocol::rdma, rdmaHeader);
        packet->addTagIfAbsent<DispatchProtocolReq>()->setProtocol(l3Protocol);
        packet->addTagIfAbsent<PacketProtocolTag>()->setProtocol(&Protocol::rdma);
        packet->setKind(0);

        EV_INFO << "Sending app packet " << packet->getName() << " over " << l3Protocol->getName() << ".\n";
        emit(packetSentSignal, packet); //emit a signal indicating the sending of a msg
        emit(packetSentToLowerSignal, packet); //emit a signal indicating the sending of a msg to lower layer

        send(packet, "lowerLayerOut");
        numSent++;
    }else{
        // FIXME some IP options should not be copied into each fragment, check their COPY bit
        headerLength = RDMA_HEADER_LENGTH.get();
        payloadLength = B(packet->getDataLength()).get() - headerLength;
        fragmentLength = ((RDMA_MAX_MESSAGE_SIZE - headerLength) / 8) * 8; // payload only (without header)
        offsetBase = rdmaHeader->getFragmentOffset();
        if (fragmentLength <= 0)
            throw cRuntimeError("Cannot fragment datagram: RDMA_MAX_MESSAGE_SIZE=%d too small for header size (%d bytes)", RDMA_MAX_MESSAGE_SIZE, headerLength); // exception and not ICMP because this is likely a simulation configuration error, not something one wants to simulate

        if(noOfFragments == 0){
        noOfFragments = (payloadLength + fragmentLength - 1) / fragmentLength;
        EV_DETAIL << "Breaking datagram into " << noOfFragments << " fragments\n";
        }

        // create and send fragments
        fragMsgName = packet->getName();
        fragMsgName += "-frag-";

        offset = 0;
        while (offset < payloadLength) {
            bool lastFragment = (offset + fragmentLength >= payloadLength);
            // length equal to fragmentLength, except for last fragment;
            int thisFragmentLength = lastFragment ? payloadLength - offset : fragmentLength;

            std::string curFragName = fragMsgName + std::to_string(offset);
            if (lastFragment)
                curFragName += "-last";
            Packet *fragment = new Packet(curFragName.c_str()); // TODO add offset or index to fragment name

            // copy Tags from packet to fragment
            fragment->copyTags(*packet);

            ASSERT(fragment->getByteLength() == 0);
            auto fraghdr = staticPtrCast<RdmaHeader>(rdmaHeader->dupShared());
            const auto& fragData = packet->peekDataAt(B(headerLength + offset), B(thisFragmentLength));
            ASSERT(fragData->getChunkLength() == B(thisFragmentLength));
            fragment->insertAtBack(fragData);

            // "more fragments" bit is unchanged in the last fragment, otherwise true
            if (!lastFragment)
                fraghdr->setMoreFragments(true);

            fraghdr->setFragmentOffset(offsetBase + offset);
            EV_INFO << fraghdr->getFragmentOffset() <<"\n";
            fraghdr->setTotalLengthField(B(headerLength + thisFragmentLength));

            if (crcMode == CRC_COMPUTED) {
                fraghdr->setCrcMode(CRC_COMPUTED);
                fraghdr->setCrc(0x0000); // crcMode == CRC_COMPUTED is done in an INetfilter hook
            } else {
                fraghdr->setCrcMode(crcMode);
                insertCrc(l3Protocol, srcAddr, destAddr, fraghdr, fragment);
            }

            insertTransportProtocolHeader(fragment, Protocol::rdma, fraghdr);
            fragment->addTagIfAbsent<DispatchProtocolReq>()->setProtocol(l3Protocol);
            fragment->addTagIfAbsent<PacketProtocolTag>()->setProtocol(&Protocol::rdma);
            fragment->setKind(0);

            fragment->insertAtFront(fraghdr);
            EV_INFO << "Sending fragment " << fragment << " over " << l3Protocol->getName() << ".\n";
            send(fragment, "lowerLayerOut");
            offset += thisFragmentLength;
        }
        numSent++;

    }

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void Rdma::insertCrc(const Protocol *networkProtocol, const L3Address& srcAddress, const L3Address& destAddress, const Ptr<RdmaHeader>& rdmaHeader, Packet *packet)
{
    CrcMode crcMode = rdmaHeader->getCrcMode();
    switch (crcMode) {
        case CRC_DISABLED:
            // if the CRC mode is disabled, then the CRC is 0
            rdmaHeader->setCrc(0x0000);
            break;
        case CRC_DECLARED_CORRECT:
            // if the CRC mode is declared to be correct, then set the CRC to an easily recognizable value
            rdmaHeader->setCrc(0xC00D);
            break;
        case CRC_DECLARED_INCORRECT:
            // if the CRC mode is declared to be incorrect, then set the CRC to an easily recognizable value
            rdmaHeader->setCrc(0xBAAD);
            break;
        case CRC_COMPUTED: {
            // if the CRC mode is computed, then compute the CRC and set it
            // this computation is delayed after the routing decision, see INetfilter hook
            rdmaHeader->setCrc(0x0000); // make sure that the CRC is 0 in the Udp header before computing the CRC --
            rdmaHeader->setCrcMode(CRC_DISABLED); // for serializer/deserializer checks only: deserializer sets the crcMode to disabled when crc is 0 --
            auto rdmaData = packet->peekData(Chunk::PF_ALLOW_EMPTY);
            auto crc = computeCrc(networkProtocol, srcAddress, destAddress, rdmaHeader, rdmaData);
            rdmaHeader->setCrc(crc);
            rdmaHeader->setCrcMode(CRC_COMPUTED);
            break;
        }
        default:
            throw cRuntimeError("Unknown CRC mode: %d", (int)crcMode);
    }
}

uint16_t Rdma::computeCrc(const Protocol *networkProtocol, const L3Address& srcAddress, const L3Address& destAddress, const Ptr<const RdmaHeader>& rdmaHeader, const Ptr<const Chunk>& rdmaData)
{
    auto pseudoHeader = makeShared<TransportPseudoHeader>();
    pseudoHeader->setSrcAddress(srcAddress);
    pseudoHeader->setDestAddress(destAddress);
    pseudoHeader->setNetworkProtocolId(networkProtocol->getId());
    pseudoHeader->setProtocolId(IP_PROT_RDMA);
    pseudoHeader->setPacketLength(rdmaHeader->getChunkLength() + rdmaData->getChunkLength());
    // pseudoHeader length: ipv4: 12 bytes, ipv6: 40 bytes, other: ???
    if (networkProtocol == &Protocol::ipv4)
        pseudoHeader->setChunkLength(B(12));
    else if (networkProtocol == &Protocol::ipv6)
        pseudoHeader->setChunkLength(B(40));
    else
        throw cRuntimeError("Unknown network protocol: %s", networkProtocol->getName());

    MemoryOutputStream stream;
    Chunk::serialize(stream, pseudoHeader);
    Chunk::serialize(stream, rdmaHeader);
    Chunk::serialize(stream, rdmaData);
    uint16_t crc = TcpIpChecksum::checksum(stream.getData());

    // Excerpt from RFC 768:
    // If the computed  checksum  is zero,  it is transmitted  as all ones (the
    // equivalent  in one's complement  arithmetic).   An all zero  transmitted
    // checksum  value means that the transmitter  generated  no checksum  (for
    // debugging or for higher level protocols that don't care).
    return crc == 0x0000 ? 0xFFFF : crc;
}


void Rdma::processRdmaPacket(Packet *rdmaPacket)
{
    ASSERT(rdmaPacket->getControlInfo() == nullptr);
    emit(packetReceivedFromLowerSignal, rdmaPacket);
    emit(packetReceivedSignal, rdmaPacket);

    rdmaPacket->removeTag<PacketProtocolTag>();
    b rdmaHeaderPopPosition = rdmaPacket->getFrontOffset();
    auto rdmaHeader = rdmaPacket->popAtFront<RdmaHeader>(b(-1), Chunk::PF_ALLOW_INCORRECT);

    // simulate checksum: discard packet if it has bit error
    EV_INFO << "Packet " << rdmaPacket->getName() << " received from network, dest port " << rdmaHeader->getDestinationPort() << "\n";

    auto srcPort = rdmaHeader->getSourcePort();
    auto destPort = rdmaHeader->getDestinationPort();
    auto l3AddressInd = rdmaPacket->getTag<L3AddressInd>();
    auto totalLength = B(rdmaHeader->getTotalLengthField());
    auto hasIncorrectLength = totalLength<rdmaHeader->getChunkLength() || totalLength> rdmaHeader->getChunkLength() + rdmaPacket->getDataLength();
    auto networkProtocol = rdmaPacket->getTag<NetworkProtocolInd>()->getProtocol();

    if (hasIncorrectLength || !verifyCrc(networkProtocol, rdmaHeader, rdmaPacket)) {
        EV_WARN << "Packet has bit error, discarding\n";
        PacketDropDetails details;
        details.setReason(INCORRECTLY_RECEIVED);
        emit(packetDroppedSignal, rdmaPacket, &details);
        numDroppedBadChecksum++;
        delete rdmaPacket;
        return;
    }

    // remove lower layer paddings:
    if (totalLength < rdmaPacket->getDataLength()) {
        rdmaPacket->setBackOffset(rdmaHeaderPopPosition + totalLength);
    }


    sendUp(rdmaHeader, rdmaPacket, srcPort, destPort);//, generationTime);
}

void Rdma::sendUp(Ptr<const RdmaHeader>& header, Packet *payload, ushort srcPort, ushort destPort)//, clocktime_t generationTime)
{
    EV_INFO << "Sending payload up to app layer\n";

    payload->addTagIfAbsent<TransportProtocolInd>()->setProtocol(&Protocol::rdma);
    payload->addTagIfAbsent<TransportProtocolInd>()->setTransportProtocolHeader(header);
    payload->addTagIfAbsent<L4PortInd>()->setSrcPort(srcPort);
    payload->addTagIfAbsent<L4PortInd>()->setDestPort(destPort);

    emit(packetSentToUpperSignal, payload);
    send(payload, "appOut");
    numPassedUp++;
}
bool Rdma::verifyCrc(const Protocol *networkProtocol, const Ptr<const RdmaHeader>& rdmaHeader, Packet *packet)
{
    switch (rdmaHeader->getCrcMode()) {
        case CRC_DISABLED:
            // if the CRC mode is disabled, then the check passes if the CRC is 0
            return rdmaHeader->getCrc() == 0x0000;
        case CRC_DECLARED_CORRECT: {
            // if the CRC mode is declared to be correct, then the check passes if and only if the chunks are correct
            auto totalLength = rdmaHeader->getTotalLengthField();
            auto rdmaDataBytes = packet->peekDataAt(B(0), totalLength - rdmaHeader->getChunkLength(), Chunk::PF_ALLOW_INCORRECT);
            return rdmaHeader->isCorrect() && rdmaDataBytes->isCorrect();
        }
        case CRC_DECLARED_INCORRECT:
            // if the CRC mode is declared to be incorrect, then the check fails
            return false;
        case CRC_COMPUTED: {
            if (rdmaHeader->getCrc() == 0x0000)
                // if the CRC mode is computed and the CRC is 0 (disabled), then the check passes
                return true;
            else {
                // otherwise compute the CRC, the check passes if the result is 0xFFFF (includes the received CRC) and the chunks are correct
                auto l3AddressInd = packet->getTag<L3AddressInd>();
                auto srcAddress = l3AddressInd->getSrcAddress();
                auto destAddress = l3AddressInd->getDestAddress();
                auto totalLength = rdmaHeader->getTotalLengthField();
                auto rdmaData = packet->peekDataAt<BytesChunk>(B(0), totalLength - rdmaHeader->getChunkLength(), Chunk::PF_ALLOW_INCORRECT);
                auto computedCrc = computeCrc(networkProtocol, srcAddress, destAddress, rdmaHeader, rdmaData);
                // TODO delete these isCorrect calls, rely on CRC only
                return computedCrc == 0xFFFF && rdmaHeader->isCorrect() && rdmaData->isCorrect();
            }
        }
        default:
            throw cRuntimeError("Unknown CRC mode");
    }
}


void Rdma::processUndeliverablePacket(Packet *rdmaPacket)
{
    const auto& rdmaHeader = rdmaPacket->peekAtFront<RdmaHeader>();
    PacketDropDetails details;
    details.setReason(NO_PORT_FOUND);
    emit(packetDroppedSignal, rdmaPacket, &details);
    numDroppedWrongPort++;

    // send back ICMP PORT_UNREACHABLE
    char buff[80];
    snprintf(buff, sizeof(buff), "Port %d unreachable", rdmaHeader->getDestinationPort());
    rdmaPacket->setName(buff);
    const Protocol *protocol = rdmaPacket->getTag<NetworkProtocolInd>()->getProtocol();

    if (protocol == nullptr) {
        throw cRuntimeError("(%s)%s arrived from lower layer without NetworkProtocolInd",
                rdmaPacket->getClassName(), rdmaPacket->getName());
    }

    // push back network protocol header
    rdmaPacket->trim();
    rdmaPacket->insertAtFront(rdmaPacket->getTag<NetworkProtocolInd>()->getNetworkProtocolHeader());
    auto inIe = rdmaPacket->getTag<InterfaceInd>()->getInterfaceId();

    if (protocol->getId() == Protocol::ipv4.getId()) {
#ifdef INET_WITH_IPv4
        if (!icmp)
            // TODO move to initialize?
            icmp = getModuleFromPar<Icmp>(par("icmpModule"), this);
        icmp->sendErrorMessage(rdmaPacket, inIe, ICMP_DESTINATION_UNREACHABLE, ICMP_DU_PORT_UNREACHABLE);
#endif // ifdef INET_WITH_IPv4
        delete rdmaPacket;
    }
    else if (protocol->getId() == Protocol::ipv6.getId()) {
#ifdef INET_WITH_IPv6
        if (!icmpv6)
            // TODO move to initialize?
            icmpv6 = getModuleFromPar<Icmpv6>(par("icmpv6Module"), this);
        icmpv6->sendErrorMessage(rdmaPacket, ICMPv6_DESTINATION_UNREACHABLE, PORT_UNREACHABLE);
#endif // ifdef INET_WITH_IPv6
        delete rdmaPacket;
    }
    else if (protocol->getId() == Protocol::nextHopForwarding.getId()) {
        delete rdmaPacket;
    }
    else {
        throw cRuntimeError("(%s)%s arrived from lower layer with unrecognized NetworkProtocolInd %s",
                rdmaPacket->getClassName(), rdmaPacket->getName(), protocol->getName());
        delete rdmaPacket;
    }
}


// #############################
// other UDP methods
// #############################
void Rdma::handleStartOperation(LifecycleOperation *operation)
{
    icmp = nullptr;
    icmpv6 = nullptr;
}

void Rdma::handleStopOperation(LifecycleOperation *operation)
{
    icmp = nullptr;
    icmpv6 = nullptr;
}

void Rdma::handleCrashOperation(LifecycleOperation *operation)
{
    icmp = nullptr;
    icmpv6 = nullptr;
}

void Rdma::refreshDisplay() const
{
    OperationalBase::refreshDisplay();

    char buf[80];
    sprintf(buf, "passed up: %d pks\nsent: %d pks", numPassedUp, numSent);
    if (numDroppedWrongPort > 0) {
        sprintf(buf + strlen(buf), "\ndropped (no app): %d pks", numDroppedWrongPort);
        getDisplayString().setTagArg("i", 1, "red");
    }
    getDisplayString().setTagArg("t", 0, buf);
}

// used in UdpProtocolDissector
bool Rdma::isCorrectPacket(Packet *packet, const Ptr<const RdmaHeader>& rdmaHeader)
{
    auto trailerPopOffset = packet->getBackOffset();
    auto rdmaHeaderOffset = packet->getFrontOffset() - rdmaHeader->getChunkLength();
    if (rdmaHeader->getTotalLengthField() < RDMA_HEADER_LENGTH)
        return false;
    else if (B(rdmaHeader->getTotalLengthField()) > trailerPopOffset - rdmaHeaderOffset)
        return false;
    else {
        const auto& l3AddressInd = packet->findTag<L3AddressInd>();
        const auto& networkProtocolInd = packet->findTag<NetworkProtocolInd>();
        if (l3AddressInd != nullptr && networkProtocolInd != nullptr)
            return verifyCrc(networkProtocolInd->getProtocol(), rdmaHeader, packet);
        else
            return rdmaHeader->getCrcMode() != CrcMode::CRC_DECLARED_INCORRECT;
    }
}


// ######################
// other methods
// ######################

INetfilter::IHook::Result Rdma::CrcInsertion::datagramPostRoutingHook(Packet *packet)
{
    if (packet->findTag<InterfaceInd>())
        return ACCEPT; // FORWARD

    auto networkProtocol = packet->getTag<PacketProtocolTag>()->getProtocol();
    const auto& networkHeader = getNetworkProtocolHeader(packet);
    if (networkHeader->getProtocol() == &Protocol::rdma) {
        ASSERT(!networkHeader->isFragment());
        packet->eraseAtFront(networkHeader->getChunkLength());
        auto rdmaHeader = packet->removeAtFront<RdmaHeader>();
        ASSERT(rdmaHeader->getCrcMode() == CRC_COMPUTED);
        const L3Address& srcAddress = networkHeader->getSourceAddress();
        const L3Address& destAddress = networkHeader->getDestinationAddress();
        Rdma::insertCrc(networkProtocol, srcAddress, destAddress, rdmaHeader, packet);
        packet->insertAtFront(rdmaHeader);
        packet->insertAtFront(networkHeader);
    }

    return ACCEPT;
}

void Rdma::handleEndTxPeriod(){
    if(offset < payloadLength){
        bool lastFragment = (offset + fragmentLength >= payloadLength);
        // length equal to fragmentLength, except for last fragment;
        int thisFragmentLength = lastFragment ? payloadLength - offset : fragmentLength;

        std::string curFragName = fragMsgName + std::to_string(offset);
        if (lastFragment)
            curFragName += "-last";
        Packet *fragment = new Packet(curFragName.c_str()); // TODO add offset or index to fragment name

        // copy Tags from packet to fragment
        fragment->copyTags(*packet);

        ASSERT(fragment->getByteLength() == 0);
        auto fraghdr = staticPtrCast<RdmaHeader>(rdmaHeader->dupShared());
        const auto &fragData = packet->peekDataAt(B(headerLength + offset), B(thisFragmentLength));
        ASSERT(fragData->getChunkLength() == B(thisFragmentLength));
        fragment->insertAtBack(fragData);

        // "more fragments" bit is unchanged in the last fragment, otherwise true
        if (!lastFragment)
            fraghdr->setMoreFragments(true);

        fraghdr->setFragmentOffset(offsetBase + offset);
        fraghdr->setTotalLengthField(B(headerLength + thisFragmentLength));

        if (crcMode == CRC_COMPUTED) {
            fraghdr->setCrcMode(CRC_COMPUTED);
            fraghdr->setCrc(0x0000);
        } else {
            fraghdr->setCrcMode(crcMode);
            insertCrc(l3Protocol, srcAddr, destAddr, fraghdr, fragment);
        }

        insertTransportProtocolHeader(fragment, Protocol::rdma, fraghdr);
        fragment->addTagIfAbsent<DispatchProtocolReq>()->setProtocol(l3Protocol);
        fragment->addTagIfAbsent<PacketProtocolTag>()->setProtocol(&Protocol::rdma);
        fragment->setKind(0);

        fragment->insertAtFront(fraghdr);

        EV_INFO << "Sending app packet " << fragment->getName() << " over " << l3Protocol->getName() << ".\n";
        emit(packetSentSignal, fragment);
        emit(packetSentToLowerSignal, fragment);
        send(fragment, "lowerLayerOut");

        offset += thisFragmentLength;

        scheduleAt(transmissionChannel->getTransmissionFinishTime(), endTxTimer);
    }else{
        offset = 0;
        numSent++;
    }
}
// unused functions!

RdmaHeader *Rdma::createRdmaPacket()
{
    return new RdmaHeader();
}


} // namespace inet

