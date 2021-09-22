/*
 * RdmaHeaderSerializer.cc
 *
 *  Created on: Sep 22, 2021
 *      Author: victor
 */

#include "inet/transportlayer/rdma/RdmaHeaderSerializer.h"

#include "inet/common/packet/serializer/ChunkSerializerRegistry.h"
#include "inet/transportlayer/rdma/RdmaHeader_m.h"

namespace inet {

Register_Serializer(RdmaHeader, RdmaHeaderSerializer);

void RdmaHeaderSerializer::serialize(MemoryOutputStream& stream, const Ptr<const Chunk>& chunk) const
{
    const auto& rdmaHeader = staticPtrCast<const RdmaHeader>(chunk);
    stream.writeUint16Be(rdmaHeader->getSourcePort());
    stream.writeUint16Be(rdmaHeader->getDestinationPort());
    stream.writeUint16Be(B(rdmaHeader->getTotalLengthField()).get());
    auto crcMode = rdmaHeader->getCrcMode();
    if (crcMode != CRC_DISABLED && crcMode != CRC_COMPUTED)
        throw cRuntimeError("Cannot serialize RDMA header without turned off or properly computed CRC, try changing the value of crcMode parameter for Rdma");
    stream.writeUint16Be(rdmaHeader->getCrc());
}

const Ptr<Chunk> RdmaHeaderSerializer::deserialize(MemoryInputStream& stream) const
{
    auto rdmaHeader = makeShared<RdmaHeader>();
    rdmaHeader->setSourcePort(stream.readUint16Be());
    rdmaHeader->setDestinationPort(stream.readUint16Be());
    rdmaHeader->setTotalLengthField(B(stream.readUint16Be()));
    auto crc = stream.readUint16Be();
    rdmaHeader->setCrc(crc);
    rdmaHeader->setCrcMode(crc == 0 ? CRC_DISABLED : CRC_COMPUTED);
    return rdmaHeader;
}

} // namespace inet




