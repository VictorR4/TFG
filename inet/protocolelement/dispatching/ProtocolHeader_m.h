//
// Generated file, do not edit! Created by nedtool 6.0 from inet/protocolelement/dispatching/ProtocolHeader.msg.
//

#ifndef __INET_PROTOCOLHEADER_M_H
#define __INET_PROTOCOLHEADER_M_H

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

class ProtocolHeader;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk


namespace inet {

/**
 * Class generated from <tt>inet/protocolelement/dispatching/ProtocolHeader.msg:24</tt> by nedtool.
 * <pre>
 * class ProtocolHeader extends FieldsChunk
 * {
 *     chunkLength = B(2);
 *     int protocolId;
 * }
 * </pre>
 */
class INET_API ProtocolHeader : public ::inet::FieldsChunk
{
  protected:
    int protocolId = 0;

  private:
    void copy(const ProtocolHeader& other);

  protected:
    bool operator==(const ProtocolHeader&) = delete;

  public:
    ProtocolHeader();
    ProtocolHeader(const ProtocolHeader& other);
    virtual ~ProtocolHeader();
    ProtocolHeader& operator=(const ProtocolHeader& other);
    virtual ProtocolHeader *dup() const override {return new ProtocolHeader(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getProtocolId() const;
    virtual void setProtocolId(int protocolId);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const ProtocolHeader& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, ProtocolHeader& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_PROTOCOLHEADER_M_H

