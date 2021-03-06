/*
 * Rdma.h
 *
 *  Created on: Aug 10, 2021
 *      Author: vr4
 */

#ifndef INET_TRANSPORTLAYER_RDMA_RDMA_H_
#define INET_TRANSPORTLAYER_RDMA_RDMA_H_

#include <list>
#include <map>

#include "inet/common/Protocol.h"
#include "inet/common/lifecycle/ModuleOperations.h"
#include "inet/common/packet/Message.h"
#include "inet/common/packet/Packet.h"
#include "inet/common/packet/chunk/BytesChunk.h"
#include "inet/networklayer/contract/INetfilter.h"
#include "inet/transportlayer/base/TransportProtocolBase.h"
#include "inet/transportlayer/common/CrcMode_m.h"
#include "inet/transportlayer/common/TransportPseudoHeader_m.h"
#include "inet/transportlayer/contract/udp/UdpControlInfo.h"
#include <list>
#include <map>

#include "inet/common/Protocol.h"
#include "inet/common/lifecycle/ModuleOperations.h"
#include "inet/common/packet/Message.h"
#include "inet/common/packet/Packet.h"
#include "inet/common/packet/chunk/BytesChunk.h"
#include "inet/networklayer/contract/INetfilter.h"
#include "inet/transportlayer/base/TransportProtocolBase.h"
#include "inet/transportlayer/common/CrcMode_m.h"
#include "inet/transportlayer/common/TransportPseudoHeader_m.h"
#include "inet/transportlayer/contract/udp/UdpControlInfo.h"
#include "inet/clock/contract/ClockTime.h"


namespace inet {

class IInterfaceTable;
class Icmp;
class Icmpv6;
class RdmaHeader;
class NetworkInterface;

const bool DEFAULT_MULTICAST_LOOP = true;
const uint16_t RDMA_MAX_MESSAGE_SIZE = 4096; // bytes

/**
 * Implements the Rdma protocol: encapsulates/decapsulates user data into/from Rdma.
 *
 * More info in the NED file.
 */
class INET_API Rdma: public TransportProtocolBase
{
  public:
    class CrcInsertion : public NetfilterBase::HookBase {
      public:
        virtual Result datagramPreRoutingHook(Packet *packet) override { return ACCEPT; }
        virtual Result datagramForwardHook(Packet *packet) override { return ACCEPT; }
        virtual Result datagramPostRoutingHook(Packet *packet) override;
        virtual Result datagramLocalInHook(Packet *packet) override { return ACCEPT; }
        virtual Result datagramLocalOutHook(Packet *packet) override { return ACCEPT; }
    };

    enum PortRange {
        EPHEMERAL_PORTRANGE_START = 1024,
        EPHEMERAL_PORTRANGE_END   = 5000
    };



  protected:
    CrcMode crcMode = CRC_MODE_UNDEFINED;
    CrcInsertion crcInsertion;

    // other state vars
    ushort lastEphemeralPort = EPHEMERAL_PORTRANGE_START;
    IInterfaceTable *ift = nullptr;
    Icmp *icmp = nullptr;
    Icmpv6 *icmpv6 = nullptr;

    // statistics
    int numSent = 0;
    int numPassedUp = 0;
    int numDroppedWrongPort = 0;
    int numDroppedBadChecksum = 0;

    //Owns
    cMessage *endTxTimer = nullptr;
    int offset = 0;
    int headerLength;
    int payloadLength;
    int fragmentLength; // payload only (without header)
    int offsetBase;
    int noOfFragments = 0;

    std::string fragMsgName;
    L3Address srcAddr, destAddr;
    const Protocol *l3Protocol = nullptr;
    Ptr<RdmaHeader> rdmaHeader = nullptr;
    Packet *packet;

    cGate *lowerLayerOut = nullptr;
    cChannel *transmissionChannel = nullptr;
  protected:
    // utility: show current statistics above the icon
    virtual void refreshDisplay() const override;


    // ephemeral port
    virtual ushort getEphemeralPort();


    virtual void sendUp(Ptr<const RdmaHeader>& header, Packet *payload, ushort srcPort, ushort destPort);//, clocktime_t generationTime);
    virtual void processUndeliverablePacket(Packet *rdmaPacket);

    // process Rdma packets coming from Ethernet
    virtual void processRdmaPacket(Packet *rdmaPacket);

    // process packets from application
    virtual void handleUpperPacket(Packet *appData) override;

    // process packets from link layer
    virtual void handleLowerPacket(Packet *appData) override;

    virtual void handleMessageWhenUp(cMessage *msg) override;

    //Process an own message
    virtual void handleSelfMessage(cMessage *msg) override;
    virtual void handleEndTxPeriod();

    // create a blank Rdma packet; override to subclass RdmaHeader
    virtual RdmaHeader *createRdmaPacket();

    // ILifeCycle:
    virtual void handleStartOperation(LifecycleOperation *operation) override;
    virtual void handleStopOperation(LifecycleOperation *operation) override;
    virtual void handleCrashOperation(LifecycleOperation *operation) override;

  public:
    // crc
    static void insertCrc(const Protocol *networkProtocol, const L3Address& srcAddress, const L3Address& destAddress, const Ptr<RdmaHeader>& rdmaHeader, Packet *rdmaPayload);
    static bool verifyCrc(const Protocol *networkProtocol, const Ptr<const RdmaHeader>& rdmaHeader, Packet *packet);
    static uint16_t computeCrc(const Protocol *networkProtocol, const L3Address& srcAddress, const L3Address& destAddress, const Ptr<const RdmaHeader>& rdmaHeader, const Ptr<const Chunk>& rdmaData);

  public:
    Rdma();
    virtual ~Rdma();

    static bool isCorrectPacket(Packet *packet, const Ptr<const RdmaHeader>& rdmaHeader);

  protected:
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
};

} // namespace inet


#endif /* INET_TRANSPORTLAYER_RDMA_RDMA_H_ */
