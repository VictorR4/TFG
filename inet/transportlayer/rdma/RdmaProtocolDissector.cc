/*
 * RdmaProtocolDissector.cc
 *
 *  Created on: Sep 22, 2021
 *      Author: victor
 */

#include "inet/transportlayer/rdma/RdmaProtocolDissector.h"

#include "inet/common/ProtocolGroup.h"
#include "inet/common/packet/dissector/ProtocolDissectorRegistry.h"
#include "inet/transportlayer/rdma/Rdma.h"
#include "inet/transportlayer/rdma/RdmaHeader_m.h"

namespace inet {

Register_Protocol_Dissector(&Protocol::rdma, RdmaProtocolDissector);

void RdmaProtocolDissector::dissect(Packet *packet, const Protocol *protocol, ICallback& callback) const
{
    auto originalTrailerPopOffset = packet->getBackOffset();
    auto rdmaHeaderOffset = packet->getFrontOffset();
    auto header = packet->popAtFront<RdmaHeader>();
    callback.startProtocolDataUnit(&Protocol::rdma);
    bool isCorrectPacket = Rdma::isCorrectPacket(packet, header);
    if (!isCorrectPacket)
        callback.markIncorrect();
    callback.visitChunk(header, &Protocol::rdma);
    auto rdmaPayloadEndOffset = rdmaHeaderOffset + B(header->getTotalLengthField());
    packet->setBackOffset(rdmaPayloadEndOffset);
    auto dataProtocol = ProtocolGroup::rdmaprotocol.findProtocol(header->getDestPort());
    if (dataProtocol == nullptr)
        dataProtocol = ProtocolGroup::rdmaprotocol.findProtocol(header->getSrcPort());
    callback.dissectPacket(packet, dataProtocol);
    ASSERT(packet->getDataLength() == B(0));
    packet->setFrontOffset(rdmaPayloadEndOffset);
    packet->setBackOffset(originalTrailerPopOffset);
    callback.endProtocolDataUnit(&Protocol::rdma);
}

} // namespace inet



