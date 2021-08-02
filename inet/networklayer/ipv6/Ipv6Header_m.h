//
// Generated file, do not edit! Created by nedtool 6.0 from inet/networklayer/ipv6/Ipv6Header.msg.
//

#ifndef __INET_IPV6HEADER_M_H
#define __INET_IPV6HEADER_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef INET_API
#  if defined(INET_EXPORT)
#    define INET_API  OPP_DLLEXPORT
#  elif defined(INET_IMPORT)
#    define INET_API  OPP_DLLIMPORT
#  else
#    define INET_API
#  endif
#endif


namespace inet {

class Ipv6ExtensionHeader;
class Ipv6Header;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/networklayer/common/IpProtocolId_m.h" // import inet.networklayer.common.IpProtocolId

#include "inet/networklayer/contract/NetworkHeaderBase_m.h" // import inet.networklayer.contract.NetworkHeaderBase

#include "inet/networklayer/contract/ipv6/Ipv6Address_m.h" // import inet.networklayer.contract.ipv6.Ipv6Address

// cplusplus {{
#include <iostream>
#include "inet/common/ProtocolGroup.h"
#include "inet/networklayer/contract/ipv6/Ipv6Consts.h"
// }}


namespace inet {

// cplusplus {{
class Ipv6ExtensionHeader;
std::ostream& operator<<(std::ostream& os, Ipv6ExtensionHeader eh);
// }}

/**
 * Class generated from <tt>inet/networklayer/ipv6/Ipv6Header.msg:45</tt> by nedtool.
 * <pre>
 * //
 * // This serves as the base class for all the Ipv6 extension headers.
 * //
 * class Ipv6ExtensionHeader extends cObject
 * {
 *     \@packetData;
 *     uint8_t extensionType;
 *     B byteLength = B(0);   // byteLength = n * 8;
 * }
 * </pre>
 */
class INET_API Ipv6ExtensionHeader : public ::omnetpp::cObject
{
  protected:
    uint8_t extensionType = 0;
    B byteLength = B(0);

  private:
    void copy(const Ipv6ExtensionHeader& other);

  protected:
    bool operator==(const Ipv6ExtensionHeader&) = delete;

  public:
    Ipv6ExtensionHeader();
    Ipv6ExtensionHeader(const Ipv6ExtensionHeader& other);
    virtual ~Ipv6ExtensionHeader();
    Ipv6ExtensionHeader& operator=(const Ipv6ExtensionHeader& other);
    virtual Ipv6ExtensionHeader *dup() const override {return new Ipv6ExtensionHeader(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint8_t getExtensionType() const;
    virtual void setExtensionType(uint8_t extensionType);
    virtual B getByteLength() const;
    virtual void setByteLength(B byteLength);

  public:
    int getOrder() const;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv6ExtensionHeader& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv6ExtensionHeader& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ipv6/Ipv6Header.msg:63</tt> by nedtool.
 * <pre>
 * //
 * // Ipv6 datagram. RFC 2460 Section 3.
 * //
 * // Header fields not explicitly modelled:
 * //    - payload length: will be calculated from encapsulated message length
 * //      and extension headers' length
 * //
 * class Ipv6Header extends NetworkHeaderBase
 * {
 *     chunkLength = IPv6_HEADER_BYTES;
 *     uint8_t version = 6;
 *     Ipv6Address srcAddress;
 *     Ipv6Address destAddress;
 *     B payloadLength = B(-1);    // The size of the payload in octets, including any extension headers. The length is set to zero when a Hop-by-Hop extension header carries a Jumbo Payload option.
 *     short trafficClass;    // \@bits(8) Traffic Class
 *     // OMNeT++ 6.0:
 *     // short __dscp \@custom \@getter(getDscp) \@setter(setDscp);  // \@bit(6), maps to bits 0-5 of trafficClass
 *     // short __ecn \@custom \@getter(getEcn) \@setter(setEcn);  // \@bit(2),  maps to bits 6-7 of trafficClass
 * 
 *     unsigned int flowLabel;
 *     short hopLimit = 0;
 *     IpProtocolId protocolId = IP_PROT_NONE;
 * 
 *     Ipv6ExtensionHeader *extensionHeader[] \@owned; // array of extension headers, subclassed from ~Ipv6ExtensionHeader
 * }
 * </pre>
 */
class INET_API Ipv6Header : public ::inet::NetworkHeaderBase
{
  protected:
    uint8_t version = 6;
    Ipv6Address srcAddress;
    Ipv6Address destAddress;
    B payloadLength = B(-1);
    short trafficClass = 0;
    unsigned int flowLabel = 0;
    short hopLimit = 0;
    inet::IpProtocolId protocolId = IP_PROT_NONE;
    Ipv6ExtensionHeader * *extensionHeader = nullptr;
    size_t extensionHeader_arraysize = 0;

  private:
    void copy(const Ipv6Header& other);

  protected:
    bool operator==(const Ipv6Header&) = delete;

  public:
    Ipv6Header();
    Ipv6Header(const Ipv6Header& other);
    virtual ~Ipv6Header();
    Ipv6Header& operator=(const Ipv6Header& other);
    virtual Ipv6Header *dup() const override {return new Ipv6Header(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint8_t getVersion() const;
    virtual void setVersion(uint8_t version);
    virtual const Ipv6Address& getSrcAddress() const;
    virtual Ipv6Address& getSrcAddressForUpdate() { handleChange();return const_cast<Ipv6Address&>(const_cast<Ipv6Header*>(this)->getSrcAddress());}
    virtual void setSrcAddress(const Ipv6Address& srcAddress);
    virtual const Ipv6Address& getDestAddress() const;
    virtual Ipv6Address& getDestAddressForUpdate() { handleChange();return const_cast<Ipv6Address&>(const_cast<Ipv6Header*>(this)->getDestAddress());}
    virtual void setDestAddress(const Ipv6Address& destAddress);
    virtual B getPayloadLength() const;
    virtual void setPayloadLength(B payloadLength);
    virtual short getTrafficClass() const;
    virtual void setTrafficClass(short trafficClass);
    virtual unsigned int getFlowLabel() const;
    virtual void setFlowLabel(unsigned int flowLabel);
    virtual short getHopLimit() const;
    virtual void setHopLimit(short hopLimit);
    virtual inet::IpProtocolId getProtocolId() const;
    virtual void setProtocolId(inet::IpProtocolId protocolId);
    virtual void setExtensionHeaderArraySize(size_t size);
    virtual size_t getExtensionHeaderArraySize() const;
    virtual const Ipv6ExtensionHeader * getExtensionHeader(size_t k) const;
    virtual Ipv6ExtensionHeader * getExtensionHeaderForUpdate(size_t k) { handleChange();return const_cast<Ipv6ExtensionHeader *>(const_cast<Ipv6Header*>(this)->getExtensionHeader(k));}
    virtual Ipv6ExtensionHeader * dropExtensionHeader(size_t k);
    virtual void setExtensionHeader(size_t k, Ipv6ExtensionHeader * extensionHeader);
    virtual void insertExtensionHeader(Ipv6ExtensionHeader * extensionHeader);
    virtual void insertExtensionHeader(size_t k, Ipv6ExtensionHeader * extensionHeader);
    virtual void eraseExtensionHeader(size_t k);

  public:
    virtual short getDscp() const;
    virtual void setDscp(short dscp);
    virtual short getEcn() const;
    virtual void setEcn(short ecn);

    /**
     * Returns the extension header of the specified type,
     * or nullptr. If index is 0, then the first, if 1 then the
     * second extension is returned. (The datagram might
     * contain two Destination Options extension.)
     */
    virtual Ipv6ExtensionHeader *findExtensionHeaderByTypeForUpdate(IpProtocolId extensionType, int index = 0);
    virtual const Ipv6ExtensionHeader *findExtensionHeaderByType(IpProtocolId extensionType, int index = 0) const;

    /**
     * Adds an extension header to the datagram.
     * The extension headers are stored in the order specified in RFC 2460 4.1.
     */
    virtual void addExtensionHeader(Ipv6ExtensionHeader *eh);

    /**
     * Calculates the length of the Ipv6 header plus the extension
     * headers.
     */
    virtual B calculateHeaderByteLength() const;

    /**
     * Calculates the length of the unfragmentable part of Ipv6 header
     * plus the extension headers.
     */
    virtual B calculateUnfragmentableHeaderByteLength() const;

    /**
     * Calculates the length of the payload and extension headers
     * after the Fragment Header.
     */
    virtual B calculateFragmentLength() const;

    /**
     * Removes and returns the first extension header of this datagram
     */
    virtual Ipv6ExtensionHeader *removeFirstExtensionHeader();


    /**
     * Removes and returns the first extension header with the given type.
     */
    virtual Ipv6ExtensionHeader *removeExtensionHeader(IpProtocolId extensionType);

    // implements NetworkHeaderBase functions:
    virtual L3Address getSourceAddress() const override { return L3Address(getSrcAddress()); }
    virtual void setSourceAddress(const L3Address& address) override { setSrcAddress(address.toIpv6()); }
    virtual L3Address getDestinationAddress() const override { return L3Address(getDestAddress()); }
    virtual void setDestinationAddress(const L3Address& address) override { setDestAddress(address.toIpv6()); }
    virtual const Protocol *getProtocol() const override { return ProtocolGroup::ipprotocol.findProtocol(getProtocolId()); }
    virtual void setProtocol(const Protocol *protocol) override { setProtocolId(static_cast<IpProtocolId>(ProtocolGroup::ipprotocol.getProtocolNumber(protocol))); }
    virtual bool isFragment() const override { return findExtensionHeaderByType(IP_PROT_IPv6EXT_FRAGMENT) != nullptr; }
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv6Header& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv6Header& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_IPV6HEADER_M_H

