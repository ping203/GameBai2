/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "ThriftPublicMessageEvent_types.h"

#include <algorithm>
#include <ostream>

#include "libs/TToString.h"

namespace es {


ThriftPublicMessageEvent::~ThriftPublicMessageEvent() throw() {
}


void ThriftPublicMessageEvent::__set_message(const std::string& val) {
  this->message = val;
__isset.message = true;
}

void ThriftPublicMessageEvent::__set_userName(const std::string& val) {
  this->userName = val;
__isset.userName = true;
}

void ThriftPublicMessageEvent::__set_zoneId(const int32_t val) {
  this->zoneId = val;
__isset.zoneId = true;
}

void ThriftPublicMessageEvent::__set_roomId(const int32_t val) {
  this->roomId = val;
__isset.roomId = true;
}

void ThriftPublicMessageEvent::__set_esObject(const  ::es::ThriftFlattenedEsObject& val) {
  this->esObject = val;
__isset.esObject = true;
}

uint32_t ThriftPublicMessageEvent::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->message);
          this->__isset.message = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->userName);
          this->__isset.userName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->zoneId);
          this->__isset.zoneId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->roomId);
          this->__isset.roomId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
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

uint32_t ThriftPublicMessageEvent::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ThriftPublicMessageEvent");

  if (this->__isset.message) {
    xfer += oprot->writeFieldBegin("message", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->message);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.userName) {
    xfer += oprot->writeFieldBegin("userName", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->userName);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.zoneId) {
    xfer += oprot->writeFieldBegin("zoneId", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32(this->zoneId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.roomId) {
    xfer += oprot->writeFieldBegin("roomId", ::apache::thrift::protocol::T_I32, 4);
    xfer += oprot->writeI32(this->roomId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.esObject) {
    xfer += oprot->writeFieldBegin("esObject", ::apache::thrift::protocol::T_STRUCT, 5);
    xfer += this->esObject.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ThriftPublicMessageEvent &a, ThriftPublicMessageEvent &b) {
  using ::std::swap;
  swap(a.message, b.message);
  swap(a.userName, b.userName);
  swap(a.zoneId, b.zoneId);
  swap(a.roomId, b.roomId);
  swap(a.esObject, b.esObject);
  swap(a.__isset, b.__isset);
}

ThriftPublicMessageEvent::ThriftPublicMessageEvent(const ThriftPublicMessageEvent& other0) {
  message = other0.message;
  userName = other0.userName;
  zoneId = other0.zoneId;
  roomId = other0.roomId;
  esObject = other0.esObject;
  __isset = other0.__isset;
}
ThriftPublicMessageEvent& ThriftPublicMessageEvent::operator=(const ThriftPublicMessageEvent& other1) {
  message = other1.message;
  userName = other1.userName;
  zoneId = other1.zoneId;
  roomId = other1.roomId;
  esObject = other1.esObject;
  __isset = other1.__isset;
  return *this;
}
void ThriftPublicMessageEvent::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ThriftPublicMessageEvent(";
  out << "message="; (__isset.message ? (out << to_string(message)) : (out << "<null>"));
  out << ", " << "userName="; (__isset.userName ? (out << to_string(userName)) : (out << "<null>"));
  out << ", " << "zoneId="; (__isset.zoneId ? (out << to_string(zoneId)) : (out << "<null>"));
  out << ", " << "roomId="; (__isset.roomId ? (out << to_string(roomId)) : (out << "<null>"));
  out << ", " << "esObject="; (__isset.esObject ? (out << to_string(esObject)) : (out << "<null>"));
  out << ")";
}

} // namespace