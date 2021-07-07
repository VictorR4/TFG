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

package red8;

import inet.linklayer.configurator.L2NetworkConfigurator;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.ethernet.EthernetHost;
import inet.node.ethernet.EthernetSwitch;
import inet.node.inet.StandardHost;
import ned.DatarateChannel;


//
// TODO auto-generated type
//
network Red
{
    @display("bgb=615,381");

    types:
        channel cable extends DatarateChannel
        {
            datarate = 10Mbps;
            delay = 0.1us;
        }

    submodules:
        host1: StandardHost {
            @display("p=36,31");
        }
        host2: StandardHost {
            @display("p=168,31");
        }
        host3: StandardHost {
            @display("p=421,31");
        }
        host4: StandardHost {
            @display("p=553,31");
        }
        host5: StandardHost {
            @display("p=36,345");
        }
        host6: StandardHost {
            @display("p=168,345");
        }
        host7: StandardHost {
            @display("p=421,345");
        }
        host8: StandardHost {
            @display("p=553,345");
        }
        switch1: EthernetSwitch {
            @display("p=84,121");
            gates:
                ethg[3];
        }
        switch2: EthernetSwitch {
            @display("p=496,121");
            gates:
                ethg[3];
        }
        switch3: EthernetSwitch {
            @display("p=84,267");
            gates:
                ethg[3];
        }
        switch4: EthernetSwitch {
            @display("p=496,267");
            gates:
                ethg[3];
        }
        switch5: EthernetSwitch {
            @display("p=301,199");
            gates:
                ethg[4];
        }


        configurator: Ipv4NetworkConfigurator {
            @display("p=290,334");
        }
    connections:
        host1.ethg++ <--> cable <--> switch1.ethg[0];
        host2.ethg++ <--> cable <--> switch1.ethg[1];
        host3.ethg++ <--> cable <--> switch2.ethg[0];
        host4.ethg++ <--> cable <--> switch2.ethg[1];
        host5.ethg++ <--> cable <--> switch3.ethg[0];
        host6.ethg++ <--> cable <--> switch3.ethg[1];
        host7.ethg++ <--> cable <--> switch4.ethg[0];
        host8.ethg++ <--> cable <--> switch4.ethg[1];
        switch1.ethg[2] <--> cable <--> switch5.ethg[0];
        switch2.ethg[2] <--> cable <--> switch5.ethg[1];
        switch3.ethg[2] <--> cable <--> switch5.ethg[2];
        switch4.ethg[2] <--> cable <--> switch5.ethg[3];
}
