//
// Generated file, do not edit! Created by nedtool 6.0 from inet/linklayer/csmaca/CsmaCaMacHeader.msg.
//

#ifndef __INET_CSMACAMACHEADER_M_H
#define __INET_CSMACAMACHEADER_M_H

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

class CsmaCaMacHeader;
class CsmaCaMacAckHeader;
class CsmaCaMacDataHeader;
class CsmaCaMacTrailer;
} // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk

#include "inet/linklayer/common/FcsMode_m.h" // import inet.linklayer.common.FcsMode

#include "inet/linklayer/common/MacAddress_m.h" // import inet.linklayer.common.MacAddress


namespace inet {

/**
 * Enum generated from <tt>inet/linklayer/csmaca/CsmaCaMacHeader.msg:25</tt> by nedtool.
 * <pre>
 * enum CsmaCaMacHeaderType
 * {
 *     CSMA_DATA = 1;
 *     CSMA_ACK = 2;
 * }
 * </pre>
 */
enum CsmaCaMacHeaderType {
    CSMA_DATA = 1,
    CSMA_ACK = 2
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const CsmaCaMacHeaderType& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, CsmaCaMacHeaderType& e) { int n; b->unpack(n); e = static_cast<CsmaCaMacHeaderType>(n); }

/**
 * Class generated from <tt>inet/linklayer/csmaca/CsmaCaMacHeader.msg:31</tt> by nedtool.
 * <pre>
 * class CsmaCaMacHeader extends FieldsChunk
 * {
 *     CsmaCaMacHeaderType type;    // header type (1 byte)
 *     uint8_t headerLengthField;    // header length in bytes, max value is 255 (1 byte)
 *     MacAddress transmitterAddress;    // (6 byte)
 *     MacAddress receiverAddress;    // (6 byte)
 * }
 * </pre>
 */
class INET_API CsmaCaMacHeader : public ::inet::FieldsChunk
{
  protected:
    inet::CsmaCaMacHeaderType type = static_cast<inet::CsmaCaMacHeaderType>(-1);
    uint8_t headerLengthField = 0;
    MacAddress transmitterAddress;
    MacAddress receiverAddress;

  private:
    void copy(const CsmaCaMacHeader& other);

  protected:
    bool operator==(const CsmaCaMacHeader&) = delete;

  public:
    CsmaCaMacHeader();
    CsmaCaMacHeader(const CsmaCaMacHeader& other);
    virtual ~CsmaCaMacHeader();
    CsmaCaMacHeader& operator=(const CsmaCaMacHeader& other);
    virtual CsmaCaMacHeader *dup() const override {return new CsmaCaMacHeader(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual inet::CsmaCaMacHeaderType getType() const;
    virtual void setType(inet::CsmaCaMacHeaderType type);
    virtual uint8_t getHeaderLengthField() const;
    virtual void setHeaderLengthField(uint8_t headerLengthField);
    virtual const MacAddress& getTransmitterAddress() const;
    virtual MacAddress& getTransmitterAddressForUpdate() { handleChange();return const_cast<MacAddress&>(const_cast<CsmaCaMacHeader*>(this)->getTransmitterAddress());}
    virtual void setTransmitterAddress(const MacAddress& transmitterAddress);
    virtual const MacAddress& getReceiverAddress() const;
    virtual MacAddress& getReceiverAddressForUpdate() { handleChange();return const_cast<MacAddress&>(const_cast<CsmaCaMacHeader*>(this)->getReceiverAddress());}
    virtual void setReceiverAddress(const MacAddress& receiverAddress);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const CsmaCaMacHeader& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, CsmaCaMacHeader& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/csmaca/CsmaCaMacHeader.msg:39</tt> by nedtool.
 * <pre>
 * class CsmaCaMacAckHeader extends CsmaCaMacHeader
 * {
 *     chunkLength = B(14);
 *     type = CSMA_ACK;
 * }
 * </pre>
 */
class INET_API CsmaCaMacAckHeader : public ::inet::CsmaCaMacHeader
{
  protected:

  private:
    void copy(const CsmaCaMacAckHeader& other);

  protected:
    bool operator==(const CsmaCaMacAckHeader&) = delete;

  public:
    CsmaCaMacAckHeader();
    CsmaCaMacAckHeader(const CsmaCaMacAckHeader& other);
    virtual ~CsmaCaMacAckHeader();
    CsmaCaMacAckHeader& operator=(const CsmaCaMacAckHeader& other);
    virtual CsmaCaMacAckHeader *dup() const override {return new CsmaCaMacAckHeader(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const CsmaCaMacAckHeader& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, CsmaCaMacAckHeader& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/csmaca/CsmaCaMacHeader.msg:45</tt> by nedtool.
 * <pre>
 * class CsmaCaMacDataHeader extends CsmaCaMacHeader
 * {
 *     chunkLength = B(17);
 *     type = CSMA_DATA;
 *     int networkProtocol = -1;    // ethernet protocol ID (2 bytes)
 *     int priority = -1;    // 802.1d UP (User Priority) (1 byte)
 * }
 * </pre>
 */
class INET_API CsmaCaMacDataHeader : public ::inet::CsmaCaMacHeader
{
  protected:
    int networkProtocol = -1;
    int priority = -1;

  private:
    void copy(const CsmaCaMacDataHeader& other);

  protected:
    bool operator==(const CsmaCaMacDataHeader&) = delete;

  public:
    CsmaCaMacDataHeader();
    CsmaCaMacDataHeader(const CsmaCaMacDataHeader& other);
    virtual ~CsmaCaMacDataHeader();
    CsmaCaMacDataHeader& operator=(const CsmaCaMacDataHeader& other);
    virtual CsmaCaMacDataHeader *dup() const override {return new CsmaCaMacDataHeader(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getNetworkProtocol() const;
    virtual void setNetworkProtocol(int networkProtocol);
    virtual int getPriority() const;
    virtual void setPriority(int priority);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const CsmaCaMacDataHeader& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, CsmaCaMacDataHeader& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/linklayer/csmaca/CsmaCaMacHeader.msg:53</tt> by nedtool.
 * <pre>
 * class CsmaCaMacTrailer extends FieldsChunk
 * {
 *     chunkLength = B(4);
 *     uint32_t fcs = 0;
 *     FcsMode fcsMode = FCS_MODE_UNDEFINED;
 * }
 * </pre>
 */
class INET_API CsmaCaMacTrailer : public ::inet::FieldsChunk
{
  protected:
    uint32_t fcs = 0;
    inet::FcsMode fcsMode = FCS_MODE_UNDEFINED;

  private:
    void copy(const CsmaCaMacTrailer& other);

  protected:
    bool operator==(const CsmaCaMacTrailer&) = delete;

  public:
    CsmaCaMacTrailer();
    CsmaCaMacTrailer(const CsmaCaMacTrailer& other);
    virtual ~CsmaCaMacTrailer();
    CsmaCaMacTrailer& operator=(const CsmaCaMacTrailer& other);
    virtual CsmaCaMacTrailer *dup() const override {return new CsmaCaMacTrailer(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint32_t getFcs() const;
    virtual void setFcs(uint32_t fcs);
    virtual inet::FcsMode getFcsMode() const;
    virtual void setFcsMode(inet::FcsMode fcsMode);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const CsmaCaMacTrailer& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, CsmaCaMacTrailer& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_CSMACAMACHEADER_M_H

