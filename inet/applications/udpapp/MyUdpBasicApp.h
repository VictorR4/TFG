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

#ifndef __INET_MYUDPBASICAPP_H
#define __INET_MYUDPBASICAPP_H

#include <vector>

#include "inet/applications/base/ApplicationBase.h"
#include "inet/common/clock/ClockUserModuleMixin.h"
#include "inet/transportlayer/contract/udp/UdpSocket.h"
#include "inet/applications/udpapp/fragBuff/UdpFragBuf.h"

namespace inet {

/**
 * UDP application. See NED for more info.
 */
class INET_API MyUdpBasicApp : public ClockUserModuleMixin<ApplicationBase>, public UdpSocket::ICallback
{
  protected:
    enum SelfMsgKinds { START = 1, SEND, STOP };

    // parameters
    int packetsToSend;
    std::vector<L3Address> destAddresses;
    std::vector<std::string> destAddressStr;
    int localPort = -1, destPort = -1;
    clocktime_t startTime;
    clocktime_t stopTime;
    bool dontFragment = false;
    const char *packetName = nullptr;
    B messageLength = B(0);
    int id;
    B fragmentSize;
    B offset = B(0);
    std::string fragMsgName;
    simtime_t creationTime;

    simtime_t creationTime_firstFragment;
    // state
    UdpSocket socket;
    ClockEvent *selfMsg = nullptr;

    // statistics
    int numSent = 0;
    int numReceived = 0;
    std::vector<simtime_t> latencyPackets;
    cStdDev statsLatency;
    cOutVector statsLatencyVector;
    int valoresValidos = 0;

    L3Address destAddr;
    clocktime_t latency;
    cMessage *endTxTimer = nullptr;
    cGate *lowerLayerOut = nullptr;
    cChannel *transmissionChannel = nullptr;
    cPacketQueue *queue = nullptr;
    B receivedMessageLength = B(0);
    B totalreceivedMessagesLength;

    bool isGlobalArp;
    UdpAppFragBuf fragbuf; // fragmentation reassembly buffer
  protected:
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void initialize(int stage) override;
    virtual void handleMessageWhenUp(cMessage *msg) override;
    virtual void finish() override;
    virtual void refreshDisplay() const override;

    // chooses random destination address
    virtual L3Address chooseDestAddr();
    virtual void sendPacket();
    virtual void processPacket(Packet *msg);
    virtual void setSocketOptions();

    virtual void processStart();
    virtual void processSend();
    virtual void processStop();

    virtual void handleStartOperation(LifecycleOperation *operation) override;
    virtual void handleStopOperation(LifecycleOperation *operation) override;
    virtual void handleCrashOperation(LifecycleOperation *operation) override;

    virtual void socketDataArrived(UdpSocket *socket, Packet *packet) override;
    virtual void socketErrorArrived(UdpSocket *socket, Indication *indication) override;
    virtual void socketClosed(UdpSocket *socket) override;


    // process an own message
    virtual void handleEndTxPeriod();

  public:
    MyUdpBasicApp() {}
    ~MyUdpBasicApp();
};

} // namespace inet

#endif

