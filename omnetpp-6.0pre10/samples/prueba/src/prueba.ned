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

package prueba;



import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.inet.StandardHost;
import inet.node.ethernet.EthernetSwitch;
import ned.DatarateChannel;

network Prueba
{
    @display("bgb=1357.8864,551.8763");
    types:
        channel C extends DatarateChannel
        {
            delay = 0.1us;
            datarate = 10Mbps;
        }
    submodules:
        host1: StandardHost {
            @display("p=75.1875,34.58625");
        }
        host2: StandardHost {
            @display("p=172.93126,34.58625");
        }
        host3: StandardHost {
            @display("p=281.20126,34.58625");
        }
        host4: StandardHost {
            @display("p=381.9525,34.58625");
        }
        host5: StandardHost {
            @display("p=735.3338,34.58625");
        }
        host6: StandardHost {
            @display("p=843.60376,34.58625");
        }
        host7: StandardHost {
            @display("p=956.385,34.58625");
        }
        host8: StandardHost {
            @display("p=1084.2037,34.58625");
        }
        host9: StandardHost {
            @display("p=75.1875,479.69626");
        }
        host10: StandardHost {
            @display("p=172.93126,472.17752");
        }
        host11: StandardHost {
            @display("p=281.20126,472.17752");
        }
        host12: StandardHost {
            @display("p=381.9525,472.17752");
        }
        host13: StandardHost {
            @display("p=735.3338,479.69626");
        }
        host14: StandardHost {
            @display("p=843.60376,479.69626");
        }
        host15: StandardHost {
            @display("p=978.9413,479.69626");
        }
        host16: StandardHost {
            @display("p=1082.7001,479.69626");
        }
        switch1: EthernetSwitch {
            @display("p=221.05125,162.405");
            gates:
                ethg[6];
        }
        switch2: EthernetSwitch {
            @display("p=221.05125,366.915");
            gates:
                ethg[6];
        }
        switch3: EthernetSwitch {
            @display("p=920.29504,160.90126");
            gates:
                ethg[6];
        }
        switch4: EthernetSwitch {
            @display("p=920.29504,366.915");
            gates:
                ethg[6];
        }
        switch5: EthernetSwitch {
            @display("p=221.05125,266.16376");
            gates:
                ethg[4];
        }
        switch6: EthernetSwitch {
            @display("p=920.29504,266.16376");
            gates:
                ethg[4];
        }
        configurator: Ipv4NetworkConfigurator {
            @display("p=75.1875,212.02876;is=s");
        }

    connections:
        switch1.ethg[0] <--> C <--> host1.ethg++;
        switch1.ethg[1] <--> C <--> host2.ethg++;
        switch1.ethg[2] <--> C <--> host3.ethg++;
        switch1.ethg[3] <--> C <--> host4.ethg++;
        switch3.ethg[0] <--> C <--> host5.ethg++;
        switch3.ethg[1] <--> C <--> host6.ethg++;
        switch3.ethg[2] <--> C <--> host7.ethg++;
        switch3.ethg[3] <--> C <--> host8.ethg++;
        switch2.ethg[0] <--> C <--> host9.ethg++;
        switch2.ethg[1] <--> C <--> host10.ethg++;
        switch2.ethg[2] <--> C <--> host11.ethg++;
        switch2.ethg[3] <--> C <--> host12.ethg++;
        switch4.ethg[0] <--> C <--> host13.ethg++;
        switch4.ethg[1] <--> C <--> host14.ethg++;
        switch4.ethg[2] <--> C <--> host15.ethg++;
        switch4.ethg[3] <--> C <--> host16.ethg++;
        switch1.ethg[4] <--> C <--> switch5.ethg[0];
        switch1.ethg[5] <--> C <--> switch6.ethg[0];
        switch2.ethg[4] <--> C <--> switch5.ethg[1];
        switch2.ethg[5] <--> C <--> switch6.ethg[1];
        switch3.ethg[4] <--> C <--> switch5.ethg[2];
        switch3.ethg[5] <--> C <--> switch6.ethg[2];
        switch4.ethg[4] <--> C <--> switch5.ethg[3];
        switch4.ethg[5] <--> C <--> switch6.ethg[3];


}
