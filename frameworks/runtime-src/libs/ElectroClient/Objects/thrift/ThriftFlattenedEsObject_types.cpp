/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "ThriftFlattenedEsObject_types.h"

#include <algorithm>
#include <ostream>

#include "libs/TToString.h"

namespace es {


ThriftFlattenedEsObject::~ThriftFlattenedEsObject() throw() {
}


void ThriftFlattenedEsObject::__set_encodedEntries(const std::vector<int8_t> & val) {
  this->encodedEntries = val;
}

uint32_t ThriftFlattenedEsObject::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->encodedEntries.clear();
            uint32_t _size0;
            ::apache::thrift::protocol::TType _etype3;
            xfer += iprot->readListBegin(_etype3, _size0);
            this->encodedEntries.resize(_size0);
            uint32_t _i4;
            for (_i4 = 0; _i4 < _size0; ++_i4)
            {
              xfer += iprot->readByte(this->encodedEntries[_i4]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.encodedEntries = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ThriftFlattenedEsObject::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ThriftFlattenedEsObject");

  xfer += oprot->writeFieldBegin("encodedEntries", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_BYTE, static_cast<uint32_t>(this->encodedEntries.size()));
    std::vector<int8_t> ::const_iterator _iter5;
    for (_iter5 = this->encodedEntries.begin(); _iter5 != this->encodedEntries.end(); ++_iter5)
    {
      xfer += oprot->writeByte((*_iter5));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ThriftFlattenedEsObject &a, ThriftFlattenedEsObject &b) {
  using ::std::swap;
  swap(a.encodedEntries, b.encodedEntries);
  swap(a.__isset, b.__isset);
}

ThriftFlattenedEsObject::ThriftFlattenedEsObject(const ThriftFlattenedEsObject& other6) {
  encodedEntries = other6.encodedEntries;
  __isset = other6.__isset;
}
ThriftFlattenedEsObject& ThriftFlattenedEsObject::operator=(const ThriftFlattenedEsObject& other7) {
  encodedEntries = other7.encodedEntries;
  __isset = other7.__isset;
  return *this;
}
void ThriftFlattenedEsObject::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ThriftFlattenedEsObject(";
  out << "encodedEntries=" << to_string(encodedEntries);
  out << ")";
}

} // namespace