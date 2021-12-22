/*
 * RdmaBasicApp.cc
 *
 *  Created on: Aug 10, 2021
 *      Author: vr4
 */

#include "inet/applications/rdmaapp/RdmaBasicApp.h"

#include "inet/applications/base/ApplicationPacket_m.h"
#include "inet/common/ModuleAccess.h"
#include "inet/common/TagBase_m.h"
#include "inet/common/TimeTag_m.h"
#include "inet/common/lifecycle/ModuleOperations.h"
#include "inet/common/packet/Packet.h"
#include "inet/networklayer/common/FragmentationTag_m.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/common/ProtocolTag_m.h"
#include "inet/networklayer/common/L3AddressTag_m.h"
#include "inet/transportlayer/common/L4PortTag_m.h"
#include "inet/linklayer/common/InterfaceTag_m.h"

namespace inet {

Define_Module(RdmaBasicApp);


RdmaBasicApp::~RdmaBasicApp()
{
    cancelAndDelete(selfMsg);
}

void RdmaBasicApp::initialize(int stage)
{
    ClockUserModuleMixin::initialize(stage);

    if (stage == INITSTAGE_LOCAL) {
        numSent = 0;
        numReceived = 0;
        WATCH(numSent);
        WATCH(numReceived);
        WATCH(latency);

        localPort = par("localPort");
        destPort = par("destPort");
        startTime = par("startTime");
        stopTime = par("stopTime");
        packetName = par("packetName");
        dontFragment = par("dontFragment");
        if (stopTime >= CLOCKTIME_ZERO && stopTime < startTime)
            throw cRuntimeError("Invalid startTime/stopTime parameters");
        selfMsg = new ClockEvent("sendTimer");
    }
}

void RdmaBasicApp::finish()
{
    recordScalar("packets sent", numSent);
    recordScalar("packets received", numReceived);
    recordScalar("latency", latency.dbl());
    recordScalar("meanLatency", latency.dbl()/numReceived);
    ApplicationBase::finish();
}

void RdmaBasicApp::handleMessageWhenUp(cMessage *msg)
{
    if (msg->isSelfMessage()) {
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
    else
        processPacket(check_and_cast<Packet *>(msg));
}


L3Address RdmaBasicApp::chooseDestAddr()
{
    int k = intrand(destAddresses.size());
    if (destAddresses[k].isUnspecified() || destAddresses[k].isLinkLocal()) {
        L3AddressResolver().tryResolve(destAddressStr[k].c_str(), destAddresses[k]);
    }
    return destAddresses[k];
}

void RdmaBasicApp::processStart()
{
    setOutputGate(gate("socketOut"));//Cambiado
//    const char *localAddress = par("localAddress");
    const char *destAddrs = par("destAddresses");
    cStringTokenizer tokenizer(destAddrs);
    const char *token;

    while ((token = tokenizer.nextToken()) != nullptr) {
        destAddressStr.push_back(token);
        L3Address result;
        L3AddressResolver().tryResolve(token, result);
        if (result.isUnspecified())
            EV_ERROR << "cannot resolve destination address: " << token << endl;
        destAddresses.push_back(result);
    }

    if (!destAddresses.empty()) {//Cambiado
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

//Completo
void RdmaBasicApp::processSend()
{
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

void RdmaBasicApp::sendToRdma(cMessage *msg)//Cambiado
{
    if (!gateToRdma)
           throw cRuntimeError("Rdma: setOutputGate() must be invoked");
       EV_DEBUG << "Sending to Rdma protocol" << EV_FIELD(msg) << EV_ENDL;
       auto& tags = check_and_cast<ITaggedObject *>(msg)->getTags();
       tags.addTagIfAbsent<DispatchProtocolReq>()->setProtocol(&Protocol::rdma);
       check_and_cast<cSimpleModule *>(gateToRdma->getOwnerModule())->send(msg, gateToRdma);
}

void RdmaBasicApp::sendTo(Packet *pk, L3Address destAddr, int destPort)
{
    pk->addTagIfAbsent<L4PortReq>()->setSrcPort(localPort);
    auto addressReq = pk->addTagIfAbsent<L3AddressReq>();
    addressReq->setDestAddress(destAddr);
    if (destPort != -1)
        pk->addTagIfAbsent<L4PortReq>()->setDestPort(destPort);
    sendToRdma(pk);
}

void RdmaBasicApp::send(Packet *pk){//Cambiado
    sendToRdma(pk);
}

void RdmaBasicApp::sendPacket()//Cambiado
{
    std::ostringstream str;
    str << packetName << "-" << numSent;
    Packet *packet = new Packet(str.str().c_str());
    if (dontFragment)
        packet->addTag<FragmentationReq>()->setDontFragment(true);
    const auto& payload = makeShared<ApplicationPacket>();
    payload->setChunkLength(B(par("messageLength")));
    payload->setSequenceNumber(numSent);
    payload->addTag<CreationTimeTag>()->setCreationTime(simTime());
    packet->insertAtBack(payload);
    //packet->addTagIfAbsent<CreationTimeTag>()->setCreationTime(simTime());//Cambiado

    L3Address destAddr = chooseDestAddr();
    emit(packetSentSignal, packet);
    sendTo(packet, destAddr, destPort);
    numSent++;
}


void RdmaBasicApp::processStop()
{
    //socket.close();
}



void RdmaBasicApp::refreshDisplay() const
{
    ApplicationBase::refreshDisplay();

    char buf[100];
    sprintf(buf, "rcvd: %d pks\nsent: %d pks\n latency: %f s", numReceived, numSent, latency.dbl());
    getDisplayString().setTagArg("t", 0, buf);
}

void RdmaBasicApp::processPacket(Packet *pk)
{
    emit(packetReceivedSignal, pk);
    //clocktime_t generationTime = payload->getGenerationTime();
    clocktime_t generationTime = pk->getTag<CreationTimeTag>()->getCreationTime();
    //EV_INFO << "Received packet: " << getReceivedPacketInfo(pk) << endl;
    delete pk;
    latency += (simTime() - generationTime);
    numReceived++;
}

std::string RdmaBasicApp::getReceivedPacketInfo(Packet *pk)
{
    auto l3Addresses = pk->getTag<L3AddressInd>();
    auto ports = pk->getTag<L4PortInd>();
    L3Address srcAddr = l3Addresses->getSrcAddress();
    L3Address destAddr = l3Addresses->getDestAddress();
    int srcPort = ports->getSrcPort();
    int destPort = ports->getDestPort();
    int interfaceID = pk->getTag<InterfaceInd>()->getInterfaceId();

    std::stringstream os;
    os << pk << " (" << pk->getByteLength() << " bytes) ";
    os << srcAddr << ":" << srcPort << " --> " << destAddr << ":" << destPort;
    os << " on ifID=" << interfaceID;
    return os.str();
}

void RdmaBasicApp::handleStartOperation(LifecycleOperation *operation)
{
    clocktime_t start = std::max(startTime, getClockTime());
    if ((stopTime < CLOCKTIME_ZERO) || (start < stopTime) || (start == stopTime && startTime == stopTime)) {
        selfMsg->setKind(START);
        scheduleClockEventAt(start, selfMsg);
    }
}

void RdmaBasicApp::handleStopOperation(LifecycleOperation *operation)
{
    cancelEvent(selfMsg);
    //socket.close();
    delayActiveOperationFinish(par("stopOperationTimeout"));
}

void RdmaBasicApp::handleCrashOperation(LifecycleOperation *operation)
{
    cancelClockEvent(selfMsg);
    //socket.destroy(); // TODO  in real operating systems, program crash detected by OS and OS closes sockets of crashed programs.
}

} // namespace inet


