/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "ThriftGetZonesRequest_types.h"

#include <algorithm>
#include <ostream>

#include "libs/TToString.h"

namespace es {


ThriftGetZonesRequest::~ThriftGetZonesRequest() throw() {
}


uint32_t ThriftGetZonesRequest::read(::apache::thrift::protocol::TProtocol* iprot) {

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
    xfer += iprot->skip(ftype);
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ThriftGetZonesRequest::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ThriftGetZonesRequest");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ThriftGetZonesRequest &a, ThriftGetZonesRequest &b) {
  using ::std::swap;
  (void) a;
  (void) b;
}

ThriftGetZonesRequest::ThriftGetZonesRequest(const ThriftGetZonesRequest& other0) {
  (void) other0;
}
ThriftGetZonesRequest& ThriftGetZonesRequest::operator=(const ThriftGetZonesRequest& other1) {
  (void) other1;
  return *this;
}
void ThriftGetZonesRequest::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ThriftGetZonesRequest(";
  out << ")";
}

} // namespace