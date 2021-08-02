//
// Generated file, do not edit! Created by nedtool 6.0 from inet/linklayer/common/VlanTag.msg.
//

#ifndef __INET_VLANTAG_M_H
#define __INET_VLANTAG_M_H

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

class VlanTagBase;
class VlanReq;
class VlanInd;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/TagBase_m.h" // import inet.common.TagBase


namespace inet {

/**
 * Class generated from <tt>inet/linklayer/common/VlanTag.msg:27</tt> by nedtool.
 * <pre>
 * //
 * // This is an abstract base class that should not be directly added as a tag.
 * //
 * class VlanTagBase extends TagBase
 * {
 *     int vlanId = -1;
 * }
 * </pre>
 */
class INET_API VlanTagBase : public ::inet::TagBase
{
  protected:
    int vlanId = -1;

  private:
    void copy(const VlanTagBase& other);

  protected:
    bool operator==(const VlanTagBase&) = delete;

  public:
    VlanTagBase();
    VlanTagBase(const VlanTagBase& other);
    virtual ~VlanTagBase();
    VlanTagBase& operator=(const VlanTagBase& other);
    virtual VlanTagBase *dup() const override {return new VlanTagBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getVlanId() const;
    virtual void setVlanId(int vlanId);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const VlanTagBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, VlanTagBase& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/common/VlanTag.msg:36</tt> by nedtool.
 * <pre>
 * //
 * // This request determines the vlan that should be used to send the packet.
 * // It may be present on a packet from the application to the mac protocol.
 * //
 * class VlanReq extends VlanTagBase
 * {
 * }
 * </pre>
 */
class INET_API VlanReq : public ::inet::VlanTagBase
{
  protected:

  private:
    void copy(const VlanReq& other);

  protected:
    bool operator==(const VlanReq&) = delete;

  public:
    VlanReq();
    VlanReq(const VlanReq& other);
    virtual ~VlanReq();
    VlanReq& operator=(const VlanReq& other);
    virtual VlanReq *dup() const override {return new VlanReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const VlanReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, VlanReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/common/VlanTag.msg:44</tt> by nedtool.
 * <pre>
 * //
 * // This indication specifies the vlan that was used to receive the packet.
 * // It may be present on a packet from the mac protocol to the application.
 * //
 * class VlanInd extends VlanTagBase
 * {
 * }
 * </pre>
 */
class INET_API VlanInd : public ::inet::VlanTagBase
{
  protected:

  private:
    void copy(const VlanInd& other);

  protected:
    bool operator==(const VlanInd&) = delete;

  public:
    VlanInd();
    VlanInd(const VlanInd& other);
    virtual ~VlanInd();
    VlanInd& operator=(const VlanInd& other);
    virtual VlanInd *dup() const override {return new VlanInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const VlanInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, VlanInd& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_VLANTAG_M_H

