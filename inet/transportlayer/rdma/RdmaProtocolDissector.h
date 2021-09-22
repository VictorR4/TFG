/*
 * RdmaProtocolDissector.h
 *
 *  Created on: Sep 22, 2021
 *      Author: victor
 */

#ifndef INET_TRANSPORTLAYER_RDMA_RDMAPROTOCOLDISSECTOR_H_
#define INET_TRANSPORTLAYER_RDMA_RDMAPROTOCOLDISSECTOR_H_


#include "inet/common/packet/dissector/ProtocolDissector.h"

namespace inet {

class INET_API RdmaProtocolDissector : public ProtocolDissector
{
  public:
    virtual void dissect(Packet *packet, const Protocol *protocol, ICallback& callback) const override;
};

} // namespace inet


#endif /* INET_TRANSPORTLAYER_RDMA_RDMAPROTOCOLDISSECTOR_H_ */
