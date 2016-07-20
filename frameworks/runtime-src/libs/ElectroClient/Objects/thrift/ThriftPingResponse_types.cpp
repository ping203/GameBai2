/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "ThriftPingResponse_types.h"

#include <algorithm>
#include <ostream>

#include "libs/TToString.h"

namespace es {


ThriftPingResponse::~ThriftPingResponse() throw() {
}


void ThriftPingResponse::__set_globalResponseRequested(const bool val) {
  this->globalResponseRequested = val;
__isset.globalResponseRequested = true;
}

void ThriftPingResponse::__set_pingRequestId(const int32_t val) {
  this->pingRequestId = val;
__isset.pingRequestId = true;
}

uint32_t ThriftPingResponse::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->globalResponseRequested);
          this->__isset.globalResponseRequested = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->pingRequestId);
          this->__isset.pingRequestId = true;
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

uint32_t ThriftPingResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ThriftPingResponse");

  if (this->__isset.globalResponseRequested) {
    xfer += oprot->writeFieldBegin("globalResponseRequested", ::apache::thrift::protocol::T_BOOL, 1);
    xfer += oprot->writeBool(this->globalResponseRequested);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.pingRequestId) {
    xfer += oprot->writeFieldBegin("pingRequestId", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32(this->pingRequestId);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ThriftPingResponse &a, ThriftPingResponse &b) {
  using ::std::swap;
  swap(a.globalResponseRequested, b.globalResponseRequested);
  swap(a.pingRequestId, b.pingRequestId);
  swap(a.__isset, b.__isset);
}

ThriftPingResponse::ThriftPingResponse(const ThriftPingResponse& other0) {
  globalResponseRequested = other0.globalResponseRequested;
  pingRequestId = other0.pingRequestId;
  __isset = other0.__isset;
}
ThriftPingResponse& ThriftPingResponse::operator=(const ThriftPingResponse& other1) {
  globalResponseRequested = other1.globalResponseRequested;
  pingRequestId = other1.pingRequestId;
  __isset = other1.__isset;
  return *this;
}
void ThriftPingResponse::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ThriftPingResponse(";
  out << "globalResponseRequested="; (__isset.globalResponseRequested ? (out << to_string(globalResponseRequested)) : (out << "<null>"));
  out << ", " << "pingRequestId="; (__isset.pingRequestId ? (out << to_string(pingRequestId)) : (out << "<null>"));
  out << ")";
}

} // namespace