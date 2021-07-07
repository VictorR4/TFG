//
// Generated file, do not edit! Created by nedtool 6.0 from inet/routing/aodv/AodvControlPackets.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "AodvControlPackets_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace {
template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)(static_cast<const omnetpp::cObject *>(t));
}

template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && !std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)dynamic_cast<const void *>(t);
}

template <class T> inline
typename std::enable_if<!std::is_polymorphic<T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)static_cast<const void *>(t);
}

}

namespace inet {
namespace aodv {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule to generate operator<< for shared_ptr<T>
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const std::shared_ptr<T>& t) { return out << t.get(); }

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline typename std::enable_if<!std::is_base_of<omnetpp::cObject, T>::value, std::ostream&>::type
operator<<(std::ostream& out,const T&) {return out.operator<<(omnetpp::opp_typename(typeid(T)));}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');

    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::aodv::AodvControlPacketType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::aodv::AodvControlPacketType"));
    e->insert(RREQ, "RREQ");
    e->insert(RREP, "RREP");
    e->insert(RERR, "RERR");
    e->insert(RREPACK, "RREPACK");
    e->insert(RREQ_IPv6, "RREQ_IPv6");
    e->insert(RREP_IPv6, "RREP_IPv6");
    e->insert(RERR_IPv6, "RERR_IPv6");
    e->insert(RREPACK_IPv6, "RREPACK_IPv6");
)

Register_Class(AodvControlPacket)

AodvControlPacket::AodvControlPacket() : ::inet::FieldsChunk()
{
}

AodvControlPacket::AodvControlPacket(const AodvControlPacket& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

AodvControlPacket::~AodvControlPacket()
{
}

AodvControlPacket& AodvControlPacket::operator=(const AodvControlPacket& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void AodvControlPacket::copy(const AodvControlPacket& other)
{
    this->packetType = other.packetType;
}

void AodvControlPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->packetType);
}

void AodvControlPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->packetType);
}

inet::aodv::AodvControlPacketType AodvControlPacket::getPacketType() const
{
    return this->packetType;
}

void AodvControlPacket::setPacketType(inet::aodv::AodvControlPacketType packetType)
{
    handleChange();
    this->packetType = packetType;
}

class AodvControlPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_packetType,
    };
  public:
    AodvControlPacketDescriptor();
    virtual ~AodvControlPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(AodvControlPacketDescriptor)

AodvControlPacketDescriptor::AodvControlPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodv::AodvControlPacket)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

AodvControlPacketDescriptor::~AodvControlPacketDescriptor()
{
    delete[] propertynames;
}

bool AodvControlPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AodvControlPacket *>(obj)!=nullptr;
}

const char **AodvControlPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AodvControlPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AodvControlPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int AodvControlPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_packetType
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *AodvControlPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "packetType",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int AodvControlPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'p' && strcmp(fieldName, "packetType") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AodvControlPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::aodv::AodvControlPacketType",    // FIELD_packetType
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **AodvControlPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_packetType: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *AodvControlPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_packetType:
            if (!strcmp(propertyname, "enum")) return "inet::aodv::AodvControlPacketType";
            return nullptr;
        default: return nullptr;
    }
}

int AodvControlPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AodvControlPacket *pp = (AodvControlPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void AodvControlPacketDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    AodvControlPacket *pp = (AodvControlPacket *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'AodvControlPacket'", field);
    }
}

const char *AodvControlPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AodvControlPacket *pp = (AodvControlPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AodvControlPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AodvControlPacket *pp = (AodvControlPacket *)object; (void)pp;
    switch (field) {
        case FIELD_packetType: return enum2string(pp->getPacketType(), "inet::aodv::AodvControlPacketType");
        default: return "";
    }
}

void AodvControlPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    AodvControlPacket *pp = (AodvControlPacket *)object; (void)pp;
    switch (field) {
        case FIELD_packetType: pp->setPacketType((inet::aodv::AodvControlPacketType)string2enum(value, "inet::aodv::AodvControlPacketType")); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AodvControlPacket'", field);
    }
}

const char *AodvControlPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *AodvControlPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AodvControlPacket *pp = (AodvControlPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void AodvControlPacketDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    AodvControlPacket *pp = (AodvControlPacket *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AodvControlPacket'", field);
    }
}

Register_Class(Rreq)

Rreq::Rreq() : ::inet::aodv::AodvControlPacket()
{
}

Rreq::Rreq(const Rreq& other) : ::inet::aodv::AodvControlPacket(other)
{
    copy(other);
}

Rreq::~Rreq()
{
}

Rreq& Rreq::operator=(const Rreq& other)
{
    if (this == &other) return *this;
    ::inet::aodv::AodvControlPacket::operator=(other);
    copy(other);
    return *this;
}

void Rreq::copy(const Rreq& other)
{
    this->joinFlag = other.joinFlag;
    this->repairFlag = other.repairFlag;
    this->gratuitousRREPFlag = other.gratuitousRREPFlag;
    this->destOnlyFlag = other.destOnlyFlag;
    this->unknownSeqNumFlag = other.unknownSeqNumFlag;
    this->reserved = other.reserved;
    this->hopCount = other.hopCount;
    this->rreqId = other.rreqId;
    this->destAddr = other.destAddr;
    this->destSeqNum = other.destSeqNum;
    this->originatorAddr = other.originatorAddr;
    this->originatorSeqNum = other.originatorSeqNum;
}

void Rreq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::aodv::AodvControlPacket::parsimPack(b);
    doParsimPacking(b,this->joinFlag);
    doParsimPacking(b,this->repairFlag);
    doParsimPacking(b,this->gratuitousRREPFlag);
    doParsimPacking(b,this->destOnlyFlag);
    doParsimPacking(b,this->unknownSeqNumFlag);
    doParsimPacking(b,this->reserved);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->rreqId);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->destSeqNum);
    doParsimPacking(b,this->originatorAddr);
    doParsimPacking(b,this->originatorSeqNum);
}

void Rreq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::aodv::AodvControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->joinFlag);
    doParsimUnpacking(b,this->repairFlag);
    doParsimUnpacking(b,this->gratuitousRREPFlag);
    doParsimUnpacking(b,this->destOnlyFlag);
    doParsimUnpacking(b,this->unknownSeqNumFlag);
    doParsimUnpacking(b,this->reserved);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->rreqId);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->destSeqNum);
    doParsimUnpacking(b,this->originatorAddr);
    doParsimUnpacking(b,this->originatorSeqNum);
}

bool Rreq::getJoinFlag() const
{
    return this->joinFlag;
}

void Rreq::setJoinFlag(bool joinFlag)
{
    handleChange();
    this->joinFlag = joinFlag;
}

bool Rreq::getRepairFlag() const
{
    return this->repairFlag;
}

void Rreq::setRepairFlag(bool repairFlag)
{
    handleChange();
    this->repairFlag = repairFlag;
}

bool Rreq::getGratuitousRREPFlag() const
{
    return this->gratuitousRREPFlag;
}

void Rreq::setGratuitousRREPFlag(bool gratuitousRREPFlag)
{
    handleChange();
    this->gratuitousRREPFlag = gratuitousRREPFlag;
}

bool Rreq::getDestOnlyFlag() const
{
    return this->destOnlyFlag;
}

void Rreq::setDestOnlyFlag(bool destOnlyFlag)
{
    handleChange();
    this->destOnlyFlag = destOnlyFlag;
}

bool Rreq::getUnknownSeqNumFlag() const
{
    return this->unknownSeqNumFlag;
}

void Rreq::setUnknownSeqNumFlag(bool unknownSeqNumFlag)
{
    handleChange();
    this->unknownSeqNumFlag = unknownSeqNumFlag;
}

uint16_t Rreq::getReserved() const
{
    return this->reserved;
}

void Rreq::setReserved(uint16_t reserved)
{
    handleChange();
    this->reserved = reserved;
}

unsigned int Rreq::getHopCount() const
{
    return this->hopCount;
}

void Rreq::setHopCount(unsigned int hopCount)
{
    handleChange();
    this->hopCount = hopCount;
}

uint32_t Rreq::getRreqId() const
{
    return this->rreqId;
}

void Rreq::setRreqId(uint32_t rreqId)
{
    handleChange();
    this->rreqId = rreqId;
}

const L3Address& Rreq::getDestAddr() const
{
    return this->destAddr;
}

void Rreq::setDestAddr(const L3Address& destAddr)
{
    handleChange();
    this->destAddr = destAddr;
}

uint32_t Rreq::getDestSeqNum() const
{
    return this->destSeqNum;
}

void Rreq::setDestSeqNum(uint32_t destSeqNum)
{
    handleChange();
    this->destSeqNum = destSeqNum;
}

const L3Address& Rreq::getOriginatorAddr() const
{
    return this->originatorAddr;
}

void Rreq::setOriginatorAddr(const L3Address& originatorAddr)
{
    handleChange();
    this->originatorAddr = originatorAddr;
}

uint32_t Rreq::getOriginatorSeqNum() const
{
    return this->originatorSeqNum;
}

void Rreq::setOriginatorSeqNum(uint32_t originatorSeqNum)
{
    handleChange();
    this->originatorSeqNum = originatorSeqNum;
}

class RreqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_joinFlag,
        FIELD_repairFlag,
        FIELD_gratuitousRREPFlag,
        FIELD_destOnlyFlag,
        FIELD_unknownSeqNumFlag,
        FIELD_reserved,
        FIELD_hopCount,
        FIELD_rreqId,
        FIELD_destAddr,
        FIELD_destSeqNum,
        FIELD_originatorAddr,
        FIELD_originatorSeqNum,
    };
  public:
    RreqDescriptor();
    virtual ~RreqDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(RreqDescriptor)

RreqDescriptor::RreqDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodv::Rreq)), "inet::aodv::AodvControlPacket")
{
    propertynames = nullptr;
}

RreqDescriptor::~RreqDescriptor()
{
    delete[] propertynames;
}

bool RreqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Rreq *>(obj)!=nullptr;
}

const char **RreqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RreqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RreqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 12+basedesc->getFieldCount() : 12;
}

unsigned int RreqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_joinFlag
        FD_ISEDITABLE,    // FIELD_repairFlag
        FD_ISEDITABLE,    // FIELD_gratuitousRREPFlag
        FD_ISEDITABLE,    // FIELD_destOnlyFlag
        FD_ISEDITABLE,    // FIELD_unknownSeqNumFlag
        FD_ISEDITABLE,    // FIELD_reserved
        FD_ISEDITABLE,    // FIELD_hopCount
        FD_ISEDITABLE,    // FIELD_rreqId
        0,    // FIELD_destAddr
        FD_ISEDITABLE,    // FIELD_destSeqNum
        0,    // FIELD_originatorAddr
        FD_ISEDITABLE,    // FIELD_originatorSeqNum
    };
    return (field >= 0 && field < 12) ? fieldTypeFlags[field] : 0;
}

const char *RreqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "joinFlag",
        "repairFlag",
        "gratuitousRREPFlag",
        "destOnlyFlag",
        "unknownSeqNumFlag",
        "reserved",
        "hopCount",
        "rreqId",
        "destAddr",
        "destSeqNum",
        "originatorAddr",
        "originatorSeqNum",
    };
    return (field >= 0 && field < 12) ? fieldNames[field] : nullptr;
}

int RreqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'j' && strcmp(fieldName, "joinFlag") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "repairFlag") == 0) return base+1;
    if (fieldName[0] == 'g' && strcmp(fieldName, "gratuitousRREPFlag") == 0) return base+2;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destOnlyFlag") == 0) return base+3;
    if (fieldName[0] == 'u' && strcmp(fieldName, "unknownSeqNumFlag") == 0) return base+4;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reserved") == 0) return base+5;
    if (fieldName[0] == 'h' && strcmp(fieldName, "hopCount") == 0) return base+6;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rreqId") == 0) return base+7;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destAddr") == 0) return base+8;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destSeqNum") == 0) return base+9;
    if (fieldName[0] == 'o' && strcmp(fieldName, "originatorAddr") == 0) return base+10;
    if (fieldName[0] == 'o' && strcmp(fieldName, "originatorSeqNum") == 0) return base+11;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RreqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_joinFlag
        "bool",    // FIELD_repairFlag
        "bool",    // FIELD_gratuitousRREPFlag
        "bool",    // FIELD_destOnlyFlag
        "bool",    // FIELD_unknownSeqNumFlag
        "uint16_t",    // FIELD_reserved
        "unsigned int",    // FIELD_hopCount
        "uint32_t",    // FIELD_rreqId
        "inet::L3Address",    // FIELD_destAddr
        "uint32_t",    // FIELD_destSeqNum
        "inet::L3Address",    // FIELD_originatorAddr
        "uint32_t",    // FIELD_originatorSeqNum
    };
    return (field >= 0 && field < 12) ? fieldTypeStrings[field] : nullptr;
}

const char **RreqDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *RreqDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int RreqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Rreq *pp = (Rreq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void RreqDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Rreq *pp = (Rreq *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Rreq'", field);
    }
}

const char *RreqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Rreq *pp = (Rreq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RreqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Rreq *pp = (Rreq *)object; (void)pp;
    switch (field) {
        case FIELD_joinFlag: return bool2string(pp->getJoinFlag());
        case FIELD_repairFlag: return bool2string(pp->getRepairFlag());
        case FIELD_gratuitousRREPFlag: return bool2string(pp->getGratuitousRREPFlag());
        case FIELD_destOnlyFlag: return bool2string(pp->getDestOnlyFlag());
        case FIELD_unknownSeqNumFlag: return bool2string(pp->getUnknownSeqNumFlag());
        case FIELD_reserved: return ulong2string(pp->getReserved());
        case FIELD_hopCount: return ulong2string(pp->getHopCount());
        case FIELD_rreqId: return ulong2string(pp->getRreqId());
        case FIELD_destAddr: return pp->getDestAddr().str();
        case FIELD_destSeqNum: return ulong2string(pp->getDestSeqNum());
        case FIELD_originatorAddr: return pp->getOriginatorAddr().str();
        case FIELD_originatorSeqNum: return ulong2string(pp->getOriginatorSeqNum());
        default: return "";
    }
}

void RreqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Rreq *pp = (Rreq *)object; (void)pp;
    switch (field) {
        case FIELD_joinFlag: pp->setJoinFlag(string2bool(value)); break;
        case FIELD_repairFlag: pp->setRepairFlag(string2bool(value)); break;
        case FIELD_gratuitousRREPFlag: pp->setGratuitousRREPFlag(string2bool(value)); break;
        case FIELD_destOnlyFlag: pp->setDestOnlyFlag(string2bool(value)); break;
        case FIELD_unknownSeqNumFlag: pp->setUnknownSeqNumFlag(string2bool(value)); break;
        case FIELD_reserved: pp->setReserved(string2ulong(value)); break;
        case FIELD_hopCount: pp->setHopCount(string2ulong(value)); break;
        case FIELD_rreqId: pp->setRreqId(string2ulong(value)); break;
        case FIELD_destSeqNum: pp->setDestSeqNum(string2ulong(value)); break;
        case FIELD_originatorSeqNum: pp->setOriginatorSeqNum(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Rreq'", field);
    }
}

const char *RreqDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *RreqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Rreq *pp = (Rreq *)object; (void)pp;
    switch (field) {
        case FIELD_destAddr: return toVoidPtr(&pp->getDestAddr()); break;
        case FIELD_originatorAddr: return toVoidPtr(&pp->getOriginatorAddr()); break;
        default: return nullptr;
    }
}

void RreqDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Rreq *pp = (Rreq *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Rreq'", field);
    }
}

Register_Class(Rrep)

Rrep::Rrep() : ::inet::aodv::AodvControlPacket()
{
}

Rrep::Rrep(const Rrep& other) : ::inet::aodv::AodvControlPacket(other)
{
    copy(other);
}

Rrep::~Rrep()
{
}

Rrep& Rrep::operator=(const Rrep& other)
{
    if (this == &other) return *this;
    ::inet::aodv::AodvControlPacket::operator=(other);
    copy(other);
    return *this;
}

void Rrep::copy(const Rrep& other)
{
    this->repairFlag = other.repairFlag;
    this->ackRequiredFlag = other.ackRequiredFlag;
    this->reserved = other.reserved;
    this->prefixSize = other.prefixSize;
    this->hopCount = other.hopCount;
    this->destAddr = other.destAddr;
    this->destSeqNum = other.destSeqNum;
    this->originatorAddr = other.originatorAddr;
    this->lifeTime = other.lifeTime;
}

void Rrep::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::aodv::AodvControlPacket::parsimPack(b);
    doParsimPacking(b,this->repairFlag);
    doParsimPacking(b,this->ackRequiredFlag);
    doParsimPacking(b,this->reserved);
    doParsimPacking(b,this->prefixSize);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->destSeqNum);
    doParsimPacking(b,this->originatorAddr);
    doParsimPacking(b,this->lifeTime);
}

void Rrep::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::aodv::AodvControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->repairFlag);
    doParsimUnpacking(b,this->ackRequiredFlag);
    doParsimUnpacking(b,this->reserved);
    doParsimUnpacking(b,this->prefixSize);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->destSeqNum);
    doParsimUnpacking(b,this->originatorAddr);
    doParsimUnpacking(b,this->lifeTime);
}

bool Rrep::getRepairFlag() const
{
    return this->repairFlag;
}

void Rrep::setRepairFlag(bool repairFlag)
{
    handleChange();
    this->repairFlag = repairFlag;
}

bool Rrep::getAckRequiredFlag() const
{
    return this->ackRequiredFlag;
}

void Rrep::setAckRequiredFlag(bool ackRequiredFlag)
{
    handleChange();
    this->ackRequiredFlag = ackRequiredFlag;
}

uint16_t Rrep::getReserved() const
{
    return this->reserved;
}

void Rrep::setReserved(uint16_t reserved)
{
    handleChange();
    this->reserved = reserved;
}

unsigned int Rrep::getPrefixSize() const
{
    return this->prefixSize;
}

void Rrep::setPrefixSize(unsigned int prefixSize)
{
    handleChange();
    this->prefixSize = prefixSize;
}

unsigned int Rrep::getHopCount() const
{
    return this->hopCount;
}

void Rrep::setHopCount(unsigned int hopCount)
{
    handleChange();
    this->hopCount = hopCount;
}

const L3Address& Rrep::getDestAddr() const
{
    return this->destAddr;
}

void Rrep::setDestAddr(const L3Address& destAddr)
{
    handleChange();
    this->destAddr = destAddr;
}

uint32_t Rrep::getDestSeqNum() const
{
    return this->destSeqNum;
}

void Rrep::setDestSeqNum(uint32_t destSeqNum)
{
    handleChange();
    this->destSeqNum = destSeqNum;
}

const L3Address& Rrep::getOriginatorAddr() const
{
    return this->originatorAddr;
}

void Rrep::setOriginatorAddr(const L3Address& originatorAddr)
{
    handleChange();
    this->originatorAddr = originatorAddr;
}

omnetpp::simtime_t Rrep::getLifeTime() const
{
    return this->lifeTime;
}

void Rrep::setLifeTime(omnetpp::simtime_t lifeTime)
{
    handleChange();
    this->lifeTime = lifeTime;
}

class RrepDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_repairFlag,
        FIELD_ackRequiredFlag,
        FIELD_reserved,
        FIELD_prefixSize,
        FIELD_hopCount,
        FIELD_destAddr,
        FIELD_destSeqNum,
        FIELD_originatorAddr,
        FIELD_lifeTime,
    };
  public:
    RrepDescriptor();
    virtual ~RrepDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(RrepDescriptor)

RrepDescriptor::RrepDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodv::Rrep)), "inet::aodv::AodvControlPacket")
{
    propertynames = nullptr;
}

RrepDescriptor::~RrepDescriptor()
{
    delete[] propertynames;
}

bool RrepDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Rrep *>(obj)!=nullptr;
}

const char **RrepDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RrepDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RrepDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int RrepDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_repairFlag
        FD_ISEDITABLE,    // FIELD_ackRequiredFlag
        FD_ISEDITABLE,    // FIELD_reserved
        FD_ISEDITABLE,    // FIELD_prefixSize
        FD_ISEDITABLE,    // FIELD_hopCount
        0,    // FIELD_destAddr
        FD_ISEDITABLE,    // FIELD_destSeqNum
        0,    // FIELD_originatorAddr
        0,    // FIELD_lifeTime
    };
    return (field >= 0 && field < 9) ? fieldTypeFlags[field] : 0;
}

const char *RrepDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "repairFlag",
        "ackRequiredFlag",
        "reserved",
        "prefixSize",
        "hopCount",
        "destAddr",
        "destSeqNum",
        "originatorAddr",
        "lifeTime",
    };
    return (field >= 0 && field < 9) ? fieldNames[field] : nullptr;
}

int RrepDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "repairFlag") == 0) return base+0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "ackRequiredFlag") == 0) return base+1;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reserved") == 0) return base+2;
    if (fieldName[0] == 'p' && strcmp(fieldName, "prefixSize") == 0) return base+3;
    if (fieldName[0] == 'h' && strcmp(fieldName, "hopCount") == 0) return base+4;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destAddr") == 0) return base+5;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destSeqNum") == 0) return base+6;
    if (fieldName[0] == 'o' && strcmp(fieldName, "originatorAddr") == 0) return base+7;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lifeTime") == 0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RrepDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_repairFlag
        "bool",    // FIELD_ackRequiredFlag
        "uint16_t",    // FIELD_reserved
        "unsigned int",    // FIELD_prefixSize
        "unsigned int",    // FIELD_hopCount
        "inet::L3Address",    // FIELD_destAddr
        "uint32_t",    // FIELD_destSeqNum
        "inet::L3Address",    // FIELD_originatorAddr
        "omnetpp::simtime_t",    // FIELD_lifeTime
    };
    return (field >= 0 && field < 9) ? fieldTypeStrings[field] : nullptr;
}

const char **RrepDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *RrepDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int RrepDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Rrep *pp = (Rrep *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void RrepDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Rrep *pp = (Rrep *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Rrep'", field);
    }
}

const char *RrepDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Rrep *pp = (Rrep *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RrepDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Rrep *pp = (Rrep *)object; (void)pp;
    switch (field) {
        case FIELD_repairFlag: return bool2string(pp->getRepairFlag());
        case FIELD_ackRequiredFlag: return bool2string(pp->getAckRequiredFlag());
        case FIELD_reserved: return ulong2string(pp->getReserved());
        case FIELD_prefixSize: return ulong2string(pp->getPrefixSize());
        case FIELD_hopCount: return ulong2string(pp->getHopCount());
        case FIELD_destAddr: return pp->getDestAddr().str();
        case FIELD_destSeqNum: return ulong2string(pp->getDestSeqNum());
        case FIELD_originatorAddr: return pp->getOriginatorAddr().str();
        case FIELD_lifeTime: return simtime2string(pp->getLifeTime());
        default: return "";
    }
}

void RrepDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Rrep *pp = (Rrep *)object; (void)pp;
    switch (field) {
        case FIELD_repairFlag: pp->setRepairFlag(string2bool(value)); break;
        case FIELD_ackRequiredFlag: pp->setAckRequiredFlag(string2bool(value)); break;
        case FIELD_reserved: pp->setReserved(string2ulong(value)); break;
        case FIELD_prefixSize: pp->setPrefixSize(string2ulong(value)); break;
        case FIELD_hopCount: pp->setHopCount(string2ulong(value)); break;
        case FIELD_destSeqNum: pp->setDestSeqNum(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Rrep'", field);
    }
}

const char *RrepDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *RrepDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Rrep *pp = (Rrep *)object; (void)pp;
    switch (field) {
        case FIELD_destAddr: return toVoidPtr(&pp->getDestAddr()); break;
        case FIELD_originatorAddr: return toVoidPtr(&pp->getOriginatorAddr()); break;
        default: return nullptr;
    }
}

void RrepDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Rrep *pp = (Rrep *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Rrep'", field);
    }
}

UnreachableNode::UnreachableNode()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const UnreachableNode& a)
{
    doParsimPacking(b,a.addr);
    doParsimPacking(b,a.seqNum);
}

void __doUnpacking(omnetpp::cCommBuffer *b, UnreachableNode& a)
{
    doParsimUnpacking(b,a.addr);
    doParsimUnpacking(b,a.seqNum);
}

class UnreachableNodeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_addr,
        FIELD_seqNum,
    };
  public:
    UnreachableNodeDescriptor();
    virtual ~UnreachableNodeDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(UnreachableNodeDescriptor)

UnreachableNodeDescriptor::UnreachableNodeDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodv::UnreachableNode)), "")
{
    propertynames = nullptr;
}

UnreachableNodeDescriptor::~UnreachableNodeDescriptor()
{
    delete[] propertynames;
}

bool UnreachableNodeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UnreachableNode *>(obj)!=nullptr;
}

const char **UnreachableNodeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UnreachableNodeDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UnreachableNodeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int UnreachableNodeDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_addr
        FD_ISEDITABLE,    // FIELD_seqNum
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *UnreachableNodeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "addr",
        "seqNum",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int UnreachableNodeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'a' && strcmp(fieldName, "addr") == 0) return base+0;
    if (fieldName[0] == 's' && strcmp(fieldName, "seqNum") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UnreachableNodeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_addr
        "uint32_t",    // FIELD_seqNum
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **UnreachableNodeDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *UnreachableNodeDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int UnreachableNodeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UnreachableNode *pp = (UnreachableNode *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void UnreachableNodeDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    UnreachableNode *pp = (UnreachableNode *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'UnreachableNode'", field);
    }
}

const char *UnreachableNodeDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UnreachableNode *pp = (UnreachableNode *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UnreachableNodeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UnreachableNode *pp = (UnreachableNode *)object; (void)pp;
    switch (field) {
        case FIELD_addr: return pp->addr.str();
        case FIELD_seqNum: return ulong2string(pp->seqNum);
        default: return "";
    }
}

void UnreachableNodeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    UnreachableNode *pp = (UnreachableNode *)object; (void)pp;
    switch (field) {
        case FIELD_seqNum: pp->seqNum = string2ulong(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UnreachableNode'", field);
    }
}

const char *UnreachableNodeDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *UnreachableNodeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UnreachableNode *pp = (UnreachableNode *)object; (void)pp;
    switch (field) {
        case FIELD_addr: return toVoidPtr(&pp->addr); break;
        default: return nullptr;
    }
}

void UnreachableNodeDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    UnreachableNode *pp = (UnreachableNode *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UnreachableNode'", field);
    }
}

Register_Class(Rerr)

Rerr::Rerr() : ::inet::aodv::AodvControlPacket()
{
}

Rerr::Rerr(const Rerr& other) : ::inet::aodv::AodvControlPacket(other)
{
    copy(other);
}

Rerr::~Rerr()
{
    delete [] this->unreachableNodes;
}

Rerr& Rerr::operator=(const Rerr& other)
{
    if (this == &other) return *this;
    ::inet::aodv::AodvControlPacket::operator=(other);
    copy(other);
    return *this;
}

void Rerr::copy(const Rerr& other)
{
    this->noDeleteFlag = other.noDeleteFlag;
    this->reserved = other.reserved;
    delete [] this->unreachableNodes;
    this->unreachableNodes = (other.unreachableNodes_arraysize==0) ? nullptr : new UnreachableNode[other.unreachableNodes_arraysize];
    unreachableNodes_arraysize = other.unreachableNodes_arraysize;
    for (size_t i = 0; i < unreachableNodes_arraysize; i++) {
        this->unreachableNodes[i] = other.unreachableNodes[i];
    }
}

void Rerr::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::aodv::AodvControlPacket::parsimPack(b);
    doParsimPacking(b,this->noDeleteFlag);
    doParsimPacking(b,this->reserved);
    b->pack(unreachableNodes_arraysize);
    doParsimArrayPacking(b,this->unreachableNodes,unreachableNodes_arraysize);
}

void Rerr::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::aodv::AodvControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->noDeleteFlag);
    doParsimUnpacking(b,this->reserved);
    delete [] this->unreachableNodes;
    b->unpack(unreachableNodes_arraysize);
    if (unreachableNodes_arraysize == 0) {
        this->unreachableNodes = nullptr;
    } else {
        this->unreachableNodes = new UnreachableNode[unreachableNodes_arraysize];
        doParsimArrayUnpacking(b,this->unreachableNodes,unreachableNodes_arraysize);
    }
}

bool Rerr::getNoDeleteFlag() const
{
    return this->noDeleteFlag;
}

void Rerr::setNoDeleteFlag(bool noDeleteFlag)
{
    handleChange();
    this->noDeleteFlag = noDeleteFlag;
}

uint16_t Rerr::getReserved() const
{
    return this->reserved;
}

void Rerr::setReserved(uint16_t reserved)
{
    handleChange();
    this->reserved = reserved;
}

size_t Rerr::getUnreachableNodesArraySize() const
{
    return unreachableNodes_arraysize;
}

const UnreachableNode& Rerr::getUnreachableNodes(size_t k) const
{
    if (k >= unreachableNodes_arraysize) throw omnetpp::cRuntimeError("Array of size unreachableNodes_arraysize indexed by %lu", (unsigned long)k);
    return this->unreachableNodes[k];
}

void Rerr::setUnreachableNodesArraySize(size_t newSize)
{
    handleChange();
    UnreachableNode *unreachableNodes2 = (newSize==0) ? nullptr : new UnreachableNode[newSize];
    size_t minSize = unreachableNodes_arraysize < newSize ? unreachableNodes_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        unreachableNodes2[i] = this->unreachableNodes[i];
    delete [] this->unreachableNodes;
    this->unreachableNodes = unreachableNodes2;
    unreachableNodes_arraysize = newSize;
}

void Rerr::setUnreachableNodes(size_t k, const UnreachableNode& unreachableNodes)
{
    if (k >= unreachableNodes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    this->unreachableNodes[k] = unreachableNodes;
}

void Rerr::insertUnreachableNodes(size_t k, const UnreachableNode& unreachableNodes)
{
    if (k > unreachableNodes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = unreachableNodes_arraysize + 1;
    UnreachableNode *unreachableNodes2 = new UnreachableNode[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        unreachableNodes2[i] = this->unreachableNodes[i];
    unreachableNodes2[k] = unreachableNodes;
    for (i = k + 1; i < newSize; i++)
        unreachableNodes2[i] = this->unreachableNodes[i-1];
    delete [] this->unreachableNodes;
    this->unreachableNodes = unreachableNodes2;
    unreachableNodes_arraysize = newSize;
}

void Rerr::insertUnreachableNodes(const UnreachableNode& unreachableNodes)
{
    insertUnreachableNodes(unreachableNodes_arraysize, unreachableNodes);
}

void Rerr::eraseUnreachableNodes(size_t k)
{
    if (k >= unreachableNodes_arraysize) throw omnetpp::cRuntimeError("Array of size  indexed by %lu", (unsigned long)k);
    handleChange();
    size_t newSize = unreachableNodes_arraysize - 1;
    UnreachableNode *unreachableNodes2 = (newSize == 0) ? nullptr : new UnreachableNode[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        unreachableNodes2[i] = this->unreachableNodes[i];
    for (i = k; i < newSize; i++)
        unreachableNodes2[i] = this->unreachableNodes[i+1];
    delete [] this->unreachableNodes;
    this->unreachableNodes = unreachableNodes2;
    unreachableNodes_arraysize = newSize;
}

class RerrDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_noDeleteFlag,
        FIELD_reserved,
        FIELD_unreachableNodes,
    };
  public:
    RerrDescriptor();
    virtual ~RerrDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(RerrDescriptor)

RerrDescriptor::RerrDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodv::Rerr)), "inet::aodv::AodvControlPacket")
{
    propertynames = nullptr;
}

RerrDescriptor::~RerrDescriptor()
{
    delete[] propertynames;
}

bool RerrDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Rerr *>(obj)!=nullptr;
}

const char **RerrDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RerrDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RerrDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int RerrDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_noDeleteFlag
        FD_ISEDITABLE,    // FIELD_reserved
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISRESIZABLE,    // FIELD_unreachableNodes
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *RerrDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "noDeleteFlag",
        "reserved",
        "unreachableNodes",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int RerrDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'n' && strcmp(fieldName, "noDeleteFlag") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reserved") == 0) return base+1;
    if (fieldName[0] == 'u' && strcmp(fieldName, "unreachableNodes") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RerrDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_noDeleteFlag
        "uint16_t",    // FIELD_reserved
        "inet::aodv::UnreachableNode",    // FIELD_unreachableNodes
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **RerrDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *RerrDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int RerrDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Rerr *pp = (Rerr *)object; (void)pp;
    switch (field) {
        case FIELD_unreachableNodes: return pp->getUnreachableNodesArraySize();
        default: return 0;
    }
}

void RerrDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Rerr *pp = (Rerr *)object; (void)pp;
    switch (field) {
        case FIELD_unreachableNodes: pp->setUnreachableNodesArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Rerr'", field);
    }
}

const char *RerrDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Rerr *pp = (Rerr *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RerrDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Rerr *pp = (Rerr *)object; (void)pp;
    switch (field) {
        case FIELD_noDeleteFlag: return bool2string(pp->getNoDeleteFlag());
        case FIELD_reserved: return ulong2string(pp->getReserved());
        case FIELD_unreachableNodes: {std::stringstream out; out << pp->getUnreachableNodes(i); return out.str();}
        default: return "";
    }
}

void RerrDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Rerr *pp = (Rerr *)object; (void)pp;
    switch (field) {
        case FIELD_noDeleteFlag: pp->setNoDeleteFlag(string2bool(value)); break;
        case FIELD_reserved: pp->setReserved(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Rerr'", field);
    }
}

const char *RerrDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_unreachableNodes: return omnetpp::opp_typename(typeid(UnreachableNode));
        default: return nullptr;
    };
}

void *RerrDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Rerr *pp = (Rerr *)object; (void)pp;
    switch (field) {
        case FIELD_unreachableNodes: return toVoidPtr(&pp->getUnreachableNodes(i)); break;
        default: return nullptr;
    }
}

void RerrDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    Rerr *pp = (Rerr *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Rerr'", field);
    }
}

Register_Class(RrepAck)

RrepAck::RrepAck() : ::inet::aodv::AodvControlPacket()
{
    this->setChunkLength(B(2));

}

RrepAck::RrepAck(const RrepAck& other) : ::inet::aodv::AodvControlPacket(other)
{
    copy(other);
}

RrepAck::~RrepAck()
{
}

RrepAck& RrepAck::operator=(const RrepAck& other)
{
    if (this == &other) return *this;
    ::inet::aodv::AodvControlPacket::operator=(other);
    copy(other);
    return *this;
}

void RrepAck::copy(const RrepAck& other)
{
    this->reserved = other.reserved;
}

void RrepAck::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::aodv::AodvControlPacket::parsimPack(b);
    doParsimPacking(b,this->reserved);
}

void RrepAck::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::aodv::AodvControlPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->reserved);
}

uint8_t RrepAck::getReserved() const
{
    return this->reserved;
}

void RrepAck::setReserved(uint8_t reserved)
{
    handleChange();
    this->reserved = reserved;
}

class RrepAckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_reserved,
    };
  public:
    RrepAckDescriptor();
    virtual ~RrepAckDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(RrepAckDescriptor)

RrepAckDescriptor::RrepAckDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodv::RrepAck)), "inet::aodv::AodvControlPacket")
{
    propertynames = nullptr;
}

RrepAckDescriptor::~RrepAckDescriptor()
{
    delete[] propertynames;
}

bool RrepAckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RrepAck *>(obj)!=nullptr;
}

const char **RrepAckDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RrepAckDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RrepAckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int RrepAckDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_reserved
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *RrepAckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "reserved",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int RrepAckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "reserved") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RrepAckDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_reserved
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **RrepAckDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *RrepAckDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int RrepAckDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RrepAck *pp = (RrepAck *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void RrepAckDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    RrepAck *pp = (RrepAck *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'RrepAck'", field);
    }
}

const char *RrepAckDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RrepAck *pp = (RrepAck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RrepAckDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RrepAck *pp = (RrepAck *)object; (void)pp;
    switch (field) {
        case FIELD_reserved: return ulong2string(pp->getReserved());
        default: return "";
    }
}

void RrepAckDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    RrepAck *pp = (RrepAck *)object; (void)pp;
    switch (field) {
        case FIELD_reserved: pp->setReserved(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RrepAck'", field);
    }
}

const char *RrepAckDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *RrepAckDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RrepAck *pp = (RrepAck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void RrepAckDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    RrepAck *pp = (RrepAck *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RrepAck'", field);
    }
}

Register_Class(WaitForRrep)

WaitForRrep::WaitForRrep(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

WaitForRrep::WaitForRrep(const WaitForRrep& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

WaitForRrep::~WaitForRrep()
{
}

WaitForRrep& WaitForRrep::operator=(const WaitForRrep& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void WaitForRrep::copy(const WaitForRrep& other)
{
    this->destAddr = other.destAddr;
    this->lastTTL = other.lastTTL;
    this->fromInvalidEntry = other.fromInvalidEntry;
}

void WaitForRrep::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->lastTTL);
    doParsimPacking(b,this->fromInvalidEntry);
}

void WaitForRrep::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->lastTTL);
    doParsimUnpacking(b,this->fromInvalidEntry);
}

const L3Address& WaitForRrep::getDestAddr() const
{
    return this->destAddr;
}

void WaitForRrep::setDestAddr(const L3Address& destAddr)
{
    this->destAddr = destAddr;
}

unsigned int WaitForRrep::getLastTTL() const
{
    return this->lastTTL;
}

void WaitForRrep::setLastTTL(unsigned int lastTTL)
{
    this->lastTTL = lastTTL;
}

bool WaitForRrep::getFromInvalidEntry() const
{
    return this->fromInvalidEntry;
}

void WaitForRrep::setFromInvalidEntry(bool fromInvalidEntry)
{
    this->fromInvalidEntry = fromInvalidEntry;
}

class WaitForRrepDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_destAddr,
        FIELD_lastTTL,
        FIELD_fromInvalidEntry,
    };
  public:
    WaitForRrepDescriptor();
    virtual ~WaitForRrepDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(WaitForRrepDescriptor)

WaitForRrepDescriptor::WaitForRrepDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodv::WaitForRrep)), "omnetpp::cMessage")
{
    propertynames = nullptr;
}

WaitForRrepDescriptor::~WaitForRrepDescriptor()
{
    delete[] propertynames;
}

bool WaitForRrepDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<WaitForRrep *>(obj)!=nullptr;
}

const char **WaitForRrepDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *WaitForRrepDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int WaitForRrepDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int WaitForRrepDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_destAddr
        FD_ISEDITABLE,    // FIELD_lastTTL
        FD_ISEDITABLE,    // FIELD_fromInvalidEntry
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *WaitForRrepDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "destAddr",
        "lastTTL",
        "fromInvalidEntry",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int WaitForRrepDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destAddr") == 0) return base+0;
    if (fieldName[0] == 'l' && strcmp(fieldName, "lastTTL") == 0) return base+1;
    if (fieldName[0] == 'f' && strcmp(fieldName, "fromInvalidEntry") == 0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *WaitForRrepDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_destAddr
        "unsigned int",    // FIELD_lastTTL
        "bool",    // FIELD_fromInvalidEntry
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **WaitForRrepDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *WaitForRrepDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int WaitForRrepDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    WaitForRrep *pp = (WaitForRrep *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void WaitForRrepDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    WaitForRrep *pp = (WaitForRrep *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'WaitForRrep'", field);
    }
}

const char *WaitForRrepDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    WaitForRrep *pp = (WaitForRrep *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string WaitForRrepDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    WaitForRrep *pp = (WaitForRrep *)object; (void)pp;
    switch (field) {
        case FIELD_destAddr: return pp->getDestAddr().str();
        case FIELD_lastTTL: return ulong2string(pp->getLastTTL());
        case FIELD_fromInvalidEntry: return bool2string(pp->getFromInvalidEntry());
        default: return "";
    }
}

void WaitForRrepDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    WaitForRrep *pp = (WaitForRrep *)object; (void)pp;
    switch (field) {
        case FIELD_lastTTL: pp->setLastTTL(string2ulong(value)); break;
        case FIELD_fromInvalidEntry: pp->setFromInvalidEntry(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WaitForRrep'", field);
    }
}

const char *WaitForRrepDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *WaitForRrepDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    WaitForRrep *pp = (WaitForRrep *)object; (void)pp;
    switch (field) {
        case FIELD_destAddr: return toVoidPtr(&pp->getDestAddr()); break;
        default: return nullptr;
    }
}

void WaitForRrepDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    WaitForRrep *pp = (WaitForRrep *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WaitForRrep'", field);
    }
}

Register_Class(PacketHolderMessage)

PacketHolderMessage::PacketHolderMessage(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
    if (this->ownedPacket != nullptr) take(this->ownedPacket);
}

PacketHolderMessage::PacketHolderMessage(const PacketHolderMessage& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

PacketHolderMessage::~PacketHolderMessage()
{
    dropAndDelete(this->ownedPacket);
}

PacketHolderMessage& PacketHolderMessage::operator=(const PacketHolderMessage& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void PacketHolderMessage::copy(const PacketHolderMessage& other)
{
    dropAndDelete(this->ownedPacket);
    this->ownedPacket = other.ownedPacket;
    if (this->ownedPacket != nullptr) {
        this->ownedPacket = this->ownedPacket->dup();
        take(this->ownedPacket);
        this->ownedPacket->setName(other.ownedPacket->getName());
    }
}

void PacketHolderMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->ownedPacket);
}

void PacketHolderMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->ownedPacket);
}

const Packet * PacketHolderMessage::getOwnedPacket() const
{
    return this->ownedPacket;
}

void PacketHolderMessage::setOwnedPacket(Packet * ownedPacket)
{
    if (this->ownedPacket != nullptr) throw omnetpp::cRuntimeError("setOwnedPacket(): a value is already set, remove it first with dropOwnedPacket()");
    this->ownedPacket = ownedPacket;
    if (this->ownedPacket != nullptr)
        take(this->ownedPacket);
}

Packet * PacketHolderMessage::dropOwnedPacket()
{
    Packet * retval = this->ownedPacket;
    if (retval != nullptr)
        drop(retval);
    this->ownedPacket = nullptr;
    return retval;
}

class PacketHolderMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_ownedPacket,
    };
  public:
    PacketHolderMessageDescriptor();
    virtual ~PacketHolderMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;
    virtual void setFieldArraySize(void *object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual void setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
    virtual void setFieldStructValuePointer(void *object, int field, int i, void *ptr) const override;
};

Register_ClassDescriptor(PacketHolderMessageDescriptor)

PacketHolderMessageDescriptor::PacketHolderMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::aodv::PacketHolderMessage)), "omnetpp::cMessage")
{
    propertynames = nullptr;
}

PacketHolderMessageDescriptor::~PacketHolderMessageDescriptor()
{
    delete[] propertynames;
}

bool PacketHolderMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PacketHolderMessage *>(obj)!=nullptr;
}

const char **PacketHolderMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PacketHolderMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PacketHolderMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int PacketHolderMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISCOWNEDOBJECT | FD_ISREPLACEABLE,    // FIELD_ownedPacket
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *PacketHolderMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ownedPacket",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int PacketHolderMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'o' && strcmp(fieldName, "ownedPacket") == 0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PacketHolderMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::Packet",    // FIELD_ownedPacket
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **PacketHolderMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_ownedPacket: {
            static const char *names[] = { "owned",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *PacketHolderMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_ownedPacket:
            if (!strcmp(propertyname, "owned")) return "";
            return nullptr;
        default: return nullptr;
    }
}

int PacketHolderMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PacketHolderMessage *pp = (PacketHolderMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PacketHolderMessageDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    PacketHolderMessage *pp = (PacketHolderMessage *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PacketHolderMessage'", field);
    }
}

const char *PacketHolderMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PacketHolderMessage *pp = (PacketHolderMessage *)object; (void)pp;
    switch (field) {
        case FIELD_ownedPacket: { const Packet * value = pp->getOwnedPacket(); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string PacketHolderMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PacketHolderMessage *pp = (PacketHolderMessage *)object; (void)pp;
    switch (field) {
        case FIELD_ownedPacket: {std::stringstream out; out << pp->getOwnedPacket(); return out.str();}
        default: return "";
    }
}

void PacketHolderMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    PacketHolderMessage *pp = (PacketHolderMessage *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PacketHolderMessage'", field);
    }
}

const char *PacketHolderMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_ownedPacket: return omnetpp::opp_typename(typeid(Packet));
        default: return nullptr;
    };
}

void *PacketHolderMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PacketHolderMessage *pp = (PacketHolderMessage *)object; (void)pp;
    switch (field) {
        case FIELD_ownedPacket: return toVoidPtr(pp->getOwnedPacket()); break;
        default: return nullptr;
    }
}

void PacketHolderMessageDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    PacketHolderMessage *pp = (PacketHolderMessage *)object; (void)pp;
    switch (field) {
        case FIELD_ownedPacket: pp->setOwnedPacket((Packet *)ptr); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PacketHolderMessage'", field);
    }
}

} // namespace aodv
} // namespace inet

