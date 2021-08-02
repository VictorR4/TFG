//
// Generated file, do not edit! Created by nedtool 6.0 from inet/routing/ospf_common/OspfPacketBase.msg.
//

#ifndef __INET__OSPF_OSPFPACKETBASE_M_H
#define __INET__OSPF_OSPFPACKETBASE_M_H

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
namespace ospf {

class OspfPacketBase;
} // namespace ospf
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk

#include "inet/networklayer/contract/ipv4/Ipv4Address_m.h" // import inet.networklayer.contract.ipv4.Ipv4Address

#include "inet/transportlayer/common/CrcMode_m.h" // import inet.transportlayer.common.CrcMode


namespace inet {
namespace ospf {

/**
 * Enum generated from <tt>inet/routing/ospf_common/OspfPacketBase.msg:27</tt> by nedtool.
 * <pre>
 * enum OspfPacketType
 * {
 *     HELLO_PACKET = 1;
 *     DATABASE_DESCRIPTION_PACKET = 2;
 *     LINKSTATE_REQUEST_PACKET = 3;
 *     LINKSTATE_UPDATE_PACKET = 4;
 *     LINKSTATE_ACKNOWLEDGEMENT_PACKET = 5;
 * }
 * </pre>
 */
enum OspfPacketType {
    HELLO_PACKET = 1,
    DATABASE_DESCRIPTION_PACKET = 2,
    LINKSTATE_REQUEST_PACKET = 3,
    LINKSTATE_UPDATE_PACKET = 4,
    LINKSTATE_ACKNOWLEDGEMENT_PACKET = 5
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const OspfPacketType& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, OspfPacketType& e) { int n; b->unpack(n); e = static_cast<OspfPacketType>(n); }

/**
 * Class generated from <tt>inet/routing/ospf_common/OspfPacketBase.msg:39</tt> by nedtool.
 * <pre>
 * //
 * // Represents an OSPF packet header
 * //
 * class OspfPacketBase extends FieldsChunk
 * {
 *     chunkLength = B(14);
 *     short version = -1;     // 1 byte
 *     OspfPacketType type = static_cast<OspfPacketType>(-1);    // 1 byte
 *     int packetLengthField;  // 2 bytes
 * 
 *     Ipv4Address routerID;   // 4 bytes
 *     Ipv4Address areaID;     // 4 bytes
 * 
 *     uint16_t crc = 0;       // 2 bytes
 *     CrcMode crcMode = CRC_MODE_UNDEFINED;
 * }
 * </pre>
 */
class INET_API OspfPacketBase : public ::inet::FieldsChunk
{
  protected:
    short version = -1;
    inet::ospf::OspfPacketType type = static_cast<OspfPacketType>(-1);
    int packetLengthField = 0;
    Ipv4Address routerID;
    Ipv4Address areaID;
    uint16_t crc = 0;
    inet::CrcMode crcMode = CRC_MODE_UNDEFINED;

  private:
    void copy(const OspfPacketBase& other);

  protected:
    bool operator==(const OspfPacketBase&) = delete;

  public:
    OspfPacketBase();
    OspfPacketBase(const OspfPacketBase& other);
    virtual ~OspfPacketBase();
    OspfPacketBase& operator=(const OspfPacketBase& other);
    virtual OspfPacketBase *dup() const override {return new OspfPacketBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual short getVersion() const;
    virtual void setVersion(short version);
    virtual inet::ospf::OspfPacketType getType() const;
    virtual void setType(inet::ospf::OspfPacketType type);
    virtual int getPacketLengthField() const;
    virtual void setPacketLengthField(int packetLengthField);
    virtual const Ipv4Address& getRouterID() const;
    virtual Ipv4Address& getRouterIDForUpdate() { handleChange();return const_cast<Ipv4Address&>(const_cast<OspfPacketBase*>(this)->getRouterID());}
    virtual void setRouterID(const Ipv4Address& routerID);
    virtual const Ipv4Address& getAreaID() const;
    virtual Ipv4Address& getAreaIDForUpdate() { handleChange();return const_cast<Ipv4Address&>(const_cast<OspfPacketBase*>(this)->getAreaID());}
    virtual void setAreaID(const Ipv4Address& areaID);
    virtual uint16_t getCrc() const;
    virtual void setCrc(uint16_t crc);
    virtual inet::CrcMode getCrcMode() const;
    virtual void setCrcMode(inet::CrcMode crcMode);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const OspfPacketBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, OspfPacketBase& obj) {obj.parsimUnpack(b);}

} // namespace ospf
} // namespace inet

#endif // ifndef __INET__OSPF_OSPFPACKETBASE_M_H

