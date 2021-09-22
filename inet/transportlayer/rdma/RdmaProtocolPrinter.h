/*
 * RdmaProtocolPrinter.h
 *
 *  Created on: Sep 22, 2021
 *      Author: victor
 */

#ifndef INET_TRANSPORTLAYER_RDMA_RDMAPROTOCOLPRINTER_H_
#define INET_TRANSPORTLAYER_RDMA_RDMAPROTOCOLPRINTER_H_


#include "inet/common/packet/printer/ProtocolPrinter.h"

namespace inet {

class INET_API RdmaProtocolPrinter : public ProtocolPrinter
{
  public:
    virtual void print(const Ptr<const Chunk>& chunk, const Protocol *protocol, const cMessagePrinter::Options *options, Context& context) const override;
};

} // namespace inet


#endif /* INET_TRANSPORTLAYER_RDMA_RDMAPROTOCOLPRINTER_H_ */
