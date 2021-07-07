//
// Generated file, do not edit! Created by nedtool 6.0 from inet/linklayer/common/UserPriorityTag.msg.
//

#ifndef __INET_USERPRIORITYTAG_M_H
#define __INET_USERPRIORITYTAG_M_H

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

class UserPriorityTagBase;
class UserPriorityReq;
class UserPriorityInd;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/TagBase_m.h" // import inet.common.TagBase


namespace inet {

/**
 * Class generated from <tt>inet/linklayer/common/UserPriorityTag.msg:14</tt> by nedtool.
 * <pre>
 * //
 * // This is an abstract base class that should not be directly added as a tag.
 * //
 * class UserPriorityTagBase extends TagBase
 * {
 *     int userPriority = -1; // value is in the range of [0, 7]
 * }
 * </pre>
 */
class INET_API UserPriorityTagBase : public ::inet::TagBase
{
  protected:
    int userPriority = -1;

  private:
    void copy(const UserPriorityTagBase& other);

  protected:
    bool operator==(const UserPriorityTagBase&) = delete;

  public:
    UserPriorityTagBase();
    UserPriorityTagBase(const UserPriorityTagBase& other);
    virtual ~UserPriorityTagBase();
    UserPriorityTagBase& operator=(const UserPriorityTagBase& other);
    virtual UserPriorityTagBase *dup() const override {return new UserPriorityTagBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getUserPriority() const;
    virtual void setUserPriority(int userPriority);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const UserPriorityTagBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, UserPriorityTagBase& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/common/UserPriorityTag.msg:23</tt> by nedtool.
 * <pre>
 * //
 * // This request determines the user priority that should be used to send the packet.
 * // It may be present on a packet from the application to the mac protocol.
 * //
 * class UserPriorityReq extends UserPriorityTagBase
 * {
 * }
 * </pre>
 */
class INET_API UserPriorityReq : public ::inet::UserPriorityTagBase
{
  protected:

  private:
    void copy(const UserPriorityReq& other);

  protected:
    bool operator==(const UserPriorityReq&) = delete;

  public:
    UserPriorityReq();
    UserPriorityReq(const UserPriorityReq& other);
    virtual ~UserPriorityReq();
    UserPriorityReq& operator=(const UserPriorityReq& other);
    virtual UserPriorityReq *dup() const override {return new UserPriorityReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const UserPriorityReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, UserPriorityReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/common/UserPriorityTag.msg:31</tt> by nedtool.
 * <pre>
 * //
 * // This indication specifies the user priority that was used to receive the packet.
 * // It may be present on a packet from the mac protocol to the application.
 * //
 * class UserPriorityInd extends UserPriorityTagBase
 * {
 * }
 * </pre>
 */
class INET_API UserPriorityInd : public ::inet::UserPriorityTagBase
{
  protected:

  private:
    void copy(const UserPriorityInd& other);

  protected:
    bool operator==(const UserPriorityInd&) = delete;

  public:
    UserPriorityInd();
    UserPriorityInd(const UserPriorityInd& other);
    virtual ~UserPriorityInd();
    UserPriorityInd& operator=(const UserPriorityInd& other);
    virtual UserPriorityInd *dup() const override {return new UserPriorityInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const UserPriorityInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, UserPriorityInd& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_USERPRIORITYTAG_M_H

