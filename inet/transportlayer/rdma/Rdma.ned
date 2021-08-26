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

package inet.transportlayer.rdma;

//
// TODO auto-generated type
//
import inet.transportlayer.contract.IRdma;

simple Rdma like IRdma
{
    parameters:
        string interfaceTableModule;   // The path to the InterfaceTable module
        string crcMode @enum("disabled", "declared", "computed") = default("declared");
        @display("i=block/transport");
        @signal[packetSentToUpper](type=cPacket);
        @signal[packetReceivedFromUpper](type=cPacket);
        @signal[packetSentToLower](type=cPacket);
        @signal[packetReceivedFromLower](type=cPacket);
        @signal[packetDropped](type=inet::Packet);
        @signal[packetSent](type=cPacket);
        @signal[packetReceived](type=cPacket);
        @statistic[packetSent](title="packets sent"; source=packetSent; record=count,"sum(packetBytes)","vector(packetBytes)"; interpolationmode=none);
        @statistic[packetReceived](title="packets received"; source=packetReceived; record=count,"sum(packetBytes)","vector(packetBytes)"; interpolationmode=none);
        @statistic[passedUpPk](title="packets passed up"; source=packetSentToUpper; record=count,"vector(count)"; interpolationmode=none);
        @statistic[droppedPkWrongPort](title="packets dropped (wrong port)"; source=packetDropReasonIsNoPortFound(packetDropped); record=count,"vector(count)"; interpolationmode=none);
        @statistic[droppedPkBadChecksum](title="packets dropped (checksum error)"; source=packetDropReasonIsIncorrectlyReceived(packetDropped); record=count,"vector(count)"; interpolationmode=none);
        @selfMessageKinds();    // kind not used in self messages or model doesn't use any self message
        @directSendKinds();     // kind not used in sendDirect() messages or model doesn't use any sendDirect()
        
    gates:
		input appIn @labels(RDMAControlInfo/down);
        output appOut @labels(RDMAControlInfo/up);
        input lowerLayerIn;
        output lowerLayerOut;
}