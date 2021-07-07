//
// Generated file, do not edit! Created by nedtool 6.0 from inet/networklayer/rsvpte/SignallingMsg.msg.
//

#ifndef __INET_SIGNALLINGMSG_M_H
#define __INET_SIGNALLINGMSG_M_H

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

class SignallingMsg;
class PsbTimerMsg;
class PsbTimeoutMsg;
class RsbRefreshTimerMsg;
class RsbCommitTimerMsg;
class RsbTimeoutMsg;
class HelloTimerMsg;
class HelloTimeoutMsg;
class PathNotifyMsg;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/networklayer/contract/ipv4/Ipv4Address_m.h" // import inet.networklayer.contract.ipv4.Ipv4Address

#include "inet/networklayer/rsvpte/IntServ_m.h" // import inet.networklayer.rsvpte.IntServ


namespace inet {

/**
 * Enum generated from <tt>inet/networklayer/rsvpte/SignallingMsg.msg:22</tt> by nedtool.
 * <pre>
 * enum SignallingConstants
 * {
 *     MSG_PSB_TIMER = 1;
 *     MSG_PSB_TIMEOUT = 2;
 * 
 *     MSG_RSB_REFRESH_TIMER = 3;
 *     MSG_RSB_COMMIT_TIMER = 4;
 *     MSG_RSB_TIMEOUT = 5;
 * 
 *     MSG_HELLO_TIMER = 6;
 *     MSG_HELLO_TIMEOUT = 7;
 * 
 *     MSG_PATH_NOTIFY = 8;
 * 
 *     PATH_CREATED = 1;
 *     PATH_UNFEASIBLE = 2;
 *     PATH_FAILED = 3;
 *     PATH_PREEMPTED = 4;
 *     PATH_RETRY = 5;
 * }
 * </pre>
 */
enum SignallingConstants {
    MSG_PSB_TIMER = 1,
    MSG_PSB_TIMEOUT = 2,
    MSG_RSB_REFRESH_TIMER = 3,
    MSG_RSB_COMMIT_TIMER = 4,
    MSG_RSB_TIMEOUT = 5,
    MSG_HELLO_TIMER = 6,
    MSG_HELLO_TIMEOUT = 7,
    MSG_PATH_NOTIFY = 8,
    PATH_CREATED = 1,
    PATH_UNFEASIBLE = 2,
    PATH_FAILED = 3,
    PATH_PREEMPTED = 4,
    PATH_RETRY = 5
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SignallingConstants& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SignallingConstants& e) { int n; b->unpack(n); e = static_cast<SignallingConstants>(n); }

/**
 * Class generated from <tt>inet/networklayer/rsvpte/SignallingMsg.msg:46</tt> by nedtool.
 * <pre>
 * //
 * // FIXME missing documentation
 * //
 * message SignallingMsg
 * {
 *     int command = 0;
 * }
 * </pre>
 */
class INET_API SignallingMsg : public ::omnetpp::cMessage
{
  protected:
    int command = 0;

  private:
    void copy(const SignallingMsg& other);

  protected:
    bool operator==(const SignallingMsg&) = delete;

  public:
    SignallingMsg(const char *name=nullptr, short kind=0);
    SignallingMsg(const SignallingMsg& other);
    virtual ~SignallingMsg();
    SignallingMsg& operator=(const SignallingMsg& other);
    virtual SignallingMsg *dup() const override {return new SignallingMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getCommand() const;
    virtual void setCommand(int command);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const SignallingMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, SignallingMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/rsvpte/SignallingMsg.msg:54</tt> by nedtool.
 * <pre>
 * //
 * // FIXME missing documentation
 * //
 * message PsbTimerMsg extends SignallingMsg
 * {
 *     int id;
 * 
 *     command = MSG_PSB_TIMER;
 * }
 * </pre>
 */
class INET_API PsbTimerMsg : public ::inet::SignallingMsg
{
  protected:
    int id = 0;

  private:
    void copy(const PsbTimerMsg& other);

  protected:
    bool operator==(const PsbTimerMsg&) = delete;

  public:
    PsbTimerMsg(const char *name=nullptr, short kind=0);
    PsbTimerMsg(const PsbTimerMsg& other);
    virtual ~PsbTimerMsg();
    PsbTimerMsg& operator=(const PsbTimerMsg& other);
    virtual PsbTimerMsg *dup() const override {return new PsbTimerMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getId() const;
    virtual void setId(int id);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const PsbTimerMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, PsbTimerMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/rsvpte/SignallingMsg.msg:64</tt> by nedtool.
 * <pre>
 * //
 * // FIXME missing documentation
 * //
 * message PsbTimeoutMsg extends SignallingMsg
 * {
 *     int id;
 * 
 *     command = MSG_PSB_TIMEOUT;
 * }
 * </pre>
 */
class INET_API PsbTimeoutMsg : public ::inet::SignallingMsg
{
  protected:
    int id = 0;

  private:
    void copy(const PsbTimeoutMsg& other);

  protected:
    bool operator==(const PsbTimeoutMsg&) = delete;

  public:
    PsbTimeoutMsg(const char *name=nullptr, short kind=0);
    PsbTimeoutMsg(const PsbTimeoutMsg& other);
    virtual ~PsbTimeoutMsg();
    PsbTimeoutMsg& operator=(const PsbTimeoutMsg& other);
    virtual PsbTimeoutMsg *dup() const override {return new PsbTimeoutMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getId() const;
    virtual void setId(int id);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const PsbTimeoutMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, PsbTimeoutMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/rsvpte/SignallingMsg.msg:74</tt> by nedtool.
 * <pre>
 * //
 * // FIXME missing documentation
 * //
 * message RsbRefreshTimerMsg extends SignallingMsg
 * {
 *     int id;
 * 
 *     command = MSG_RSB_REFRESH_TIMER;
 * }
 * </pre>
 */
class INET_API RsbRefreshTimerMsg : public ::inet::SignallingMsg
{
  protected:
    int id = 0;

  private:
    void copy(const RsbRefreshTimerMsg& other);

  protected:
    bool operator==(const RsbRefreshTimerMsg&) = delete;

  public:
    RsbRefreshTimerMsg(const char *name=nullptr, short kind=0);
    RsbRefreshTimerMsg(const RsbRefreshTimerMsg& other);
    virtual ~RsbRefreshTimerMsg();
    RsbRefreshTimerMsg& operator=(const RsbRefreshTimerMsg& other);
    virtual RsbRefreshTimerMsg *dup() const override {return new RsbRefreshTimerMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getId() const;
    virtual void setId(int id);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const RsbRefreshTimerMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, RsbRefreshTimerMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/rsvpte/SignallingMsg.msg:84</tt> by nedtool.
 * <pre>
 * //
 * // FIXME missing documentation
 * //
 * message RsbCommitTimerMsg extends SignallingMsg
 * {
 *     int id;
 * 
 *     command = MSG_RSB_COMMIT_TIMER;
 * }
 * </pre>
 */
class INET_API RsbCommitTimerMsg : public ::inet::SignallingMsg
{
  protected:
    int id = 0;

  private:
    void copy(const RsbCommitTimerMsg& other);

  protected:
    bool operator==(const RsbCommitTimerMsg&) = delete;

  public:
    RsbCommitTimerMsg(const char *name=nullptr, short kind=0);
    RsbCommitTimerMsg(const RsbCommitTimerMsg& other);
    virtual ~RsbCommitTimerMsg();
    RsbCommitTimerMsg& operator=(const RsbCommitTimerMsg& other);
    virtual RsbCommitTimerMsg *dup() const override {return new RsbCommitTimerMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getId() const;
    virtual void setId(int id);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const RsbCommitTimerMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, RsbCommitTimerMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/rsvpte/SignallingMsg.msg:94</tt> by nedtool.
 * <pre>
 * //
 * // FIXME missing documentation
 * //
 * message RsbTimeoutMsg extends SignallingMsg
 * {
 *     int id;
 * 
 *     command = MSG_RSB_TIMEOUT;
 * }
 * </pre>
 */
class INET_API RsbTimeoutMsg : public ::inet::SignallingMsg
{
  protected:
    int id = 0;

  private:
    void copy(const RsbTimeoutMsg& other);

  protected:
    bool operator==(const RsbTimeoutMsg&) = delete;

  public:
    RsbTimeoutMsg(const char *name=nullptr, short kind=0);
    RsbTimeoutMsg(const RsbTimeoutMsg& other);
    virtual ~RsbTimeoutMsg();
    RsbTimeoutMsg& operator=(const RsbTimeoutMsg& other);
    virtual RsbTimeoutMsg *dup() const override {return new RsbTimeoutMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getId() const;
    virtual void setId(int id);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const RsbTimeoutMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, RsbTimeoutMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/rsvpte/SignallingMsg.msg:104</tt> by nedtool.
 * <pre>
 * //
 * // FIXME missing documentation
 * //
 * message HelloTimerMsg extends SignallingMsg
 * {
 *     Ipv4Address peer;
 * 
 *     command = MSG_HELLO_TIMER;
 * }
 * </pre>
 */
class INET_API HelloTimerMsg : public ::inet::SignallingMsg
{
  protected:
    Ipv4Address peer;

  private:
    void copy(const HelloTimerMsg& other);

  protected:
    bool operator==(const HelloTimerMsg&) = delete;

  public:
    HelloTimerMsg(const char *name=nullptr, short kind=0);
    HelloTimerMsg(const HelloTimerMsg& other);
    virtual ~HelloTimerMsg();
    HelloTimerMsg& operator=(const HelloTimerMsg& other);
    virtual HelloTimerMsg *dup() const override {return new HelloTimerMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const Ipv4Address& getPeer() const;
    virtual Ipv4Address& getPeerForUpdate() { return const_cast<Ipv4Address&>(const_cast<HelloTimerMsg*>(this)->getPeer());}
    virtual void setPeer(const Ipv4Address& peer);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const HelloTimerMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, HelloTimerMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/rsvpte/SignallingMsg.msg:114</tt> by nedtool.
 * <pre>
 * //
 * // FIXME missing documentation
 * //
 * message HelloTimeoutMsg extends SignallingMsg
 * {
 *     Ipv4Address peer;
 * 
 *     command = MSG_HELLO_TIMEOUT;
 * }
 * </pre>
 */
class INET_API HelloTimeoutMsg : public ::inet::SignallingMsg
{
  protected:
    Ipv4Address peer;

  private:
    void copy(const HelloTimeoutMsg& other);

  protected:
    bool operator==(const HelloTimeoutMsg&) = delete;

  public:
    HelloTimeoutMsg(const char *name=nullptr, short kind=0);
    HelloTimeoutMsg(const HelloTimeoutMsg& other);
    virtual ~HelloTimeoutMsg();
    HelloTimeoutMsg& operator=(const HelloTimeoutMsg& other);
    virtual HelloTimeoutMsg *dup() const override {return new HelloTimeoutMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const Ipv4Address& getPeer() const;
    virtual Ipv4Address& getPeerForUpdate() { return const_cast<Ipv4Address&>(const_cast<HelloTimeoutMsg*>(this)->getPeer());}
    virtual void setPeer(const Ipv4Address& peer);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const HelloTimeoutMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, HelloTimeoutMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/rsvpte/SignallingMsg.msg:124</tt> by nedtool.
 * <pre>
 * //
 * // FIXME missing documentation
 * //
 * message PathNotifyMsg extends SignallingMsg
 * {
 *     SessionObj session;
 *     SenderTemplateObj sender;
 * 
 *     int status;
 * 
 *     command = MSG_PATH_NOTIFY;
 * }
 * </pre>
 */
class INET_API PathNotifyMsg : public ::inet::SignallingMsg
{
  protected:
    SessionObj session;
    SenderTemplateObj sender;
    int status = 0;

  private:
    void copy(const PathNotifyMsg& other);

  protected:
    bool operator==(const PathNotifyMsg&) = delete;

  public:
    PathNotifyMsg(const char *name=nullptr, short kind=0);
    PathNotifyMsg(const PathNotifyMsg& other);
    virtual ~PathNotifyMsg();
    PathNotifyMsg& operator=(const PathNotifyMsg& other);
    virtual PathNotifyMsg *dup() const override {return new PathNotifyMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const SessionObj& getSession() const;
    virtual SessionObj& getSessionForUpdate() { return const_cast<SessionObj&>(const_cast<PathNotifyMsg*>(this)->getSession());}
    virtual void setSession(const SessionObj& session);
    virtual const SenderTemplateObj& getSender() const;
    virtual SenderTemplateObj& getSenderForUpdate() { return const_cast<SenderTemplateObj&>(const_cast<PathNotifyMsg*>(this)->getSender());}
    virtual void setSender(const SenderTemplateObj& sender);
    virtual int getStatus() const;
    virtual void setStatus(int status);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const PathNotifyMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, PathNotifyMsg& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_SIGNALLINGMSG_M_H

