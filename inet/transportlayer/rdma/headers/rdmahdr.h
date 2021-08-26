/*
 * rdmahdr.h
 *
 *  Created on: Aug 10, 2021
 *      Author: vr4
 */

#ifndef INET_TRANSPORTLAYER_RDMA_HEADERS_RDMAHDR_H_
#define INET_TRANSPORTLAYER_RDMA_HEADERS_RDMAHDR_H_

namespace inet {

/*
 * Udp protocol header.
 * Per RFC 768, September, 1981.
 */
struct rdmahdr
{
    u_short uh_sport;    /* source port */
    u_short uh_dport;    /* destination port */
    u_short uh_ulen;    /* rdma length */
    u_short uh_sum;    /* rdma checksum */
};

} // namespace inet



#endif /* INET_TRANSPORTLAYER_RDMA_HEADERS_RDMAHDR_H_ */
