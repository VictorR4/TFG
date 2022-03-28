//
// Copyright (C) 2020 OpenSim Ltd.
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

package inet.node.rdma.base;

import inet.common.MessageDispatcher;
//import inet.node.base.NetworkLayerNodeBase;
import inet.transportlayer.contract.ISctp;
import inet.transportlayer.contract.ITcp;
import inet.transportlayer.contract.IUdp;
import inet.transportlayer.contract.IRdma;
import ned.DatarateChannel;
import inet.node.ethernet.Eth40G;

module TransportLayerNodeBase extends NetworkLayerNodeBase
{
    parameters:
		bool hasRdma = default(firstAvailableOrEmpty("Rdma") != "");
        @figure[transportLayer](type=rectangle; pos=250,156; size=1000,130; fillColor=#ff0000; lineColor=#808080; cornerRadius=5; fillOpacity=0.1);
        @figure[transportLayer.title](type=text; pos=1245,161; anchor=ne; text="transport layer");
    
    types:
        channel cable extends DatarateChannel
        {
            double retardo @unit(us);
            datarate = 1Gbps;
            delay = this.retardo;
        }    
    submodules:

 		rdma: <default(firstAvailableOrEmpty("Rdma"))> like IRdma if hasRdma{
            parameters:
            @display("p=885.472,224.672");
        }
        tn: MessageDispatcher {
            parameters:
                @display("p=750,296;b=1000,5,,,,1");
        }

    connections allowunconnected:
        tn.out++ --> ipv4.transportIn if hasIpv4;
        tn.in++ <-- ipv4.transportOut if hasIpv4;

        tn.out++ --> ipv6.transportIn if hasIpv6;
        tn.in++ <-- ipv6.transportOut if hasIpv6;

        tn.out++ --> generic.transportIn if hasGn;
        tn.in++ <-- generic.transportOut if hasGn;

        tn.out++ --> nl.in++;
        tn.in++ <-- nl.out++;
        
        rdma.lowerLayerOut --> tn.in++ if hasRdma;
        rdma.lowerLayerIn <-- tn.out++ if hasRdma;
}

