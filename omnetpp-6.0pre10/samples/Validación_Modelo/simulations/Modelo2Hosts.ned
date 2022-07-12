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

//
// TODO auto-generated type
//

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.ethernet.Eth40G;
import inet.node.inet.StandardHost;
import inet.node.ethernet.EthernetSwitch;
import ned.DatarateChannel;

network Modelo2Hosts
{
    @display("bgb=551,225");
    types:
        channel cable extends DatarateChannel{
            datarate = 40Gbps;
            double length @unit(m) = default(10m);
    		delay = replaceUnit(4*length / 2e8, "s");
        }
    submodules:
        H_0: StandardHost {
            @display("p=104,114");
        }
        SW_1_1: EthernetSwitch {
            gates:
                ethg[2];
        }
        H_1: StandardHost {
            @display("p=470,114");
        }

        configurator: Ipv4NetworkConfigurator {
            @display("p=395,178");
        }
    connections:
        SW_1_1.ethg[0] <--> Eth40G <--> H_0.ethg++;
        SW_1_1.ethg[1] <--> Eth40G <--> H_1.ethg++;
}
