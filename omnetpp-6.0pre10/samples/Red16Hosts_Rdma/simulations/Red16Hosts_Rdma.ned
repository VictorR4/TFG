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

package red16hosts_rdma.simulations;

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.ethernet.Eth40G;
import inet.node.rdma.RdmaHost;
import inet.node.ethernet.EthernetSwitch;
import ned.DatarateChannel;
//
// TODO auto-generated type
//
network Red16Hosts_Rdma
{
    @display("bgb=1807.9113,973.93005");
    types:
        channel cable extends DatarateChannel
        {
            delay = 0.0000035s;
            datarate = 40Gbps;
        }
    submodules:
        configurator: Ipv4NetworkConfigurator {
            @display("p=1682.2428,294.17828;is=s");
        }
        H_0: RdmaHost {
            @display("p=100,80");
        }
        H_1: RdmaHost {
            @display("p=300,80");
        }
        H_2: RdmaHost {
            @display("p=500,80");
        }
        SW_1_1: EthernetSwitch {
            @display("p=411.27838,291.32217");
            gates:
                ethg[6];
        }
        H_3: RdmaHost {
            @display("p=700,80");
        }
        H_4: RdmaHost {
            @display("p=900,80");
        }
        H_5: RdmaHost {
            @display("p=1100,80");
        }
        SW_1_2: EthernetSwitch {
            @display("p=1188.1376,291.32217");
            gates:
                ethg[6];
        }
        H_6: RdmaHost {
            @display("p=1300,80");
        }
        H_7: RdmaHost {
            @display("p=1500,80");
        }
        H_8: RdmaHost {
            @display("p=100,800");
        }
        H_9: RdmaHost {
            @display("p=300,800");
        }
        H_10: RdmaHost {
            @display("p=500,800");
        }
        H_11: RdmaHost {
            @display("p=700,800");
        }
        SW_2_1: EthernetSwitch {
            @display("p=411.27838,636.9103");
            gates:
                ethg[6];
        }
        H_12: RdmaHost {
            @display("p=900,800");
        }
        H_13: RdmaHost {
            @display("p=1100,800");
        }
        H_14: RdmaHost {
            @display("p=1300,800");
        }
        SW_2_2: EthernetSwitch {
            @display("p=1188.1376,636.9103");
            gates:
                ethg[6];
        }
        H_15: RdmaHost {
            @display("p=1500,800");
        }
        SW_3_1: EthernetSwitch {
            @display("p=411.27838,451.26376");
            gates:
                ethg[4];
        }
        SW_3_2: EthernetSwitch {
            @display("p=1188.1376,451.26376");
            gates:
                ethg[4];
        }

    connections:
        H_0.ethg++ <--> Eth40G <--> SW_1_1.ethg[0];
        H_1.ethg++ <--> Eth40G <--> SW_1_1.ethg[1];
        H_2.ethg++ <--> Eth40G <--> SW_1_1.ethg[2];
        H_3.ethg++ <--> Eth40G <--> SW_1_1.ethg[3];
        H_4.ethg++ <--> Eth40G <--> SW_1_2.ethg[0];
        H_5.ethg++ <--> Eth40G <--> SW_1_2.ethg[1];
        H_6.ethg++ <--> Eth40G <--> SW_1_2.ethg[2];
        H_7.ethg++ <--> Eth40G <--> SW_1_2.ethg[3];
        H_8.ethg++ <--> Eth40G <--> SW_2_1.ethg[0];
        H_9.ethg++ <--> Eth40G <--> SW_2_1.ethg[1];
        H_10.ethg++ <--> Eth40G <--> SW_2_1.ethg[2];
        H_11.ethg++ <--> Eth40G <--> SW_2_1.ethg[3];
        H_12.ethg++ <--> Eth40G <--> SW_2_2.ethg[0];
        H_13.ethg++ <--> Eth40G <--> SW_2_2.ethg[1];
        H_14.ethg++ <--> Eth40G <--> SW_2_2.ethg[2];
        H_15.ethg++ <--> Eth40G <--> SW_2_2.ethg[3];
        SW_3_1.ethg[0] <--> Eth40G <--> SW_1_1.ethg[4];
        SW_3_1.ethg[1] <--> Eth40G <--> SW_1_2.ethg[4];
        SW_3_1.ethg[2] <--> Eth40G <--> SW_2_1.ethg[4];
        SW_3_1.ethg[3] <--> Eth40G <--> SW_2_2.ethg[4];
        SW_3_2.ethg[0] <--> Eth40G <--> SW_1_1.ethg[5];
        SW_3_2.ethg[1] <--> Eth40G <--> SW_1_2.ethg[5];
        SW_3_2.ethg[2] <--> Eth40G <--> SW_2_1.ethg[5];
        SW_3_2.ethg[3] <--> Eth40G <--> SW_2_2.ethg[5];

}
