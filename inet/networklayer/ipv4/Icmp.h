//
// Copyright (C) 2000 Institut fuer Telematik, Universitaet Karlsruhe
// Copyright (C) 2004 OpenSim Ltd.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#ifndef __INET_ICMP_H
#define __INET_ICMP_H

// Cleanup and rewrite: Andras Varga, 2004

#include "inet/common/IProtocolRegistrationListener.h"
#include "inet/common/packet/Packet.h"
#include "inet/networklayer/ipv4/IIpv4RoutingTable.h"
#include "inet/networklayer/ipv4/IcmpHeader.h"
#include "inet/transportlayer/common/CrcMode_m.h"

namespace inet {

class Ipv4Header;

/**
 * Icmp module.
 */
class INET_API Icmp : public cSimpleModule, public DefaultProtocolRegistrationListener
{
  protected:
    std::set<int> transportProtocols; // where to send up packets
    CrcMode crcMode = CRC_MODE_UNDEFINED;
    B quoteLength;
    IIpv4RoutingTable *rt = nullptr;
    IInterfaceTable *ift = nullptr;
    static long ctr;

  protected:
    virtual void processIcmpMessage(Packet *);
    virtual void errorOut(Packet *);
    virtual void processEchoRequest(Packet *);
    virtual void sendToIP(Packet *, const Ipv4Address& dest);
    virtual void sendToIP(Packet *msg);
    virtual bool possiblyLocalBroadcast(const Ipv4Address& addr, int interfaceId);
    virtual void handleRegisterService(const Protocol& protocol, cGate *gate, ServicePrimitive servicePrimitive) override;
    virtual void handleRegisterProtocol(const Protocol& protocol, cGate *gate, ServicePrimitive servicePrimitive) override;

  public:
    /**
     * This method can be called from other modules to send an ICMP error packet
     * in response to a received bogus packet. It will not send ICMP error in response
     * to broadcast or multicast packets -- in that case it will simply delete the packet.
     * KLUDGE if inputInterfaceId cannot be determined, pass in -1.
     */
    virtual void sendErrorMessage(Packet *packet, int inputInterfaceId, IcmpType type, IcmpCode code);
    virtual void sendPtbMessage(Packet *packet, int mtu);
    static void insertCrc(CrcMode crcMode, const Ptr<IcmpHeader>& icmpHeader, Packet *payload);
    void insertCrc(const Ptr<IcmpHeader>& icmpHeader, Packet *payload) { insertCrc(crcMode, icmpHeader, payload); }
    bool verifyCrc(const Packet *packet);

  protected:
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void initialize(int stage) override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void handleParameterChange(const char *name) override;
    virtual void parseQuoteLengthParameter();
    virtual bool maySendErrorMessage(Packet *packet, int inputInterfaceId);
    virtual void sendOrProcessIcmpPacket(Packet *packet, Ipv4Address origSrcAddr);
};

} // namespace inet

#endif

