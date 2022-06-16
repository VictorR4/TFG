//
// Copyright (C) 2000 Institut fuer Telematik, Universitaet Karlsruhe
// Copyright (C) 2004,2011 OpenSim Ltd.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#include "inet/applications/udpapp/MyUdpBasicApp.h"

#include "inet/applications/base/ApplicationPacket_m.h"
#include "inet/common/ModuleAccess.h"
#include "inet/common/TagBase_m.h"
#include "inet/common/TimeTag_m.h"
#include "inet/common/lifecycle/ModuleOperations.h"
#include "inet/common/packet/Packet.h"
#include "inet/networklayer/common/FragmentationTag_m.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/transportlayer/contract/udp/UdpControlInfo_m.h"
#include "inet/transportlayer/udp/UdpHeader_m.h"
#include "inet/transportlayer/udp/Udp.h"

namespace inet {

Define_Module(MyUdpBasicApp);

MyUdpBasicApp::~MyUdpBasicApp()
{
    cancelAndDelete(selfMsg);
}

void MyUdpBasicApp::initialize(int stage)
{
    ClockUserModuleMixin::initialize(stage);

    if (stage == INITSTAGE_LOCAL) {
        numSent = 0;
        numReceived = 0;
        WATCH(numSent);
        WATCH(numReceived);

        localPort = par("localPort");
        destPort = par("destPort");
        startTime = par("startTime");
        stopTime = par("stopTime");
        packetName = par("packetName");
        dontFragment = par("dontFragment");
        packetsToSend = par("packetsToSend");
        if(packetsToSend == -1)
            packetsToSend = INT_MAX;
        fragmentSize = B(par("fragmentSize"));
        if(fragmentSize > B(UDP_MAX_MESSAGE_SIZE) - B(UDP_HEADER_LENGTH) || fragmentSize <= B(0)){
            throw cRuntimeError("Invalid value for fragment size");
        }
        if (stopTime >= CLOCKTIME_ZERO && stopTime < startTime)
            throw cRuntimeError("Invalid startTime/stopTime parameters");
        selfMsg = new ClockEvent("sendTimer");
        lowerLayerOut = gate("socketOut");
        transmissionChannel = lowerLayerOut->findTransmissionChannel();
        endTxTimer = new cMessage("EndTransmission", 103);
        queue = new cPacketQueue("receiveQueue");
        isGlobalArp = par("isGlobalArp");
    }
}

void MyUdpBasicApp::finish()
{
    if(isGlobalArp){
        numSent--;
        numReceived--;
    }
    recordScalar("packets sent", numSent);
    recordScalar("packets received", numReceived);
    EV << "Media: " << statsLatency.getMean() << endl;
    EV << "Desviación típica: " << statsLatency.getStddev() << endl;
    //Calculo del intervalo de confianza
    auto confidenceIntervalMax = statsLatency.getMean() + 1.96 * statsLatency.getStddev()/sqrt(numReceived);
    auto confidenceIntervalMin = statsLatency.getMean() - 1.96 * statsLatency.getStddev()/sqrt(numReceived);
    EV_INFO << "Invervalo de confianza: (" << confidenceIntervalMin << "," << confidenceIntervalMax << ")\n";
    for (int i = 0; i < numReceived; i++) {
        if(latencyPackets[i] >= confidenceIntervalMin){
            latency += latencyPackets[i];
            valoresValidos++;
        }
    }
    recordScalar("meanLatency", latency.dbl()/valoresValidos, "s");
    EV_INFO << "Media de confianza = " << latency.dbl()/valoresValidos << "\n";
    EV_INFO << "Latency = " << latency.dbl() << "\n";
    EV_INFO << "Valores validos = " << valoresValidos << "\n";
    statsLatency.collect(latency);
    statsLatency.recordAs("statsLatency");
    recordScalar("valoresValidos", valoresValidos);
    ApplicationBase::finish();
}

void MyUdpBasicApp::setSocketOptions()
{
    int timeToLive = par("timeToLive");
    if (timeToLive != -1)
        socket.setTimeToLive(timeToLive);

    int dscp = par("dscp");
    if (dscp != -1)
        socket.setDscp(dscp);

    int tos = par("tos");
    if (tos != -1)
        socket.setTos(tos);

    const char *multicastInterface = par("multicastInterface");
    if (multicastInterface[0]) {
        IInterfaceTable *ift = getModuleFromPar<IInterfaceTable>(par("interfaceTableModule"), this);
        NetworkInterface *ie = ift->findInterfaceByName(multicastInterface);
        if (!ie)
            throw cRuntimeError("Wrong multicastInterface setting: no interface named \"%s\"", multicastInterface);
        socket.setMulticastOutputInterface(ie->getInterfaceId());
    }

    bool receiveBroadcast = par("receiveBroadcast");
    if (receiveBroadcast)
        socket.setBroadcast(true);

    bool joinLocalMulticastGroups = par("joinLocalMulticastGroups");
    if (joinLocalMulticastGroups) {
        MulticastGroupList mgl = getModuleFromPar<IInterfaceTable>(par("interfaceTableModule"), this)->collectMulticastGroups();
        socket.joinLocalMulticastGroups(mgl);
    }
    socket.setCallback(this);
}

L3Address MyUdpBasicApp::chooseDestAddr()
{
    int k = intrand(destAddresses.size());
    if (destAddresses[k].isUnspecified() || destAddresses[k].isLinkLocal()) {
        L3AddressResolver().tryResolve(destAddressStr[k].c_str(), destAddresses[k]);
    }
    return destAddresses[k];
}

void MyUdpBasicApp::sendPacket()
{
    if(packetsToSend > numSent){
        std::string str;
        str = packetName; str += "_"; str += getParentModule()->getName(); str += "-"; str += std::to_string(numSent);

        const auto& payload = makeShared<ApplicationPacket>();

        if(numSent == 0 && isGlobalArp)
            messageLength = B(par("firstPacket"));
        else
            messageLength = B(par("messageLength"));

        if(messageLength <= fragmentSize){
            Packet *packet = new Packet(str.c_str());

            if (dontFragment)
                packet->addTag<FragmentationReq>()->setDontFragment(true);

            payload->setChunkLength(messageLength);
            payload->setSequenceNumber(numSent);
            payload->addTag<CreationTimeTag>()->setCreationTime(creationTime);
            packet->insertAtBack(payload);

            destAddr = chooseDestAddr();
            EV_INFO << "Sending packet " << packet << "\n";
            emit(packetSentSignal, packet);
            socket.sendTo(packet, destAddr, destPort);
            numSent++;
        }else{
            int noOfFragments =  messageLength.get() % fragmentSize.get() != 0 ? messageLength.get()/fragmentSize.get() + 1 : messageLength.get()/fragmentSize.get() ;
            int offsetBase = payload->getFragmentOffset();
            if(offset == B(0))
                EV_DETAIL << "Breaking message into " << noOfFragments << " fragments\n";

            fragMsgName = str;
            fragMsgName += "-frag-";

            if(transmissionChannel){
                bool lastFragment = (offset + fragmentSize >= messageLength);
                B thisFragmentLength = lastFragment ? messageLength - offset : fragmentSize;

                std::string curFragName = fragMsgName + std::to_string(offset.get());
                if (lastFragment)
                    curFragName += "-last";
                else
                    payload->setMoreFragments(true);

                if(offset != B(0)){
                    payload->setFirstFragment(false);
                    EV_INFO << "Creation time false = " << creationTime << "\n";
                }else{
                    EV_INFO << "Creation time true = " << creationTime << "\n";
                }


                payload->setChunkLength(thisFragmentLength);
                payload->setFragmentOffset(offsetBase + offset.get());
                Packet *fragment = new Packet(curFragName.c_str());

                if (dontFragment)
                    fragment->addTag<FragmentationReq>()->setDontFragment(true);

                payload->setSequenceNumber(numSent);
                payload->addTag<CreationTimeTag>()->setCreationTime(creationTime);
                fragment->insertAtBack(payload);
                EV_INFO << "Creation time saved = " << fragment->getCreationTime() << "\n";

                destAddr = chooseDestAddr();
                emit(packetSentSignal, fragment);

                EV_INFO << "Sending fragment " << fragment << "\n";
                socket.sendTo(fragment, destAddr, destPort);

                scheduleAt(transmissionChannel->getTransmissionFinishTime(), endTxTimer);
                offset += thisFragmentLength;

                if(!payload->getMoreFragments())
                    numSent++;

            }else{
                int noOfFragments =  messageLength.get() % fragmentSize.get() != 0 ? messageLength.get()/fragmentSize.get() + 1 : messageLength.get()/fragmentSize.get() ;
                if(offset == B(0))
                    EV_DETAIL << "Breaking message into " << noOfFragments << " fragments\n";

                fragMsgName = str;
                fragMsgName += "-frag-";

                while(offset < messageLength){
                    bool lastFragment = (offset + fragmentSize >= messageLength);
                    B thisFragmentLength = lastFragment ? fragmentSize - offset : fragmentSize;

                    std::string curFragName = fragMsgName + std::to_string(offset.get());
                    if (lastFragment)
                        curFragName += "-last";
                    else
                        payload->setMoreFragments(true);

                    if(offset != B(0))
                        payload->setFirstFragment(false);

                    payload->setChunkLength(fragmentSize);
                    Packet *fragment = new Packet(curFragName.c_str());
                    if (dontFragment)
                        fragment->addTag<FragmentationReq>()->setDontFragment(true);
                    payload->setSequenceNumber(numSent);
                    payload->addTag<CreationTimeTag>()->setCreationTime(creationTime);
                    fragment->insertAtBack(payload);
                    destAddr = chooseDestAddr();
                    emit(packetSentSignal, fragment);
                    socket.sendTo(fragment, destAddr, destPort);
                    offset += thisFragmentLength;
                }
                numSent++;
            }
        }


        //packet->addTagIfAbsent<CreationTimeTag>()->setCreationTime(simTime());//Mio
    }
}

void MyUdpBasicApp::processStart()
{
    socket.setOutputGate(gate("socketOut"));
    const char *localAddress = par("localAddress");
    socket.bind(*localAddress ? L3AddressResolver().resolve(localAddress) : L3Address(), localPort);
    setSocketOptions();

    const char *destAddrs = par("destAddresses");
    cStringTokenizer tokenizer(destAddrs);
    const char *token;

    bool excludeLocalDestAddresses = par("excludeLocalDestAddresses");
    IInterfaceTable *ift = getModuleFromPar<IInterfaceTable>(par("interfaceTableModule"), this);

 /*   while ((token = tokenizer.nextToken()) != nullptr) {
        destAddressStr.push_back(token);
        L3Address result;
        L3AddressResolver().tryResolve(token, result);
        if (result.isUnspecified())
            EV_ERROR << "cannot resolve destination address: " << token << endl;
        else if (excludeLocalDestAddresses && ift && ift->isLocalAddress(result))
            continue;
        destAddresses.push_back(result);
    }
*/
    while ((token = tokenizer.nextToken()) != nullptr) {
        if (strstr(token, "Broadcast") != nullptr)
            destAddresses.push_back(Ipv4Address::ALLONES_ADDRESS);
        else {
            L3Address addr = L3AddressResolver().resolve(token);
            if (excludeLocalDestAddresses && ift && ift->isLocalAddress(addr))
                continue;
            destAddresses.push_back(addr);
        }
    }
    if (!destAddresses.empty()) {
        selfMsg->setKind(SEND);
        processSend();
    }
    else {
        if (stopTime >= CLOCKTIME_ZERO) {
            selfMsg->setKind(STOP);
            scheduleClockEventAt(stopTime, selfMsg);
        }
    }
}

void MyUdpBasicApp::processSend()
{
    creationTime = simTime();
    sendPacket();
    clocktime_t d = par("sendInterval");
    if (stopTime < CLOCKTIME_ZERO || getClockTime() + d < stopTime) {
        selfMsg->setKind(SEND);
        scheduleClockEventAfter(d, selfMsg);
    }
    else {
        selfMsg->setKind(STOP);
        scheduleClockEventAt(stopTime, selfMsg);
    }
}

void MyUdpBasicApp::processStop()
{
    socket.close();
}

void MyUdpBasicApp::handleMessageWhenUp(cMessage *msg)
{
        if (msg->isSelfMessage()) {
            if(msg == endTxTimer){
                handleEndTxPeriod();
            }
            else{
                ASSERT(msg == selfMsg);
                switch (selfMsg->getKind()) {
                    case START:
                        processStart();
                        break;

                    case SEND:
                        processSend();
                        break;

                    case STOP:
                        processStop();
                        break;

                    default:
                        throw cRuntimeError("Invalid kind %d in self message", (int)selfMsg->getKind());
                }
            }
        }
        else
            socket.processMessage(msg);
}
void MyUdpBasicApp::socketDataArrived(UdpSocket *socket, Packet *packet)
{
    // process incoming packet
    processPacket(packet);
}

void MyUdpBasicApp::socketErrorArrived(UdpSocket *socket, Indication *indication)
{
    EV_WARN << "Ignoring UDP error report " << indication->getName() << endl;
    delete indication;
}

void MyUdpBasicApp::socketClosed(UdpSocket *socket)
{
    if (operationalState == State::STOPPING_OPERATION)
        startActiveOperationExtraTimeOrFinish(par("stopOperationExtraTime"));
}

void MyUdpBasicApp::refreshDisplay() const
{
    ApplicationBase::refreshDisplay();

    char buf[100];
    sprintf(buf, "rcvd: %d pks\nsent: %d pks\n latency: %f s", numReceived, numSent, latency.dbl());
    getDisplayString().setTagArg("t", 0, buf);
}

void MyUdpBasicApp::processPacket(Packet *pk)
{
    if(numReceived == 0 && isGlobalArp){
        delete pk;
        numReceived++;
    }else{

    auto payload = pk->peekAtFront<ApplicationPacket>();
    if(payload->getFirstFragment())
        creationTime_firstFragment = payload->getTag<CreationTimeTag>()->getCreationTime();


    totalreceivedMessagesLength = B(par("messageLength"));
    receivedMessageLength += B(pk->getByteLength());
    if(receivedMessageLength >= totalreceivedMessagesLength){
        auto payload2 = makeShared<ApplicationPacket>();
        payload2->setChunkLength(receivedMessageLength);
        Packet *p = pk;
        std::string pkName(pk->getName());
        std::size_t found = pkName.find("-frag-");
        if (found != std::string::npos)
        pkName.resize(found);
        p->setName(pkName.c_str());
        p->insertAtBack(payload2);

        EV_INFO << "Received packet: " << UdpSocket::getReceivedPacketInfo(p) << endl;
        emit(packetReceivedSignal, p);
        simtime_t latency = simTime() - creationTime_firstFragment;
        EV_INFO << "simTime = " << simTime() << "\n";
        EV_INFO << "first 2 = " << creationTime_firstFragment << "\n";
        EV_INFO << "Latencia = " << latency << "\n";
        latencyPackets.push_back(latency);

        numReceived++;
        totalreceivedMessagesLength = B(0);
        creationTime_firstFragment = 0;
        receivedMessageLength = B(0);
        //delete p;
        statsLatencyVector.record(latency);
        statsLatency.collect(latency);
    }
    delete pk;
    }

}

void MyUdpBasicApp::handleStartOperation(LifecycleOperation *operation)
{
    clocktime_t start = std::max(startTime, getClockTime());
    if ((stopTime < CLOCKTIME_ZERO) || (start < stopTime) || (start == stopTime && startTime == stopTime)) {
        selfMsg->setKind(START);
        scheduleClockEventAt(start, selfMsg);
    }
}

void MyUdpBasicApp::handleStopOperation(LifecycleOperation *operation)
{
    cancelEvent(selfMsg);
    socket.close();
    delayActiveOperationFinish(par("stopOperationTimeout"));
}

void MyUdpBasicApp::handleCrashOperation(LifecycleOperation *operation)
{
    cancelClockEvent(selfMsg);
    socket.destroy(); // TODO  in real operating systems, program crash detected by OS and OS closes sockets of crashed programs.
}

void MyUdpBasicApp::handleEndTxPeriod(){
    if(offset < messageLength)
        sendPacket();
    else{
        offset = B(0);
    }
}
} // namespace inet

