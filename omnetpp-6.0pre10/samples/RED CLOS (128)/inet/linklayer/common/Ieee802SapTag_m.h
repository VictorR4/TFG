//
// Generated file, do not edit! Created by nedtool 6.0 from inet/linklayer/common/Ieee802SapTag.msg.
//

#ifndef __INET_IEEE802SAPTAG_M_H
#define __INET_IEEE802SAPTAG_M_H

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

class Ieee802SapTagBase;
class Ieee802SapReq;
class Ieee802SapInd;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/TagBase_m.h" // import inet.common.TagBase


namespace inet {

/**
 * Enum generated from <tt>inet/linklayer/common/Ieee802SapTag.msg:14</tt> by nedtool.
 * <pre>
 * //
 * // Some 8-bit SAP values for IEEE 802.x LLC headers.
 * //
 * enum SapCode
 * {
 *     SAP_IBM_SNA = 0x04;
 *     SAP_IP = 0x06;
 *     SAP_3COM = 0x80;
 *     SAP_SNAP = 0xAA;
 *     SAP_BANYAN = 0xBC;
 *     SAP_NOVELL_IPX = 0xE0;
 *     SAP_LAN_MANAGER = 0xF4;
 *     SAP_CLNS = 0xFE;
 *     SAP_STP = 0x42;
 * }
 * </pre>
 */
enum SapCode {
    SAP_IBM_SNA = 0x04,
    SAP_IP = 0x06,
    SAP_3COM = 0x80,
    SAP_SNAP = 0xAA,
    SAP_BANYAN = 0xBC,
    SAP_NOVELL_IPX = 0xE0,
    SAP_LAN_MANAGER = 0xF4,
    SAP_CLNS = 0xFE,
    SAP_STP = 0x42
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SapCode& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SapCode& e) { int n; b->unpack(n); e = static_cast<SapCode>(n); }

/**
 * Class generated from <tt>inet/linklayer/common/Ieee802SapTag.msg:27</tt> by nedtool.
 * <pre>
 * class Ieee802SapTagBase extends TagBase
 * {
 *     int ssap;        // used with IEEE 802 LLC (see ~EtherFrameWithLlc)
 *     int dsap;        // used with IEEE 802 LLC (see ~EtherFrameWithLlc)
 * }
 * </pre>
 */
class INET_API Ieee802SapTagBase : public ::inet::TagBase
{
  protected:
    int ssap = 0;
    int dsap = 0;

  private:
    void copy(const Ieee802SapTagBase& other);

  protected:
    bool operator==(const Ieee802SapTagBase&) = delete;

  public:
    Ieee802SapTagBase();
    Ieee802SapTagBase(const Ieee802SapTagBase& other);
    virtual ~Ieee802SapTagBase();
    Ieee802SapTagBase& operator=(const Ieee802SapTagBase& other);
    virtual Ieee802SapTagBase *dup() const override {return new Ieee802SapTagBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getSsap() const;
    virtual void setSsap(int ssap);
    virtual int getDsap() const;
    virtual void setDsap(int dsap);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ieee802SapTagBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ieee802SapTagBase& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/common/Ieee802SapTag.msg:33</tt> by nedtool.
 * <pre>
 * class Ieee802SapReq extends Ieee802SapTagBase
 * {
 * }
 * </pre>
 */
class INET_API Ieee802SapReq : public ::inet::Ieee802SapTagBase
{
  protected:

  private:
    void copy(const Ieee802SapReq& other);

  protected:
    bool operator==(const Ieee802SapReq&) = delete;

  public:
    Ieee802SapReq();
    Ieee802SapReq(const Ieee802SapReq& other);
    virtual ~Ieee802SapReq();
    Ieee802SapReq& operator=(const Ieee802SapReq& other);
    virtual Ieee802SapReq *dup() const override {return new Ieee802SapReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ieee802SapReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ieee802SapReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/common/Ieee802SapTag.msg:37</tt> by nedtool.
 * <pre>
 * class Ieee802SapInd extends Ieee802SapTagBase
 * {
 * }
 * </pre>
 */
class INET_API Ieee802SapInd : public ::inet::Ieee802SapTagBase
{
  protected:

  private:
    void copy(const Ieee802SapInd& other);

  protected:
    bool operator==(const Ieee802SapInd&) = delete;

  public:
    Ieee802SapInd();
    Ieee802SapInd(const Ieee802SapInd& other);
    virtual ~Ieee802SapInd();
    Ieee802SapInd& operator=(const Ieee802SapInd& other);
    virtual Ieee802SapInd *dup() const override {return new Ieee802SapInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ieee802SapInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ieee802SapInd& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_IEEE802SAPTAG_M_H

