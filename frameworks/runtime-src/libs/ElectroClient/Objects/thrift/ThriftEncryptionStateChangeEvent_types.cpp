/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "ThriftEncryptionStateChangeEvent_types.h"

#include <algorithm>
#include <ostream>

#include "libs/TToString.h"

namespace es {


ThriftEncryptionStateChangeEvent::~ThriftEncryptionStateChangeEvent() throw() {
}


void ThriftEncryptionStateChangeEvent::__set_encryptionOn(const bool val) {
  this->encryptionOn = val;
}

uint32_t ThriftEncryptionStateChangeEvent::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readBool(this->encryptionOn);
          this->__isset.encryptionOn = true;
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

uint32_t ThriftEncryptionStateChangeEvent::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ThriftEncryptionStateChangeEvent");

  xfer += oprot->writeFieldBegin("encryptionOn", ::apache::thrift::protocol::T_BOOL, 1);
  xfer += oprot->writeBool(this->encryptionOn);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ThriftEncryptionStateChangeEvent &a, ThriftEncryptionStateChangeEvent &b) {
  using ::std::swap;
  swap(a.encryptionOn, b.encryptionOn);
  swap(a.__isset, b.__isset);
}

ThriftEncryptionStateChangeEvent::ThriftEncryptionStateChangeEvent(const ThriftEncryptionStateChangeEvent& other0) {
  encryptionOn = other0.encryptionOn;
  __isset = other0.__isset;
}
ThriftEncryptionStateChangeEvent& ThriftEncryptionStateChangeEvent::operator=(const ThriftEncryptionStateChangeEvent& other1) {
  encryptionOn = other1.encryptionOn;
  __isset = other1.__isset;
  return *this;
}
void ThriftEncryptionStateChangeEvent::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ThriftEncryptionStateChangeEvent(";
  out << "encryptionOn=" << to_string(encryptionOn);
  out << ")";
}

} // namespace