/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "ThriftGatewayKickUserRequest_types.h"

#include <algorithm>
#include <ostream>

#include "libs/TToString.h"

namespace es {


ThriftGatewayKickUserRequest::~ThriftGatewayKickUserRequest() throw() {
}


void ThriftGatewayKickUserRequest::__set_clientId(const int64_t val) {
  this->clientId = val;
__isset.clientId = true;
}

void ThriftGatewayKickUserRequest::__set_error(const  ::es::ThriftErrorType::type val) {
  this->error = val;
__isset.error = true;
}

void ThriftGatewayKickUserRequest::__set_esObject(const  ::es::ThriftFlattenedEsObjectRO& val) {
  this->esObject = val;
__isset.esObject = true;
}

uint32_t ThriftGatewayKickUserRequest::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->clientId);
          this->__isset.clientId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->error = ( ::es::ThriftErrorType::type)ecast0;
          this->__isset.error = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->esObject.read(iprot);
          this->__isset.esObject = true;
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

uint32_t ThriftGatewayKickUserRequest::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ThriftGatewayKickUserRequest");

  if (this->__isset.clientId) {
    xfer += oprot->writeFieldBegin("clientId", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64(this->clientId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.error) {
    xfer += oprot->writeFieldBegin("error", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32((int32_t)this->error);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.esObject) {
    xfer += oprot->writeFieldBegin("esObject", ::apache::thrift::protocol::T_STRUCT, 3);
    xfer += this->esObject.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ThriftGatewayKickUserRequest &a, ThriftGatewayKickUserRequest &b) {
  using ::std::swap;
  swap(a.clientId, b.clientId);
  swap(a.error, b.error);
  swap(a.esObject, b.esObject);
  swap(a.__isset, b.__isset);
}

ThriftGatewayKickUserRequest::ThriftGatewayKickUserRequest(const ThriftGatewayKickUserRequest& other1) {
  clientId = other1.clientId;
  error = other1.error;
  esObject = other1.esObject;
  __isset = other1.__isset;
}
ThriftGatewayKickUserRequest& ThriftGatewayKickUserRequest::operator=(const ThriftGatewayKickUserRequest& other2) {
  clientId = other2.clientId;
  error = other2.error;
  esObject = other2.esObject;
  __isset = other2.__isset;
  return *this;
}
void ThriftGatewayKickUserRequest::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ThriftGatewayKickUserRequest(";
  out << "clientId="; (__isset.clientId ? (out << to_string(clientId)) : (out << "<null>"));
  out << ", " << "error="; (__isset.error ? (out << to_string(error)) : (out << "<null>"));
  out << ", " << "esObject="; (__isset.esObject ? (out << to_string(esObject)) : (out << "<null>"));
  out << ")";
}

} // namespace