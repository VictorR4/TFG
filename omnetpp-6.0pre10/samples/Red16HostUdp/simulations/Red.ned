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

package red16hostudp.simulations;

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.inet.StandardHost;
import inet.node.ethernet.EthernetSwitch;
import inet.node.ethernet.EthernetHost;
import ned.DatarateChannel;
//
// TODO auto-generated type
//
network Red
{
    @display("bgb=1035,510");
    types:
        channel cable extends DatarateChannel
        {
            datarate = 40Gbps;
            delay = 1us;
        }
    submodules:
        configurator: Ipv4NetworkConfigurator {
            @display("p=395,178");
        }
        H_0: StandardHost {
            @display("p=50,44");
        }
        H_1: StandardHost {
            @display("p=155,36");
        }
        H_2: StandardHost {
            @display("p=250,36");
        }
        H_3: StandardHost {
            @display("p=354,36");
        }
        SW_1_1: EthernetSwitch {
            @display("p=185,186");
            gates:
                ethg[6];
        }
        H_4: StandardHost {
            @display("p=511,36");
        }
        H_5: StandardHost {
            @display("p=594,44");
        }
        H_6: StandardHost {
            @display("p=719,36");
        }
        H_7: StandardHost {
            @display("p=831,50");
        }
        SW_1_2: EthernetSwitch {
            @display("p=600,175");
            gates:
                ethg[6];
        }
        H_8: StandardHost {
            @display("p=43,466");
        }
        H_9: StandardHost {
            @display("p=116,466");
        }
        H_10: StandardHost {
            @display("p=185,466");
        }
        H_11: StandardHost {
            @display("p=239,466");
        }
        SW_2_1: EthernetSwitch {
            @display("p=194,378");
            gates:
                ethg[6];
        }
        H_12: StandardHost {
            @display("p=464,466");
        }
        H_13: StandardHost {
            @display("p=561,466");
        }
        H_14: StandardHost {
            @display("p=657,466");
        }
        H_15: StandardHost {
            @display("p=767,466");
        }
        SW_2_2: EthernetSwitch {
            @display("p=600,363");
            gates:
                ethg[6];
        }
        SW_3_1: EthernetSwitch {
            @display("p=194,281");
            gates:
                ethg[4];
        }
        SW_3_2: EthernetSwitch {
            @display("p=618,281");
            gates:
                ethg[4];
        }

    connections:
        H_0.ethg++ <--> cable <--> SW_1_1.ethg[0];
        H_1.ethg++ <--> cable <--> SW_1_1.ethg[1];
        H_2.ethg++ <--> cable <--> SW_1_1.ethg[2];
        H_3.ethg++ <--> cable <--> SW_1_1.ethg[3];
        H_4.ethg++ <--> cable <--> SW_1_2.ethg[0];
        H_5.ethg++ <--> cable <--> SW_1_2.ethg[1];
        H_6.ethg++ <--> cable <--> SW_1_2.ethg[2];
        H_7.ethg++ <--> cable <--> SW_1_2.ethg[3];
        H_8.ethg++ <--> cable <--> SW_2_1.ethg[0];
        H_9.ethg++ <--> cable <--> SW_2_1.ethg[1];
        H_10.ethg++ <--> cable <--> SW_2_1.ethg[2];
        H_11.ethg++ <--> cable <--> SW_2_1.ethg[3];
        H_12.ethg++ <--> cable <--> SW_2_2.ethg[0];
        H_13.ethg++ <--> cable <--> SW_2_2.ethg[1];
        H_14.ethg++ <--> cable <--> SW_2_2.ethg[2];
        H_15.ethg++ <--> cable <--> SW_2_2.ethg[3];
        SW_3_1.ethg[0] <--> cable <--> SW_1_1.ethg[4];
        SW_3_1.ethg[1] <--> cable <--> SW_1_2.ethg[4];
        SW_3_1.ethg[2] <--> cable <--> SW_2_1.ethg[4];
        SW_3_1.ethg[3] <--> cable <--> SW_2_2.ethg[4];
        SW_3_2.ethg[0] <--> cable <--> SW_1_1.ethg[5];
        SW_3_2.ethg[1] <--> cable <--> SW_1_2.ethg[5];
        SW_3_2.ethg[2] <--> cable <--> SW_2_1.ethg[5];
        SW_3_2.ethg[3] <--> cable <--> SW_2_2.ethg[5];
}
