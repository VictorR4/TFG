//
// Copyright (C) 2013 OpenSim Ltd.
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

#include "inet/linklayer/loopback/Loopback.h"

#include <stdio.h>
#include <string.h>

#include "inet/common/INETUtils.h"
#include "inet/common/ModuleAccess.h"
#include "inet/common/ProtocolTag_m.h"
#include "inet/common/Simsignals.h"
#include "inet/common/packet/Packet.h"
#include "inet/linklayer/common/InterfaceTag_m.h"
#include "inet/networklayer/contract/IInterfaceTable.h"

namespace inet {

Define_Module(Loopback);

Loopback::~Loopback()
{
}

void Loopback::initialize(int stage)
{
    MacProtocolBase::initialize(stage);
    if (stage == INITSTAGE_LOCAL) {
        lowerLayerInGateId = -1;
        lowerLayerOutGateId = -1;
        numSent = numRcvdOK = 0;
        WATCH(numSent);
        WATCH(numRcvdOK);
    }
}

void Loopback::configureNetworkInterface()
{
    // generate a link-layer address to be used as interface token for IPv6
//    InterfaceToken token(0, getSimulation()->getUniqueNumber(), 64);
//    ie->setInterfaceToken(token);

    // capabilities
    networkInterface->setMtu(par("mtu"));
    networkInterface->setLoopback(true);
}

void Loopback::handleUpperPacket(Packet *packet)
{
    EV << "Received " << packet << " for transmission\n";
    ASSERT(packet->hasBitError() == false);

    // pass up payload
    numRcvdOK++;
    numSent++;
    auto protocol = packet->getTag<PacketProtocolTag>()->getProtocol();
    if(protocol == &Protocol::rdma){
        packet->clearTags();
        packet->addTag<DispatchProtocolReq>()->setProtocol(protocol);
        packet->addTag<PacketProtocolTag>()->setProtocol(protocol);
        packet->addTag<InterfaceInd>()->setInterfaceId(networkInterface->getInterfaceId());
        emit(packetSentToUpperSignal, packet);
        send(packet,"appLayerOut");
    }else{
        packet->clearTags();
        packet->addTag<DispatchProtocolReq>()->setProtocol(protocol);
        packet->addTag<PacketProtocolTag>()->setProtocol(protocol);
        packet->addTag<InterfaceInd>()->setInterfaceId(networkInterface->getInterfaceId());
        emit(packetSentToUpperSignal, packet);
        send(packet, upperLayerOutGateId);
    }

}

void Loopback::refreshDisplay() const
{
    MacProtocolBase::refreshDisplay();

    /* TODO find solution for displaying IPv4 address without dependence on IPv4 or IPv6
            Ipv4Address addr = networkInterface->getProtocolData<Ipv4InterfaceData>()->getIPAddress();
            sprintf(buf, "%s / %s\nrcv:%ld snt:%ld", addr.isUnspecified()?"-":addr.str().c_str(), datarateText, numRcvdOK, numSent);
     */
    char buf[80];
    sprintf(buf, "rcv:%ld snt:%ld", numRcvdOK, numSent);

    getDisplayString().setTagArg("t", 0, buf);
}

} // namespace inet

