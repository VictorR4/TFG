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


import inet.common.INETDefs;
import inet.transportlayer.common.CrcMode;
import inet.transportlayer.contract.TransportHeaderBase;

cplusplus {{
#include "inet/common/INETUtils.h"
}}

namespace inet;

cplusplus {{
const B RDMA_HEADER_LENGTH = B(8);//Cambiado
}}

//
// Represents an Rdma header, to be used with the ~Rdma module.
//
class RdmaHeader extends TransportHeaderBase
{
    unsigned short srcPort;
    unsigned short destPort;
    chunkLength = RDMA_HEADER_LENGTH;//Cambiado
    B totalLengthField = B(-1);   // UDP header + payload in bytes
    //Cambiado
}

cplusplus(RdmaHeader) {{
  public:
    virtual unsigned int getSourcePort() const override { return getSrcPort(); }
    virtual void setSourcePort(unsigned int port) override { setSrcPort(port); }
    virtual unsigned int getDestinationPort() const override { return getDestPort(); }
    virtual void setDestinationPort(unsigned int port) override { setDestPort(port); }
}}

