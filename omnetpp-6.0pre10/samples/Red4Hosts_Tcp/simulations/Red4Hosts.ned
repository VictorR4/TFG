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

package red4hosts_udp.simulations;

//
// TODO auto-generated type
//
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.rdma.RdmaHost;
import inet.node.ethernet.EthernetSwitch;
import inet.node.inet.StandardHost;
import ned.DatarateChannel;
import inet.node.ethernet.*;


//
// TODO auto-generated type
//
network Red4Hosts
{
    @display("bgb=526,307");
    submodules:
        H_0: StandardHost {
            @display("p=108,38");
        }
        H_1: StandardHost {
            @display("p=288,38");
        }
        H_2: StandardHost {
            @display("p=108,265");
        }
        H_3: StandardHost {
            @display("p=288,265");
        }
        SW_1_1: EthernetSwitch {
            @display("p=200,110");
            gates:
                ethg[3];
        }
        SW_2_1: EthernetSwitch {
            @display("p=200,204");
            gates:
                ethg[3];
        }

        configurator: Ipv4NetworkConfigurator {
            @display("p=395,178");
        }
    connections:
        H_0.ethg++ <--> Eth40G <--> SW_1_1.ethg[0];
        H_1.ethg++ <--> Eth40G <--> SW_1_1.ethg[1];
        H_2.ethg++ <--> Eth40G <--> SW_2_1.ethg[0];
        H_3.ethg++ <--> Eth40G <--> SW_2_1.ethg[1];
        SW_1_1.ethg[2] <--> Eth40G <--> SW_2_1.ethg[2];

}

