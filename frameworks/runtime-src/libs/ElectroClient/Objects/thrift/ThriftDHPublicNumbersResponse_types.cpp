/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "ThriftDHPublicNumbersResponse_types.h"

#include <algorithm>
#include <ostream>

#include "libs/TToString.h"

namespace es {


ThriftDHPublicNumbersResponse::~ThriftDHPublicNumbersResponse() throw() {
}


void ThriftDHPublicNumbersResponse::__set_baseNumber(const std::string& val) {
  this->baseNumber = val;
}

void ThriftDHPublicNumbersResponse::__set_primeNumber(const std::string& val) {
  this->primeNumber = val;
}

uint32_t ThriftDHPublicNumbersResponse::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->baseNumber);
          this->__isset.baseNumber = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->primeNumber);
          this->__isset.primeNumber = true;
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

uint32_t ThriftDHPublicNumbersResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ThriftDHPublicNumbersResponse");

  xfer += oprot->writeFieldBegin("baseNumber", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->baseNumber);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("primeNumber", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->primeNumber);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ThriftDHPublicNumbersResponse &a, ThriftDHPublicNumbersResponse &b) {
  using ::std::swap;
  swap(a.baseNumber, b.baseNumber);
  swap(a.primeNumber, b.primeNumber);
  swap(a.__isset, b.__isset);
}

ThriftDHPublicNumbersResponse::ThriftDHPublicNumbersResponse(const ThriftDHPublicNumbersResponse& other0) {
  baseNumber = other0.baseNumber;
  primeNumber = other0.primeNumber;
  __isset = other0.__isset;
}
ThriftDHPublicNumbersResponse& ThriftDHPublicNumbersResponse::operator=(const ThriftDHPublicNumbersResponse& other1) {
  baseNumber = other1.baseNumber;
  primeNumber = other1.primeNumber;
  __isset = other1.__isset;
  return *this;
}
void ThriftDHPublicNumbersResponse::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ThriftDHPublicNumbersResponse(";
  out << "baseNumber=" << to_string(baseNumber);
  out << ", " << "primeNumber=" << to_string(primeNumber);
  out << ")";
}

} // namespace
