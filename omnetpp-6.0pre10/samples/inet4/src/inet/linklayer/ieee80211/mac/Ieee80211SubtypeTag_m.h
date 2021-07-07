//
// Generated file, do not edit! Created by nedtool 6.0 from inet/linklayer/ieee80211/mac/Ieee80211SubtypeTag.msg.
//

#ifndef __INET_IEEE80211SUBTYPETAG_M_H
#define __INET_IEEE80211SUBTYPETAG_M_H

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

class Ieee80211SubtypeTagBase;
class Ieee80211SubtypeReq;
class Ieee80211SubtypeInd;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/TagBase_m.h" // import inet.common.TagBase


namespace inet {

/**
 * Class generated from <tt>inet/linklayer/ieee80211/mac/Ieee80211SubtypeTag.msg:11</tt> by nedtool.
 * <pre>
 * class Ieee80211SubtypeTagBase extends TagBase
 * {
 *     int subtype;
 * }
 * </pre>
 */
class INET_API Ieee80211SubtypeTagBase : public ::inet::TagBase
{
  protected:
    int subtype = 0;

  private:
    void copy(const Ieee80211SubtypeTagBase& other);

  protected:
    bool operator==(const Ieee80211SubtypeTagBase&) = delete;

  public:
    Ieee80211SubtypeTagBase();
    Ieee80211SubtypeTagBase(const Ieee80211SubtypeTagBase& other);
    virtual ~Ieee80211SubtypeTagBase();
    Ieee80211SubtypeTagBase& operator=(const Ieee80211SubtypeTagBase& other);
    virtual Ieee80211SubtypeTagBase *dup() const override {return new Ieee80211SubtypeTagBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getSubtype() const;
    virtual void setSubtype(int subtype);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ieee80211SubtypeTagBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ieee80211SubtypeTagBase& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/ieee80211/mac/Ieee80211SubtypeTag.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // Determines the MAC header subtype for an outgoing packet.
 * //
 * class Ieee80211SubtypeReq extends Ieee80211SubtypeTagBase
 * {
 * }
 * </pre>
 */
class INET_API Ieee80211SubtypeReq : public ::inet::Ieee80211SubtypeTagBase
{
  protected:

  private:
    void copy(const Ieee80211SubtypeReq& other);

  protected:
    bool operator==(const Ieee80211SubtypeReq&) = delete;

  public:
    Ieee80211SubtypeReq();
    Ieee80211SubtypeReq(const Ieee80211SubtypeReq& other);
    virtual ~Ieee80211SubtypeReq();
    Ieee80211SubtypeReq& operator=(const Ieee80211SubtypeReq& other);
    virtual Ieee80211SubtypeReq *dup() const override {return new Ieee80211SubtypeReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ieee80211SubtypeReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ieee80211SubtypeReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/ieee80211/mac/Ieee80211SubtypeTag.msg:26</tt> by nedtool.
 * <pre>
 * //
 * // Specifies the MAC header subtype for an incoming packet.
 * //
 * class Ieee80211SubtypeInd extends Ieee80211SubtypeTagBase
 * {
 * }
 * </pre>
 */
class INET_API Ieee80211SubtypeInd : public ::inet::Ieee80211SubtypeTagBase
{
  protected:

  private:
    void copy(const Ieee80211SubtypeInd& other);

  protected:
    bool operator==(const Ieee80211SubtypeInd&) = delete;

  public:
    Ieee80211SubtypeInd();
    Ieee80211SubtypeInd(const Ieee80211SubtypeInd& other);
    virtual ~Ieee80211SubtypeInd();
    Ieee80211SubtypeInd& operator=(const Ieee80211SubtypeInd& other);
    virtual Ieee80211SubtypeInd *dup() const override {return new Ieee80211SubtypeInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ieee80211SubtypeInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ieee80211SubtypeInd& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_IEEE80211SUBTYPETAG_M_H

