//
// Generated file, do not edit! Created by nedtool 6.0 from inet/applications/voip/SimpleVoipPacket.msg.
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
#include "SimpleVoipPacket_m.h"

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

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule to generate operator<< for shared_ptr<T>
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const std::shared_ptr<T>& t) { return out << t.get(); }

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline typename std::enable_if<!std::is_base_of<omnetpp::cObject, T>::value, std::ostream&>::type
operator<<(std::ostream& out,const T&) {const char *s = omnetpp::opp_typename(typeid(T)); out.put('<'); out.write(s, strlen(s)); out.put('>'); return out;}

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

Register_Class(SimpleVoipPacket)

SimpleVoipPacket::SimpleVoipPacket() : ::inet::FieldsChunk()
{
}

SimpleVoipPacket::SimpleVoipPacket(const SimpleVoipPacket& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

SimpleVoipPacket::~SimpleVoipPacket()
{
}

SimpleVoipPacket& SimpleVoipPacket::operator=(const SimpleVoipPacket& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void SimpleVoipPacket::copy(const SimpleVoipPacket& other)
{
    this->totalLengthField = other.totalLengthField;
    this->talkspurtID = other.talkspurtID;
    this->talkspurtNumPackets = other.talkspurtNumPackets;
    this->packetID = other.packetID;
    this->voipTimestamp = other.voipTimestamp;
    this->voiceDuration = other.voiceDuration;
}

void SimpleVoipPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->totalLengthField);
    doParsimPacking(b,this->talkspurtID);
    doParsimPacking(b,this->talkspurtNumPackets);
    doParsimPacking(b,this->packetID);
    doParsimPacking(b,this->voipTimestamp);
    doParsimPacking(b,this->voiceDuration);
}

void SimpleVoipPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->totalLengthField);
    doParsimUnpacking(b,this->talkspurtID);
    doParsimUnpacking(b,this->talkspurtNumPackets);
    doParsimUnpacking(b,this->packetID);
    doParsimUnpacking(b,this->voipTimestamp);
    doParsimUnpacking(b,this->voiceDuration);
}

uint16_t SimpleVoipPacket::getTotalLengthField() const
{
    return this->totalLengthField;
}

void SimpleVoipPacket::setTotalLengthField(uint16_t totalLengthField)
{
    handleChange();
    this->totalLengthField = totalLengthField;
}

unsigned int SimpleVoipPacket::getTalkspurtID() const
{
    return this->talkspurtID;
}

void SimpleVoipPacket::setTalkspurtID(unsigned int talkspurtID)
{
    handleChange();
    this->talkspurtID = talkspurtID;
}

unsigned int SimpleVoipPacket::getTalkspurtNumPackets() const
{
    return this->talkspurtNumPackets;
}

void SimpleVoipPacket::setTalkspurtNumPackets(unsigned int talkspurtNumPackets)
{
    handleChange();
    this->talkspurtNumPackets = talkspurtNumPackets;
}

unsigned int SimpleVoipPacket::getPacketID() const
{
    return this->packetID;
}

void SimpleVoipPacket::setPacketID(unsigned int packetID)
{
    handleChange();
    this->packetID = packetID;
}

omnetpp::simtime_t SimpleVoipPacket::getVoipTimestamp() const
{
    return this->voipTimestamp;
}

void SimpleVoipPacket::setVoipTimestamp(omnetpp::simtime_t voipTimestamp)
{
    handleChange();
    this->voipTimestamp = voipTimestamp;
}

omnetpp::simtime_t SimpleVoipPacket::getVoiceDuration() const
{
    return this->voiceDuration;
}

void SimpleVoipPacket::setVoiceDuration(omnetpp::simtime_t voiceDuration)
{
    handleChange();
    this->voiceDuration = voiceDuration;
}

class SimpleVoipPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_totalLengthField,
        FIELD_talkspurtID,
        FIELD_talkspurtNumPackets,
        FIELD_packetID,
        FIELD_voipTimestamp,
        FIELD_voiceDuration,
    };
  public:
    SimpleVoipPacketDescriptor();
    virtual ~SimpleVoipPacketDescriptor();

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

Register_ClassDescriptor(SimpleVoipPacketDescriptor)

SimpleVoipPacketDescriptor::SimpleVoipPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::SimpleVoipPacket)), "inet::FieldsChunk")
{
    propertynames = nullptr;
}

SimpleVoipPacketDescriptor::~SimpleVoipPacketDescriptor()
{
    delete[] propertynames;
}

bool SimpleVoipPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SimpleVoipPacket *>(obj)!=nullptr;
}

const char **SimpleVoipPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SimpleVoipPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SimpleVoipPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int SimpleVoipPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_totalLengthField
        FD_ISEDITABLE,    // FIELD_talkspurtID
        FD_ISEDITABLE,    // FIELD_talkspurtNumPackets
        FD_ISEDITABLE,    // FIELD_packetID
        0,    // FIELD_voipTimestamp
        0,    // FIELD_voiceDuration
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *SimpleVoipPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "totalLengthField",
        "talkspurtID",
        "talkspurtNumPackets",
        "packetID",
        "voipTimestamp",
        "voiceDuration",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int SimpleVoipPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 't' && strcmp(fieldName, "totalLengthField") == 0) return base+0;
    if (fieldName[0] == 't' && strcmp(fieldName, "talkspurtID") == 0) return base+1;
    if (fieldName[0] == 't' && strcmp(fieldName, "talkspurtNumPackets") == 0) return base+2;
    if (fieldName[0] == 'p' && strcmp(fieldName, "packetID") == 0) return base+3;
    if (fieldName[0] == 'v' && strcmp(fieldName, "voipTimestamp") == 0) return base+4;
    if (fieldName[0] == 'v' && strcmp(fieldName, "voiceDuration") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SimpleVoipPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_totalLengthField
        "unsigned int",    // FIELD_talkspurtID
        "unsigned int",    // FIELD_talkspurtNumPackets
        "unsigned int",    // FIELD_packetID
        "omnetpp::simtime_t",    // FIELD_voipTimestamp
        "omnetpp::simtime_t",    // FIELD_voiceDuration
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **SimpleVoipPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *SimpleVoipPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SimpleVoipPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SimpleVoipPacket *pp = (SimpleVoipPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void SimpleVoipPacketDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    SimpleVoipPacket *pp = (SimpleVoipPacket *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'SimpleVoipPacket'", field);
    }
}

const char *SimpleVoipPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SimpleVoipPacket *pp = (SimpleVoipPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SimpleVoipPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SimpleVoipPacket *pp = (SimpleVoipPacket *)object; (void)pp;
    switch (field) {
        case FIELD_totalLengthField: return ulong2string(pp->getTotalLengthField());
        case FIELD_talkspurtID: return ulong2string(pp->getTalkspurtID());
        case FIELD_talkspurtNumPackets: return ulong2string(pp->getTalkspurtNumPackets());
        case FIELD_packetID: return ulong2string(pp->getPacketID());
        case FIELD_voipTimestamp: return simtime2string(pp->getVoipTimestamp());
        case FIELD_voiceDuration: return simtime2string(pp->getVoiceDuration());
        default: return "";
    }
}

void SimpleVoipPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    SimpleVoipPacket *pp = (SimpleVoipPacket *)object; (void)pp;
    switch (field) {
        case FIELD_totalLengthField: pp->setTotalLengthField(string2ulong(value)); break;
        case FIELD_talkspurtID: pp->setTalkspurtID(string2ulong(value)); break;
        case FIELD_talkspurtNumPackets: pp->setTalkspurtNumPackets(string2ulong(value)); break;
        case FIELD_packetID: pp->setPacketID(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'SimpleVoipPacket'", field);
    }
}

const char *SimpleVoipPacketDescriptor::getFieldStructName(int field) const
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

void *SimpleVoipPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SimpleVoipPacket *pp = (SimpleVoipPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void SimpleVoipPacketDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    SimpleVoipPacket *pp = (SimpleVoipPacket *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'SimpleVoipPacket'", field);
    }
}

} // namespace inet

