/*
 * RdmaBasicApp.cc
 *
 *  Created on: Aug 2, 2021
 *      Author: usuario
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

namespace inet {

Define_Module(RdmaBasicApp);

int RdmaBasicApp::counter;

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

        localPort = par("localPort"); //Cambiado
        destPort = par("destPort");   //Cambiado
        startTime = par("startTime");
        stopTime = par("stopTime");
        packetName = par("packetName");
        dontFragment = par("dontFragment");
        if (stopTime >= CLOCKTIME_ZERO && stopTime < startTime)
            throw cRuntimeError("Invalid startTime/stopTime parameters");
        selfMsg = new ClockEvent("sendTimer");
        destAddress = par("destAddress");//Cambiado
    }
}

void RdmaBasicApp::finish()
{
    recordScalar("packets sent", numSent);
    recordScalar("packets received", numReceived);
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
    /*else
        socket.processMessage(msg);*/
}

void RdmaBasicApp::processStart()
{
    //const char *localAddress = par("localAddress");
    setOutputGate(gate("socketOut"));//Cambiado
    const char *destAddrs = par("destAddresses");
    cStringTokenizer tokenizer(destAddrs);
    const char *token;

    while ((token = tokenizer.nextToken()) != nullptr) {
        destAddressStr.push_back(token);
        L3Address result;
        L3AddressResolver().tryResolve(token, result);
        if (result.isUnspecified())
            EV_ERROR << "cannot resolve destination address: " << token << endl;
        //destAddresses.push_back(result);
    }

    if (destAddress != 0) {
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

void RdmaBasicApp::send(Packet *pk){//Cambiado
    sendToRdma(pk);
}

void RdmaBasicApp::sendPacket()//Cambiado
{
    char msgName[32];
    sprintf(msgName, "RdmaBasicAppData-%d", numSent);
    Packet *packet = new Packet(msgName);
    if (dontFragment)
        packet->addTag<FragmentationReq>()->setDontFragment(true);
    const auto& payload = makeShared<ApplicationPacket>();
    payload->setChunkLength(B(par("messageLength")));
    payload->setSequenceNumber(numSent);
    payload->addTag<CreationTimeTag>()->setCreationTime(simTime());
    packet->insertAtBack(payload);
    emit(packetSentSignal, packet);
    //socket.sendTo(packet, destAddr, destPort);
    send(packet);
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
    sprintf(buf, "rcvd: %d pks\nsent: %d pks", numReceived, numSent);
    getDisplayString().setTagArg("t", 0, buf);
}

void RdmaBasicApp::processPacket(Packet *pk)
{
    emit(packetReceivedSignal, pk);
    EV_INFO << "Received packet: " << receive() << endl;
    delete pk;
    numReceived++;
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




