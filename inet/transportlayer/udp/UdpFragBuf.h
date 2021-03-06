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

#ifndef __INET_UDPFRAGBUF_H
#define __INET_UDPFRAGBUF_H

#include <map>

#include "inet/common/packet/Packet.h"
#include "inet/common/packet/ReassemblyBuffer.h"
#include "inet/networklayer/contract/ipv4/Ipv4Address.h"

namespace inet {

class Icmp;
class Ipv4Header;
class UdpHeader;

/**
 * Reassembly buffer for fragmented Ipv4 datagrams.
 */
class INET_API UdpFragBuf
{
  protected:
    //
    // Key for finding the reassembly buffer for a datagram.
    //
    struct Key {
        //ushort id = static_cast<ushort>(-1);
        uint16_t id = -1;
        int localPort = -1;
        int remotePort = -1;

        inline bool operator<(const Key& b) const
        {
            return (id != b.id) ? (id < b.id) : (localPort != b.localPort) ? (localPort < b.localPort) : (remotePort < b.remotePort);
        }
    };

    //
    // Reassembly buffer for the datagram
    //
    struct DatagramBuffer {
        ReassemblyBuffer buf; // reassembly buffer
        Packet *packet = nullptr; // the packet
        simtime_t lastupdate; // last time a new fragment arrived
    };

    // we use std::map for fast lookup by datagram Id
    typedef std::map<Key, DatagramBuffer> Buffers;

    // the reassembly buffers
    Buffers bufs;

  public:
    /**
     * Ctor.
     */
    UdpFragBuf();

    /**
     * Dtor.
     */
    ~UdpFragBuf();

    /**
     * Takes a fragment and inserts it into the reassembly buffer.
     * If this fragment completes a datagram, the full reassembled
     * datagram is returned, otherwise nullptr.
     */
    Packet *addFragment(Packet *packet, simtime_t now);

    /**
     * Throws out all fragments which are incomplete and their
     * last update (last fragment arrival) was before "lastupdate",
     * and sends ICMP TIME EXCEEDED message about them.
     *
     * Timeout should be between 60 seconds and 120 seconds (RFC1122).
     * This method should be called more frequently, maybe every
     * 10..30 seconds or so.
     */
    void purgeStaleFragments(Icmp *icmpModule, simtime_t lastupdate);

    /**
     * Clear all state.
     */
    void flush();
};

} // namespace inet

#endif

