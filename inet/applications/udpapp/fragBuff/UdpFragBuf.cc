//
// Copyright (C) 2004 OpenSim Ltd.
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

#include "inet/applications/udpapp/fragBuff/UdpFragBuf.h"

#include <stdlib.h>
#include <string.h>

#include "inet/networklayer/ipv4/Icmp.h"
//#include "inet/networklayer/ipv4/Ipv4Header_m.h"
//#include "inet/transportlayer/udp/UdpHeader_m.h"
#include "inet/applications/base/ApplicationPacket_m.h"

namespace inet {

UdpAppFragBuf::UdpAppFragBuf()
{
}

UdpAppFragBuf::~UdpAppFragBuf()
{
    flush();
}

void UdpAppFragBuf::flush()
{
    for (auto i = bufs.begin(); i != bufs.end(); ++i)
        delete i->second.packet;
    bufs.clear();
}

Packet *UdpAppFragBuf::addFragment(Packet *packet, simtime_t now)
{
    const auto& udpHeader = packet->peekAtFront<ApplicationPacket>();
    //auto udpHeader = packet->popAtFront<UdpHeader>(b(-1), Chunk::PF_ALLOW_INCORRECT);
    // find datagram buffer
    Key key;
    key.id = udpHeader->getId();

    auto i = bufs.find(key);
    DatagramBuffer *curBuf = nullptr;

    if (i == bufs.end()) {
        // this is the first fragment of that datagram, create reassembly buffer for it
        curBuf = &bufs[key];
        i = bufs.find(key);
    }
    else {
        // use existing buffer
        curBuf = &(i->second);
    }

    // add fragment into reassembly buffer
    ASSERT(packet->getByteLength() > 0);
    B bytes = B(packet->getByteLength());

    curBuf->buf.replace(B(udpHeader->getFragmentOffset()), packet->peekDataAt(B(0), bytes));
    if (!udpHeader->getMoreFragments()) {
        curBuf->buf.setExpectedLength(B(udpHeader->getFragmentOffset()) + bytes);
    }
    if (udpHeader->getFragmentOffset() == 0 || curBuf->packet == nullptr) {
        delete curBuf->packet;
        curBuf->packet = packet;
    }
    else {
        delete packet;
    }

    // do we have the complete datagram?
    if (curBuf->buf.isComplete()) {
        // datagram complete: deallocate buffer and return complete datagram
        std::string pkName(curBuf->packet->getName());
        std::size_t found = pkName.find("-frag-");
        if (found != std::string::npos)
            pkName.resize(found);
        auto hdr = Ptr<ApplicationPacket>(curBuf->packet->peekAtFront<ApplicationPacket>()->dup());
        Packet *pk = curBuf->packet;
        pk->setName(pkName.c_str());
        pk->removeAll();
        const auto& payload = curBuf->buf.getReassembledData();
        hdr->setTotalLengthField(payload->getChunkLength());
        hdr->setFragmentOffset(0);
        hdr->setMoreFragments(false);
        pk->insertAtFront(hdr);
        pk->insertAtBack(payload);
        bufs.erase(i);
        return pk;
    }
    else {
        // there are still missing fragments
        curBuf->lastupdate = now;
        return nullptr;
    }
}



} // namespace inet

