/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "ThriftJoinGameRequest_types.h"

#include <algorithm>
#include <ostream>

#include "libs/TToString.h"

namespace es {


ThriftJoinGameRequest::~ThriftJoinGameRequest() throw() {
}


void ThriftJoinGameRequest::__set_gameId(const int32_t val) {
  this->gameId = val;
}

void ThriftJoinGameRequest::__set_password(const std::string& val) {
  this->password = val;
}

uint32_t ThriftJoinGameRequest::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->gameId);
          this->__isset.gameId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->password);
          this->__isset.password = true;
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

uint32_t ThriftJoinGameRequest::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ThriftJoinGameRequest");

  xfer += oprot->writeFieldBegin("gameId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->gameId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("password", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->password);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ThriftJoinGameRequest &a, ThriftJoinGameRequest &b) {
  using ::std::swap;
  swap(a.gameId, b.gameId);
  swap(a.password, b.password);
  swap(a.__isset, b.__isset);
}

ThriftJoinGameRequest::ThriftJoinGameRequest(const ThriftJoinGameRequest& other0) {
  gameId = other0.gameId;
  password = other0.password;
  __isset = other0.__isset;
}
ThriftJoinGameRequest& ThriftJoinGameRequest::operator=(const ThriftJoinGameRequest& other1) {
  gameId = other1.gameId;
  password = other1.password;
  __isset = other1.__isset;
  return *this;
}
void ThriftJoinGameRequest::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ThriftJoinGameRequest(";
  out << "gameId=" << to_string(gameId);
  out << ", " << "password=" << to_string(password);
  out << ")";
}

} // namespace
