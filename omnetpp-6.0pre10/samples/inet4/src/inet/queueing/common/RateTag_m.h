//
// Generated file, do not edit! Created by nedtool 6.0 from inet/queueing/common/RateTag.msg.
//

#ifndef __INET_RATETAG_M_H
#define __INET_RATETAG_M_H

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

class RateTag;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/TagBase_m.h" // import inet.common.TagBase

#include "inet/common/Units_m.h" // import inet.common.Units


namespace inet {

/**
 * Class generated from <tt>inet/queueing/common/RateTag.msg:30</tt> by nedtool.
 * <pre>
 * //
 * // This tag can be attached to individual packets the specify the data rate and
 * // packet rate. The values are meaningful for a stream of packets which this
 * // packet is part of.
 * //
 * class RateTag extends TagBase
 * {
 *     bps datarate;
 *     double packetrate;
 * }
 * </pre>
 */
class INET_API RateTag : public ::inet::TagBase
{
  protected:
    bps datarate = bps(NaN);
    double packetrate = 0;

  private:
    void copy(const RateTag& other);

  protected:
    bool operator==(const RateTag&) = delete;

  public:
    RateTag();
    RateTag(const RateTag& other);
    virtual ~RateTag();
    RateTag& operator=(const RateTag& other);
    virtual RateTag *dup() const override {return new RateTag(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual bps getDatarate() const;
    virtual void setDatarate(bps datarate);
    virtual double getPacketrate() const;
    virtual void setPacketrate(double packetrate);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const RateTag& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, RateTag& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_RATETAG_M_H

