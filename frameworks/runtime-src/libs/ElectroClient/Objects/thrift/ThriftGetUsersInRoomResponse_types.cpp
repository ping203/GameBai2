/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "ThriftGetUsersInRoomResponse_types.h"

#include <algorithm>
#include <ostream>

#include "libs/TToString.h"

namespace es {


ThriftGetUsersInRoomResponse::~ThriftGetUsersInRoomResponse() throw() {
}


void ThriftGetUsersInRoomResponse::__set_zoneId(const int32_t val) {
  this->zoneId = val;
}

void ThriftGetUsersInRoomResponse::__set_roomId(const int32_t val) {
  this->roomId = val;
}

void ThriftGetUsersInRoomResponse::__set_users(const std::vector< ::es::ThriftUserListEntry> & val) {
  this->users = val;
}

uint32_t ThriftGetUsersInRoomResponse::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI32(this->zoneId);
          this->__isset.zoneId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->roomId);
          this->__isset.roomId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->users.clear();
            uint32_t _size0;
            ::apache::thrift::protocol::TType _etype3;
            xfer += iprot->readListBegin(_etype3, _size0);
            this->users.resize(_size0);
            uint32_t _i4;
            for (_i4 = 0; _i4 < _size0; ++_i4)
            {
              xfer += this->users[_i4].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.users = true;
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

uint32_t ThriftGetUsersInRoomResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ThriftGetUsersInRoomResponse");

  xfer += oprot->writeFieldBegin("zoneId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->zoneId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("roomId", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->roomId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("users", ::apache::thrift::protocol::T_LIST, 3);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->users.size()));
    std::vector< ::es::ThriftUserListEntry> ::const_iterator _iter5;
    for (_iter5 = this->users.begin(); _iter5 != this->users.end(); ++_iter5)
    {
      xfer += (*_iter5).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ThriftGetUsersInRoomResponse &a, ThriftGetUsersInRoomResponse &b) {
  using ::std::swap;
  swap(a.zoneId, b.zoneId);
  swap(a.roomId, b.roomId);
  swap(a.users, b.users);
  swap(a.__isset, b.__isset);
}

ThriftGetUsersInRoomResponse::ThriftGetUsersInRoomResponse(const ThriftGetUsersInRoomResponse& other6) {
  zoneId = other6.zoneId;
  roomId = other6.roomId;
  users = other6.users;
  __isset = other6.__isset;
}
ThriftGetUsersInRoomResponse& ThriftGetUsersInRoomResponse::operator=(const ThriftGetUsersInRoomResponse& other7) {
  zoneId = other7.zoneId;
  roomId = other7.roomId;
  users = other7.users;
  __isset = other7.__isset;
  return *this;
}
void ThriftGetUsersInRoomResponse::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ThriftGetUsersInRoomResponse(";
  out << "zoneId=" << to_string(zoneId);
  out << ", " << "roomId=" << to_string(roomId);
  out << ", " << "users=" << to_string(users);
  out << ")";
}

} // namespace