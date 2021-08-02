//
// Generated file, do not edit! Created by nedtool 6.0 from inet/networklayer/mpls/MplsPacket.msg.
//

#ifndef __INET_MPLSPACKET_M_H
#define __INET_MPLSPACKET_M_H

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

class MplsHeader;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk

#include "inet/networklayer/contract/ipv4/Ipv4Address_m.h" // import inet.networklayer.contract.ipv4.Ipv4Address


namespace inet {

/**
 * Class generated from <tt>inet/networklayer/mpls/MplsPacket.msg:26</tt> by nedtool.
 * <pre>
 * class MplsHeader extends FieldsChunk
 * {
 *     chunkLength = B(4);
 *     uint32_t label;     // \@bit(20)  Label value. A label with the value of 1 represents the router alert label.
 *     uint8_t tc;       // \@bit(3)   Traffic Class field for QoS (quality of service) priority and ECN (Explicit Congestion Notification). Prior to 2009 this field was called EXP.
 *     bool s;         // \@bit(1)   bottom of stack flag. If this is set, it signifies that the current label is the last in the stack.
 *     uint8_t ttl;      // \@bit(8)   time to live
 * }
 * </pre>
 */
class INET_API MplsHeader : public ::inet::FieldsChunk
{
  protected:
    uint32_t label = 0;
    uint8_t tc = 0;
    bool s = false;
    uint8_t ttl = 0;

  private:
    void copy(const MplsHeader& other);

  protected:
    bool operator==(const MplsHeader&) = delete;

  public:
    MplsHeader();
    MplsHeader(const MplsHeader& other);
    virtual ~MplsHeader();
    MplsHeader& operator=(const MplsHeader& other);
    virtual MplsHeader *dup() const override {return new MplsHeader(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint32_t getLabel() const;
    virtual void setLabel(uint32_t label);
    virtual uint8_t getTc() const;
    virtual void setTc(uint8_t tc);
    virtual bool getS() const;
    virtual void setS(bool s);
    virtual uint8_t getTtl() const;
    virtual void setTtl(uint8_t ttl);

  public:
    /**
     * Returns MPLS header in human readable format string.
     */
    virtual std::string str() const override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const MplsHeader& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, MplsHeader& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_MPLSPACKET_M_H

