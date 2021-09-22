/*
 * RdmaHeaderSerializer.h
 *
 *  Created on: Sep 22, 2021
 *      Author: victor
 */

#ifndef INET_TRANSPORTLAYER_RDMA_RDMAHEADERSERIALIZER_H_
#define INET_TRANSPORTLAYER_RDMA_RDMAHEADERSERIALIZER_H_

#include "inet/common/packet/serializer/FieldsChunkSerializer.h"

namespace inet {

/**
 * Converts between UdpHeader and binary (network byte order) Udp header.
 */
class INET_API RdmaHeaderSerializer : public FieldsChunkSerializer
{
  protected:
    virtual void serialize(MemoryOutputStream& stream, const Ptr<const Chunk>& chunk) const override;
    virtual const Ptr<Chunk> deserialize(MemoryInputStream& stream) const override;

  public:
    RdmaHeaderSerializer() : FieldsChunkSerializer() {}
};

} // namespace inet



#endif /* INET_TRANSPORTLAYER_RDMA_RDMAHEADERSERIALIZER_H_ */
