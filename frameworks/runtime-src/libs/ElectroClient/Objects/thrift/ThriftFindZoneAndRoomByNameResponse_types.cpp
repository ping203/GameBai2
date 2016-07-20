/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "ThriftFindZoneAndRoomByNameResponse_types.h"

#include <algorithm>
#include <ostream>

#include "libs/TToString.h"

namespace es {


ThriftFindZoneAndRoomByNameResponse::~ThriftFindZoneAndRoomByNameResponse() throw() {
}


void ThriftFindZoneAndRoomByNameResponse::__set_roomAndZoneList(const std::vector<std::vector<int32_t> > & val) {
  this->roomAndZoneList = val;
}

uint32_t ThriftFindZoneAndRoomByNameResponse::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            this->roomAndZoneList.clear();
            uint32_t _size0;
            ::apache::thrift::protocol::TType _etype3;
            xfer += iprot->readListBegin(_etype3, _size0);
            this->roomAndZoneList.resize(_size0);
            uint32_t _i4;
            for (_i4 = 0; _i4 < _size0; ++_i4)
            {
              {
                this->roomAndZoneList[_i4].clear();
                uint32_t _size5;
                ::apache::thrift::protocol::TType _etype8;
                xfer += iprot->readListBegin(_etype8, _size5);
                this->roomAndZoneList[_i4].resize(_size5);
                uint32_t _i9;
                for (_i9 = 0; _i9 < _size5; ++_i9)
                {
                  xfer += iprot->readI32(this->roomAndZoneList[_i4][_i9]);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.roomAndZoneList = true;
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

uint32_t ThriftFindZoneAndRoomByNameResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ThriftFindZoneAndRoomByNameResponse");

  xfer += oprot->writeFieldBegin("roomAndZoneList", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->roomAndZoneList.size()));
    std::vector<std::vector<int32_t> > ::const_iterator _iter10;
    for (_iter10 = this->roomAndZoneList.begin(); _iter10 != this->roomAndZoneList.end(); ++_iter10)
    {
      {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I32, static_cast<uint32_t>((*_iter10).size()));
        std::vector<int32_t> ::const_iterator _iter11;
        for (_iter11 = (*_iter10).begin(); _iter11 != (*_iter10).end(); ++_iter11)
        {
          xfer += oprot->writeI32((*_iter11));
        }
        xfer += oprot->writeListEnd();
      }
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ThriftFindZoneAndRoomByNameResponse &a, ThriftFindZoneAndRoomByNameResponse &b) {
  using ::std::swap;
  swap(a.roomAndZoneList, b.roomAndZoneList);
  swap(a.__isset, b.__isset);
}

ThriftFindZoneAndRoomByNameResponse::ThriftFindZoneAndRoomByNameResponse(const ThriftFindZoneAndRoomByNameResponse& other12) {
  roomAndZoneList = other12.roomAndZoneList;
  __isset = other12.__isset;
}
ThriftFindZoneAndRoomByNameResponse& ThriftFindZoneAndRoomByNameResponse::operator=(const ThriftFindZoneAndRoomByNameResponse& other13) {
  roomAndZoneList = other13.roomAndZoneList;
  __isset = other13.__isset;
  return *this;
}
void ThriftFindZoneAndRoomByNameResponse::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ThriftFindZoneAndRoomByNameResponse(";
  out << "roomAndZoneList=" << to_string(roomAndZoneList);
  out << ")";
}

} // namespace