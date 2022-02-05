/*
 * RdmaHeader_m.cc
 *
 *  Created on: Aug 10, 2021
 *      Author: vr4
 */

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
#include "RdmaHeader_m.h"

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

Register_Class(RdmaHeader)

RdmaHeader::RdmaHeader() : ::inet::TransportHeaderBase()
{
    this->setChunkLength(RDMA_HEADER_LENGTH);

}

RdmaHeader::RdmaHeader(const RdmaHeader& other) : ::inet::TransportHeaderBase(other)
{
    copy(other);
}

RdmaHeader::~RdmaHeader()
{
}

RdmaHeader& RdmaHeader::operator=(const RdmaHeader& other)
{
    if (this == &other) return *this;
    ::inet::TransportHeaderBase::operator=(other);
    copy(other);
    return *this;
}

void RdmaHeader::copy(const RdmaHeader& other)//Cambiado
{
    this->srcPort = other.srcPort;
    this->destPort = other.destPort;
    this->totalLengthField = other.totalLengthField;
    this->crc = other.crc;
    this->crcMode = other.crcMode;
    /*this->srcAddress = other.srcAddress;
    this->dstAddress = other.dstAddress;//Cambiado*/
}

void RdmaHeader::parsimPack(omnetpp::cCommBuffer *b) const //Cambiado
{
    ::inet::TransportHeaderBase::parsimPack(b);
    doParsimPacking(b,this->srcPort);
    doParsimPacking(b,this->destPort);
    doParsimPacking(b,this->totalLengthField);
    doParsimPacking(b,this->crc);
    doParsimPacking(b,this->crcMode);
    /*doParsimPacking(b, this->srcAddress);//Cambiado
    doParsimPacking(b, this->dstAddress);//Cambiado*/
}

void RdmaHeader::parsimUnpack(omnetpp::cCommBuffer *b)//Cambiado
{
    ::inet::TransportHeaderBase::parsimUnpack(b);
    doParsimUnpacking(b,this->srcPort);
    doParsimUnpacking(b,this->destPort);
    doParsimUnpacking(b,this->totalLengthField);
    doParsimUnpacking(b,this->crc);
    doParsimUnpacking(b,this->crcMode);
    /*doParsimUnpacking(b,this->srcAddress);//Cambiado
    doParsimUnpacking(b,this->dstAddress);//Cambiado*/

}

unsigned short RdmaHeader::getSrcPort() const
{
    return this->srcPort;
}

void RdmaHeader::setSrcPort(unsigned short srcPort)
{
    handleChange();
    this->srcPort = srcPort;
}

unsigned short RdmaHeader::getDestPort() const
{
    return this->destPort;
}

void RdmaHeader::setDestPort(unsigned short destPort)
{
    handleChange();
    this->destPort = destPort;
}

B RdmaHeader::getTotalLengthField() const
{
    return this->totalLengthField;
}

void RdmaHeader::setTotalLengthField(B totalLengthField)
{
    handleChange();
    this->totalLengthField = totalLengthField;
}

uint16_t RdmaHeader::getCrc() const
{
    return this->crc;
}

void RdmaHeader::setCrc(uint16_t crc)
{
    handleChange();
    this->crc = crc;
}

inet::CrcMode RdmaHeader::getCrcMode() const
{
    return this->crcMode;
}

void RdmaHeader::setCrcMode(inet::CrcMode crcMode)
{
    handleChange();
    this->crcMode = crcMode;
}

//Añadidos
clocktime_t RdmaHeader::getGenerationTime() const
{
    return this->generationTime;
}

void RdmaHeader::setGenerationTime(clocktime_t generationTime)
{
    handleChange();
    this->generationTime = generationTime;
}

bool RdmaHeader::getMoreFragments() const
{
    return this->moreFragments;
}

void RdmaHeader::setMoreFragments(bool moreFragments)
{
    handleChange();
    this->moreFragments = moreFragments;
}

uint16_t RdmaHeader::getFragmentOffset() const
{
    return this->fragmentOffset;
}

void RdmaHeader::setFragmentOffset(uint16_t fragmentOffset)
{
    handleChange();
    this->fragmentOffset = fragmentOffset;
}
class RdmaHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_srcPort,
        FIELD_destPort,
        FIELD_totalLengthField,
        FIELD_crc,
        FIELD_crcMode,
       /* FIELD_srcAddress,
        FIELD_dstAddress,//Cambiado*/
    };
  public:
    RdmaHeaderDescriptor();
    virtual ~RdmaHeaderDescriptor();

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

Register_ClassDescriptor(RdmaHeaderDescriptor)

RdmaHeaderDescriptor::RdmaHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::RdmaHeader)), "inet::TransportHeaderBase")
{
    propertynames = nullptr;
}

RdmaHeaderDescriptor::~RdmaHeaderDescriptor()
{
    delete[] propertynames;
}

bool RdmaHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RdmaHeader *>(obj)!=nullptr;
}

const char **RdmaHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RdmaHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RdmaHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5; //Cambiado
}

unsigned int RdmaHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_srcPort
        FD_ISEDITABLE,    // FIELD_destPort
        FD_ISEDITABLE,    // FIELD_totalLengthField
        FD_ISEDITABLE,    // FIELD_crc
        FD_ISEDITABLE,    // FIELD_crcMode
        /*FD_ISEDITABLE,    // FIELD_srcAddress //Cambiado
        FD_ISEDITABLE,    // FIELD_dstAddress //Cambiado*/
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 5; //Cambiado
}

const char *RdmaHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcPort",
        "destPort",
        "totalLengthField",
        "crc",
        "crcMode",
       /* "srcAddress",//Cambiado
        "dstAddress",//Cambiado*/
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr; //Cambiado
}

int RdmaHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 's' && strcmp(fieldName, "srcPort") == 0) return base+0;
    if (fieldName[0] == 'd' && strcmp(fieldName, "destPort") == 0) return base+1;
    if (fieldName[0] == 't' && strcmp(fieldName, "totalLengthField") == 0) return base+2;
    if (fieldName[0] == 'c' && strcmp(fieldName, "crc") == 0) return base+3;
    if (fieldName[0] == 'c' && strcmp(fieldName, "crcMode") == 0) return base+4;
 /*   if (fieldName[0] == 's' && strcmp(fieldName, "srcAddress") == 0) return base+5;//Cambiado
    if (fieldName[0] == 'd' && strcmp(fieldName, "dstAddress") == 0) return base+6;//Cambiado*/
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RdmaHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",    // FIELD_srcPort
        "unsigned short",    // FIELD_destPort
        "inet::B",    // FIELD_totalLengthField
        "uint16_t",    // FIELD_crc
        "inet::CrcMode",    // FIELD_crcMode
   /*     "int"           //FIELD_srcAddress //Cambiado
        "int"           //FIELD_dstAddress //Cambiado*/
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr; //Cambiado
}

const char **RdmaHeaderDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_crc: {
            static const char *names[] = { "toString", "fromString",  nullptr };
            return names;
        }
        case FIELD_crcMode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *RdmaHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case FIELD_crc:
            if (!strcmp(propertyname, "toString")) return "utils::hex($)";
            if (!strcmp(propertyname, "fromString")) return "utils::uhex($)";
            return nullptr;
        case FIELD_crcMode:
            if (!strcmp(propertyname, "enum")) return "inet::CrcMode";
            return nullptr;
        default: return nullptr;
    }
}

int RdmaHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RdmaHeader *pp = (RdmaHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

void RdmaHeaderDescriptor::setFieldArraySize(void *object, int field, int size) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldArraySize(object, field, size);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    RdmaHeader *pp = (RdmaHeader *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'RdmaHeader'", field);
    }
}

const char *RdmaHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RdmaHeader *pp = (RdmaHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RdmaHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RdmaHeader *pp = (RdmaHeader *)object; (void)pp;
    switch (field) {
        case FIELD_srcPort: return ulong2string(pp->getSrcPort());
        case FIELD_destPort: return ulong2string(pp->getDestPort());
        case FIELD_totalLengthField: return unit2string(pp->getTotalLengthField());
        case FIELD_crc: return utils::hex(pp->getCrc());
        case FIELD_crcMode: return enum2string(pp->getCrcMode(), "inet::CrcMode");
   /*     case FIELD_srcAddress: return int642string(pp->getSrcAddress());//Cambiado
        case FIELD_dstAddress: return int642string(pp->getDestAddress());//Cambiado*/
        default: return "";
    }
}

void RdmaHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    RdmaHeader *pp = (RdmaHeader *)object; (void)pp;
    switch (field) {
        case FIELD_srcPort: pp->setSrcPort(string2ulong(value)); break;
        case FIELD_destPort: pp->setDestPort(string2ulong(value)); break;
        case FIELD_totalLengthField: pp->setTotalLengthField(B(string2long(value))); break;
        case FIELD_crc: pp->setCrc(utils::uhex(value)); break;
        case FIELD_crcMode: pp->setCrcMode((inet::CrcMode)string2enum(value, "inet::CrcMode")); break;
  /*      case FIELD_srcAddress: pp->setSrcAddress(string2int64(value));//Cambiado
        case FIELD_dstAddress: pp->setDestAddress(string2int64(value));//Cambiado*/
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RdmaHeader'", field);
    }
}

const char *RdmaHeaderDescriptor::getFieldStructName(int field) const
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

void *RdmaHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RdmaHeader *pp = (RdmaHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

void RdmaHeaderDescriptor::setFieldStructValuePointer(void *object, int field, int i, void *ptr) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount()) {
            basedesc->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= basedesc->getFieldCount();
    }
    RdmaHeader *pp = (RdmaHeader *)object; (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RdmaHeader'", field);
    }
}

} // namespace inet


