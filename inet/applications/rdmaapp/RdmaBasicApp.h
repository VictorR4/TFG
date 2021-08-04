/*
 * RdmaBasicApp.h
 *
 *  Created on: Aug 2, 2021
 *      Author: usuario
 */

#ifndef INET_APPLICATIONS_RDMAAPP_RDMABASICAPP_H_
#define INET_APPLICATIONS_RDMAAPP_RDMABASICAPP_H_

#include <vector>

#include "inet/applications/base/ApplicationBase.h"
#include "inet/common/clock/ClockUserModuleMixin.h"
#include "inet/transportlayer/contract/udp/UdpSocket.h"

namespace inet {

/**
 * RDMA application. See NED for more info.
 */
class INET_API RdmaBasicApp : public ClockUserModuleMixin<ApplicationBase>//, public UdpSocket::ICallback
{
  protected:
    enum SelfMsgKinds { START = 1, SEND, STOP };

    // parameters
    int destAddress;//Cambiado
    std::vector<std::string> destAddressStr;
    int localPort = -1, destPort = -1;    //Cambiado
    clocktime_t startTime;
    clocktime_t stopTime;
    bool dontFragment = false;
    const char *packetName = nullptr;

    // state
    ClockEvent *selfMsg = nullptr;

    // statistics
    int numSent = 0;
    int numReceived = 0;

    // statistics:
    static int counter; // counter for generating a global number for each packet

  protected:
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void initialize(int stage) override;
    virtual void handleMessageWhenUp(cMessage *msg) override;
    virtual void finish() override;
    virtual void refreshDisplay() const override;

    // chooses random destination address
    //virtual L3Address chooseDestAddr(); //Cambiado
    virtual void sendPacket();
    virtual void processPacket(Packet *msg);
    virtual void processStart();
    virtual void processSend();
    virtual void processStop();

    virtual void handleStartOperation(LifecycleOperation *operation) override;
    virtual void handleStopOperation(LifecycleOperation *operation) override;
    virtual void handleCrashOperation(LifecycleOperation *operation) override;

  public:
    RdmaBasicApp() {}
    ~RdmaBasicApp();
};

} // namespace inet




#endif /* INET_APPLICATIONS_RDMAAPP_RDMABASICAPP_H_ */
