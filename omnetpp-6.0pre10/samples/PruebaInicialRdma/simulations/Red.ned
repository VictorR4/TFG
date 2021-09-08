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
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package pruebainicialrdma.simulations;

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.rdma.RdmaHost;
import inet.node.ethernet.EthernetSwitch;
import inet.node.ethernet.EthernetHost;
import ned.DatarateChannel;

//
// TODO auto-generated type
//
network Red
{
    @display("bgb=526,307");
    types:
        channel cable extends DatarateChannel
        {
            datarate = 40Gbps;
            delay = 1us;
        }
    submodules:
        hA: RdmaHost {
            srcAddresses = 1;
            @display("p=108,38");
        }
        hB: RdmaHost {
            srcAddresses = 2;
            @display("p=288,38");
        }
        hC: RdmaHost {
            srcAddresses = 3;
            @display("p=108,265");
        }
        hD: RdmaHost {
            srcAddresses = 4;
            @display("p=288,265");
        }
        switch1: EthernetSwitch {
            @display("p=200,110");
            gates:
                ethg[3];
        }
        switch2: EthernetSwitch {
            @display("p=200,204");
            gates:
                ethg[3];
        }

        configurator: Ipv4NetworkConfigurator {
            @display("p=395,178");
        }
    connections:
        hA.ethg++ <--> cable <--> switch1.ethg[0];
        hB.ethg++ <--> cable <--> switch1.ethg[1];
        hC.ethg++ <--> cable <--> switch2.ethg[0];
        hD.ethg++ <--> cable <--> switch2.ethg[1];
        switch1.ethg[2] <--> cable <--> switch2.ethg[2];

}
