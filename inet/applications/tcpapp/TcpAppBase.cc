//
// Copyright (C) 2004 OpenSim Ltd.
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

#include "inet/applications/tcpapp/TcpAppBase.h"

#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/transportlayer/contract/tcp/TcpSocket.h"
#include "inet/common/TimeTag_m.h"
#include "inet/applications/tcpapp/GenericAppMsg_m.h"

namespace inet {

simsignal_t TcpAppBase::connectSignal = registerSignal("connect");

void TcpAppBase::initialize(int stage)
{
    ApplicationBase::initialize(stage);

    if (stage == INITSTAGE_LOCAL) {
        numSessions = numBroken = packetsSent = packetsRcvd = bytesSent = bytesRcvd = 0;

        WATCH(numSessions);
        WATCH(numBroken);
        WATCH(packetsSent);
        WATCH(packetsRcvd);
        WATCH(bytesSent);
        WATCH(bytesRcvd);
    }
    else if (stage == INITSTAGE_APPLICATION_LAYER) {
        // parameters
        const char *localAddress = par("localAddress");
        int localPort = par("localPort");
        socket.bind(*localAddress ? L3AddressResolver().resolve(localAddress) : L3Address(), localPort);

        socket.setCallback(this);
        socket.setOutputGate(gate("socketOut"));
    }
}

void TcpAppBase::handleMessageWhenUp(cMessage *msg)
{
    if (msg->isSelfMessage())
        handleTimer(msg);
    else
        socket.processMessage(msg);
}

L3Address TcpAppBase::chooseDestAddr()
{
    int k = intrand(destAddresses.size());
    if (destAddresses[k].isUnspecified() || destAddresses[k].isLinkLocal()) {
        L3AddressResolver().tryResolve(destAddressStr[k].c_str(), destAddresses[k]);
    }
    return destAddresses[k];
}

void TcpAppBase::connect()
{
    // we need a new connId if this is not the first connection
    socket.renewSocket();

    const char *localAddress = par("localAddress");
    int localPort = par("localPort");
    socket.bind(*localAddress ? L3AddressResolver().resolve(localAddress) : L3Address(), localPort);

    int timeToLive = par("timeToLive");
    if (timeToLive != -1)
        socket.setTimeToLive(timeToLive);

    int dscp = par("dscp");
    if (dscp != -1)
        socket.setDscp(dscp);

    int tos = par("tos");
    if (tos != -1)
        socket.setTos(tos);

    // connect
    const char *connectAddrs = par("connectAddress");
    cStringTokenizer tokenizer(connectAddrs);
    const char *token;

    bool excludeLocalDestAddresses = par("excludeLocalDestAddresses");
    IInterfaceTable *ift = getModuleFromPar<IInterfaceTable>(par("interfaceTableModule"), this);
    int connectPort = par("connectPort");
    L3Address destination;

    while ((token = tokenizer.nextToken()) != nullptr) {
        if (strstr(token, "Broadcast") != nullptr)
            destAddresses.push_back(Ipv4Address::ALLONES_ADDRESS);
        else {
            L3Address addr = L3AddressResolver().resolve(token);
            if (excludeLocalDestAddresses && ift && ift->isLocalAddress(addr))
                continue;
            destAddresses.push_back(addr);
        }
    }

    destination = chooseDestAddr();
    //L3AddressResolver().tryResolve(connectAddress, destination);
    if (destination.isUnspecified()) {
        //EV_ERROR << "Connecting to " << connectAddress << " port=" << connectPort << ": cannot resolve destination address\n";
    }
    else {
        EV_INFO << "Connecting to " /*<< connectAddress*/ << "(" << destination << ") port=" << connectPort << endl;

        socket.connect(destination, connectPort);

        numSessions++;
        emit(connectSignal, 1L);
    }
}

void TcpAppBase::close()
{
    EV_INFO << "issuing CLOSE command\n";
    socket.close();
    emit(connectSignal, -1L);
}

void TcpAppBase::sendPacket(Packet *msg)
{
    int numBytes = msg->getByteLength();
    emit(packetSentSignal, msg);
    socket.send(msg);

    packetsSent++;
    bytesSent += numBytes;
}

void TcpAppBase::refreshDisplay() const
{
    ApplicationBase::refreshDisplay();
    getDisplayString().setTagArg("t", 0, TcpSocket::stateName(socket.getState()));
}

void TcpAppBase::socketEstablished(TcpSocket *)
{
    // *redefine* to perform or schedule first sending
    EV_INFO << "connected\n";
}

void TcpAppBase::socketDataArrived(TcpSocket *, Packet *msg, bool)
{
    // *redefine* to perform or schedule next sending

    EV_INFO << "Tiempo de recepción de fragmento con = " << msg->getByteLength() << ", es " << simTime() << "\n";
    totalreceivedMessagesLength = B(par("requestLength"));
    receivedMessageLength += B(msg->getByteLength());
    if(totalreceivedMessagesLength == receivedMessageLength){
        EV_INFO << "Tiempo de envío de paquete es = " << creationTime << "\n";
        EV_INFO << "Tiempo de recepción de paquete entero es = " << simTime() << "\n";
        packetsRcvd++;
        bytesRcvd += receivedMessageLength.get();//msg->getByteLength();
        emit(packetReceivedSignal, msg);
        receivedMessageLength = B(0);
        latency = simTime() - creationTime;
        EV_INFO << "Latencia = " << latency << "\n";
        latencyPackets.push_back(latency);
        statsLatencyVector.record(latency);
        statsLatency.collect(latency);
    }
    delete msg;
}

void TcpAppBase::socketPeerClosed(TcpSocket *socket_)
{
    ASSERT(socket_ == &socket);
    // close the connection (if not already closed)
    if (socket.getState() == TcpSocket::PEER_CLOSED) {
        EV_INFO << "remote TCP closed, closing here as well\n";
        close();
    }
}

void TcpAppBase::socketClosed(TcpSocket *)
{
    // *redefine* to start another session etc.
    EV_INFO << "connection closed\n";
}

void TcpAppBase::socketFailure(TcpSocket *, int code)
{
    // subclasses may override this function, and add code try to reconnect after a delay.
    EV_WARN << "connection broken\n";
    numBroken++;
}

void TcpAppBase::finish()
{
    std::string modulePath = getFullPath();

    EV_INFO << modulePath << ": opened " << numSessions << " sessions\n";
    EV_INFO << modulePath << ": sent " << bytesSent << " bytes in " << packetsSent << " packets\n";
    EV_INFO << modulePath << ": received " << bytesRcvd << " bytes in " << packetsRcvd << " packets\n";

    EV << "Media: " << statsLatency.getMean() << endl;
    EV << "Desviación típica: " << statsLatency.getStddev() << endl;
    //Calculo del intervalo de confianza
    auto confidenceIntervalMax = statsLatency.getMean() + 1.96 * statsLatency.getStddev()/sqrt(packetsRcvd);
    auto confidenceIntervalMin = statsLatency.getMean() - 1.96 * statsLatency.getStddev()/sqrt(packetsRcvd);
    EV_INFO << "Invervalo de confianza: (" << confidenceIntervalMin << "," << confidenceIntervalMax << ")\n";
    for (int i = 0; i < packetsRcvd; i++) {
        if(latencyPackets[i] >= confidenceIntervalMin){
            latency += latencyPackets[i];
            valoresValidos++;
        }
    }

    recordScalar("meanLatency", latency.dbl()/valoresValidos, "s");
    EV_INFO << "Media de confianza = " << latency.dbl()/valoresValidos << "\n";
    EV_INFO << "Latency = " << latency.dbl() << "\n";
    EV_INFO << "Valores validos = " << valoresValidos << "\n";
    statsLatency.collect(latency);
    statsLatency.recordAs("statsLatency");
    recordScalar("valoresValidos", valoresValidos);
}

} // namespace inet

