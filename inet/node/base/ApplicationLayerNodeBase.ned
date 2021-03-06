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

package inet.node.base;

import inet.applications.contract.IApp;
import inet.common.MessageDispatcher;
import ned.DatarateChannel;
import inet.node.ethernet.Eth40G;

module ApplicationLayerNodeBase extends TransportLayerNodeBase
{
    parameters:
        int numApps = default(0);
        @figure[applicationLayer](type=rectangle; pos=250,6; size=1000,130; lineColor=#808080; cornerRadius=5; fillColor=#ffff00; fillOpacity=0.1);
        @figure[applicationLayer.title](type=text; pos=1245,11; anchor=ne; text="application layer");
        
    submodules:
        app[numApps]: <> like IApp {
            parameters:
                @display("p=375,76,row,150");
        }
        at: MessageDispatcher {
            parameters:
                @display("p=750,146;b=1000,5,,,,1");
        }

    connections allowunconnected:
        for i=0..numApps-1 {
            app[i].socketOut --> Eth40G --> at.in++ if !hasTcp;
            app[i].socketOut --> at.in++ if hasTcp;//3
            app[i].socketIn <-- Eth40G <-- at.out++ if !hasTcp;//2
            app[i].socketIn  <-- at.out++ if hasTcp;//

        }

        at.out++ --> Eth40G --> udp.appIn if hasUdp;//
        at.in++  <-- Eth40G <-- udp.appOut if hasUdp;//

        at.out++ --> tcp.appIn if hasTcp;//4
        at.in++ <-- tcp.appOut if hasTcp;//1

        at.out++ --> sctp.appIn if hasSctp;
        at.in++ <-- sctp.appOut if hasSctp;

        at.out++ --> tn.in++;
        at.in++  <-- tn.out++;


}

