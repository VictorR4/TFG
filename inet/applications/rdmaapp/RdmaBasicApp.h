/*
 * RdmaBasicApp.h
 *
 *  Created on: Aug 10, 2021
 *      Author: vr4
 */

#ifndef INET_APPLICATIONS_RDMAAPP_RDMABASICAPP_H_
#define INET_APPLICATIONS_RDMAAPP_RDMABASICAPP_H_

#include <vector>

#include "inet/applications/base/ApplicationBase.h"
#include "inet/common/clock/ClockUserModuleMixin.h"
#include "inet/transportlayer/contract/udp/UdpSocket.h"
#include "inet/applications/rdmaapp/fragBuff/RdmaFragBuf.h"
#include "inet/networklayer/ipv4/Ipv4FragBuf.h"
#include "inet/transportlayer/rdma/RdmaHeader_m.h"

namespace inet {

/**
 * RDMA application. See NED for more info.
 */
class INET_API RdmaBasicApp : public ClockUserModuleMixin<ApplicationBase>//, public UdpSocket::ICallback
{

  protected:
    enum SelfMsgKinds { START = 1, SEND, STOP };

    // parameters
    std::vector<L3Address> destAddresses;
    std::vector<std::string> destAddressStr;
    int localPort = -1, destPort = -1;
    clocktime_t startTime;
    clocktime_t stopTime;
    bool dontFragment = false;
    const char *packetName = nullptr;
    B messageLength = B(0);
    B receivedMessageLength = B(0);
    B totalLengthToReceive;

    // state
    ClockEvent *selfMsg = nullptr;

    // statistics
    int numSent = 0;
    int numReceived = 0;
    clocktime_t latency;
    cStdDev statsLatency;
    cOutVector statsLatencyVector;
    //double *latencyPackets;
    std::vector<simtime_t> latencyPackets;
    simtime_t meanLatency;
    int valoresValidos = 0;

    RdmaAppFragBuf fragbufRdma; // fragmentation reassembly buffer
    Ipv4FragBuf fragbufIpv4; // fragmentation reassembly buffer

    // statistics:
    static int counter; // counter for generating a global number for each packet
  protected:
    cGate *gateToRdma = nullptr;

  protected:
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void initialize(int stage) override;
    virtual void handleMessageWhenUp(cMessage *msg) override;
    virtual void finish() override;
    virtual void refreshDisplay() const override;

    // chooses random destination address
    virtual L3Address chooseDestAddr(); //Cambiado
    void setOutputGate(cGate *toRdma) { gateToRdma = toRdma; }//Cambiado
    virtual void sendToRdma(cMessage *msg);//Cambiado
    virtual void send(Packet *pk);//Cambiado
    void sendTo(Packet *pk, L3Address destAddr, int destPort);//Cambiado
    virtual void sendPacket();
    virtual void processPacket(Packet *msg);
    virtual void processStart();
    virtual void processSend();
    virtual void processStop();
    static std::string getReceivedPacketInfo(Packet *pk);
    virtual void handleStartOperation(LifecycleOperation *operation) override;
    virtual void handleStopOperation(LifecycleOperation *operation) override;
    virtual void handleCrashOperation(LifecycleOperation *operation) override;
    virtual void decapsulate(Packet *packet);

  public:
    RdmaBasicApp() {}
    ~RdmaBasicApp();
};

} // namespace inet




#endif /* INET_APPLICATIONS_RDMAAPP_RDMABASICAPP_H_ */
