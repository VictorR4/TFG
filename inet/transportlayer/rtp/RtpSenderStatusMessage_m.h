//
// Generated file, do not edit! Created by nedtool 6.0 from inet/transportlayer/rtp/RtpSenderStatusMessage.msg.
//

#ifndef __INET__RTP_RTPSENDERSTATUSMESSAGE_M_H
#define __INET__RTP_RTPSENDERSTATUSMESSAGE_M_H

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
namespace rtp {

class RtpSenderStatusMessage;
} // namespace rtp
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs


namespace inet {
namespace rtp {

/**
 * Enum generated from <tt>inet/transportlayer/rtp/RtpSenderStatusMessage.msg:34</tt> by nedtool.
 * <pre>
 * //
 * // Messages of type ~RtpSenderStatusMessage are used to send information
 * // from an rtp sender module to the application. Within this class a status
 * // string is defined in which the information is stored. This can be "PLAYING",
 * // "STOPPED" or "FINISHED".
 * // If a message must provide more information than just a string, a new class
 * // defining this parameter can derived.
 * //
 * enum RtpSenderStatus
 * {
 *     RTP_SENDER_STATUS_PLAYING = 1;
 *     RTP_SENDER_STATUS_FINISHED = 2;
 *     RTP_SENDER_STATUS_STOPPED = 3;
 *     RTP_SENDER_STATUS_PAUSED = 4;
 * }
 * </pre>
 */
enum RtpSenderStatus {
    RTP_SENDER_STATUS_PLAYING = 1,
    RTP_SENDER_STATUS_FINISHED = 2,
    RTP_SENDER_STATUS_STOPPED = 3,
    RTP_SENDER_STATUS_PAUSED = 4
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const RtpSenderStatus& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, RtpSenderStatus& e) { int n; b->unpack(n); e = static_cast<RtpSenderStatus>(n); }

/**
 * Class generated from <tt>inet/transportlayer/rtp/RtpSenderStatusMessage.msg:42</tt> by nedtool.
 * <pre>
 * packet RtpSenderStatusMessage
 * {
 *     RtpSenderStatus status;
 *     uint32_t timeStamp;
 * }
 * </pre>
 */
class INET_API RtpSenderStatusMessage : public ::omnetpp::cPacket
{
  protected:
    inet::rtp::RtpSenderStatus status = static_cast<inet::rtp::RtpSenderStatus>(-1);
    uint32_t timeStamp = 0;

  private:
    void copy(const RtpSenderStatusMessage& other);

  protected:
    bool operator==(const RtpSenderStatusMessage&) = delete;

  public:
    RtpSenderStatusMessage(const char *name=nullptr, short kind=0);
    RtpSenderStatusMessage(const RtpSenderStatusMessage& other);
    virtual ~RtpSenderStatusMessage();
    RtpSenderStatusMessage& operator=(const RtpSenderStatusMessage& other);
    virtual RtpSenderStatusMessage *dup() const override {return new RtpSenderStatusMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual inet::rtp::RtpSenderStatus getStatus() const;
    virtual void setStatus(inet::rtp::RtpSenderStatus status);
    virtual uint32_t getTimeStamp() const;
    virtual void setTimeStamp(uint32_t timeStamp);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const RtpSenderStatusMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, RtpSenderStatusMessage& obj) {obj.parsimUnpack(b);}

} // namespace rtp
} // namespace inet

#endif // ifndef __INET__RTP_RTPSENDERSTATUSMESSAGE_M_H

