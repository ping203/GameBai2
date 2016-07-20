/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "ThriftPrivateMessageRequest_types.h"

#include <algorithm>
#include <ostream>

#include"libs/TToString.h"

namespace es {


ThriftPrivateMessageRequest::~ThriftPrivateMessageRequest() throw() {
}


void ThriftPrivateMessageRequest::__set_message(const std::string& val) {
  this->message = val;
__isset.message = true;
}

void ThriftPrivateMessageRequest::__set_userNames(const std::vector<std::string> & val) {
  this->userNames = val;
__isset.userNames = true;
}

void ThriftPrivateMessageRequest::__set_esObject(const  ::es::ThriftFlattenedEsObject& val) {
  this->esObject = val;
__isset.esObject = true;
}

uint32_t ThriftPrivateMessageRequest::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->userNames.clear();
            uint32_t _size0;
            ::apache::thrift::protocol::TType _etype3;
            xfer += iprot->readListBegin(_etype3, _size0);
            this->userNames.resize(_size0);
            uint32_t _i4;
            for (_i4 = 0; _i4 < _size0; ++_i4)
            {
              xfer += iprot->readString(this->userNames[_i4]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.userNames = true;
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

uint32_t ThriftPrivateMessageRequest::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ThriftPrivateMessageRequest");

  if (this->__isset.message) {
    xfer += oprot->writeFieldBegin("message", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->message);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.userNames) {
    xfer += oprot->writeFieldBegin("userNames", ::apache::thrift::protocol::T_LIST, 2);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->userNames.size()));
      std::vector<std::string> ::const_iterator _iter5;
      for (_iter5 = this->userNames.begin(); _iter5 != this->userNames.end(); ++_iter5)
      {
        xfer += oprot->writeString((*_iter5));
      }
      xfer += oprot->writeListEnd();
    }
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

void swap(ThriftPrivateMessageRequest &a, ThriftPrivateMessageRequest &b) {
  using ::std::swap;
  swap(a.message, b.message);
  swap(a.userNames, b.userNames);
  swap(a.esObject, b.esObject);
  swap(a.__isset, b.__isset);
}

ThriftPrivateMessageRequest::ThriftPrivateMessageRequest(const ThriftPrivateMessageRequest& other6) {
  message = other6.message;
  userNames = other6.userNames;
  esObject = other6.esObject;
  __isset = other6.__isset;
}
ThriftPrivateMessageRequest& ThriftPrivateMessageRequest::operator=(const ThriftPrivateMessageRequest& other7) {
  message = other7.message;
  userNames = other7.userNames;
  esObject = other7.esObject;
  __isset = other7.__isset;
  return *this;
}
void ThriftPrivateMessageRequest::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ThriftPrivateMessageRequest(";
  out << "message="; (__isset.message ? (out << to_string(message)) : (out << "<null>"));
  out << ", " << "userNames="; (__isset.userNames ? (out << to_string(userNames)) : (out << "<null>"));
  out << ", " << "esObject="; (__isset.esObject ? (out << to_string(esObject)) : (out << "<null>"));
  out << ")";
}

} // namespace