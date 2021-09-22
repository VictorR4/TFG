/*
 * RdmaProtocolPrinter.cc
 *
 *  Created on: Sep 22, 2021
 *      Author: victor
 */


#include "inet/transportlayer/rdma/RdmaProtocolPrinter.h"

#include "inet/common/packet/printer/PacketPrinter.h"
#include "inet/common/packet/printer/ProtocolPrinterRegistry.h"
#include "inet/transportlayer/rdma/RdmaHeader_m.h"

namespace inet {

Register_Protocol_Printer(&Protocol::rdma, RdmaProtocolPrinter);

void RdmaProtocolPrinter::print(const Ptr<const Chunk>& chunk, const Protocol *protocol, const cMessagePrinter::Options *options, Context& context) const
{
    if (auto header = dynamicPtrCast<const RdmaHeader>(chunk)) {
        context.sourceColumn << header->getSrcPort();
        context.destinationColumn << header->getDestPort();
        context.infoColumn << header->getSrcPort() << "->" << header->getDestPort() << ", payload:" << (B(header->getTotalLengthField()) - header->getChunkLength());
    }
    else
        context.infoColumn << "(RDMA) " << chunk;
}

} // namespace inet



