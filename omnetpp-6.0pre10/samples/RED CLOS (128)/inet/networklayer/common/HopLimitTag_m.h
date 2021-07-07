//
// Generated file, do not edit! Created by nedtool 6.0 from inet/networklayer/common/HopLimitTag.msg.
//

#ifndef __INET_HOPLIMITTAG_M_H
#define __INET_HOPLIMITTAG_M_H

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

class HopLimitTagBase;
class HopLimitReq;
class HopLimitInd;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/TagBase_m.h" // import inet.common.TagBase


namespace inet {

/**
 * Class generated from <tt>inet/networklayer/common/HopLimitTag.msg:11</tt> by nedtool.
 * <pre>
 * class HopLimitTagBase extends TagBase
 * {
 *     int hopLimit = -1;
 * }
 * </pre>
 */
class INET_API HopLimitTagBase : public ::inet::TagBase
{
  protected:
    int hopLimit = -1;

  private:
    void copy(const HopLimitTagBase& other);

  protected:
    bool operator==(const HopLimitTagBase&) = delete;

  public:
    HopLimitTagBase();
    HopLimitTagBase(const HopLimitTagBase& other);
    virtual ~HopLimitTagBase();
    HopLimitTagBase& operator=(const HopLimitTagBase& other);
    virtual HopLimitTagBase *dup() const override {return new HopLimitTagBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getHopLimit() const;
    virtual void setHopLimit(int hopLimit);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const HopLimitTagBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, HopLimitTagBase& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/common/HopLimitTag.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // Determines the initial hop count (time to live, ttl) for an outgoing packet.
 * //
 * class HopLimitReq extends HopLimitTagBase
 * {
 * }
 * </pre>
 */
class INET_API HopLimitReq : public ::inet::HopLimitTagBase
{
  protected:

  private:
    void copy(const HopLimitReq& other);

  protected:
    bool operator==(const HopLimitReq&) = delete;

  public:
    HopLimitReq();
    HopLimitReq(const HopLimitReq& other);
    virtual ~HopLimitReq();
    HopLimitReq& operator=(const HopLimitReq& other);
    virtual HopLimitReq *dup() const override {return new HopLimitReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const HopLimitReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, HopLimitReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/common/HopLimitTag.msg:26</tt> by nedtool.
 * <pre>
 * //
 * // Specifies the remainder hop count (time to live, ttl) for an incoming packet.
 * //
 * class HopLimitInd extends HopLimitTagBase
 * {
 * }
 * </pre>
 */
class INET_API HopLimitInd : public ::inet::HopLimitTagBase
{
  protected:

  private:
    void copy(const HopLimitInd& other);

  protected:
    bool operator==(const HopLimitInd&) = delete;

  public:
    HopLimitInd();
    HopLimitInd(const HopLimitInd& other);
    virtual ~HopLimitInd();
    HopLimitInd& operator=(const HopLimitInd& other);
    virtual HopLimitInd *dup() const override {return new HopLimitInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const HopLimitInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, HopLimitInd& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_HOPLIMITTAG_M_H

