/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "ThriftFindGamesRequest_types.h"

#include <algorithm>
#include <ostream>

#include "libs/TToString.h"

namespace es {


ThriftFindGamesRequest::~ThriftFindGamesRequest() throw() {
}


void ThriftFindGamesRequest::__set_searchCriteria(const  ::es::ThriftSearchCriteria& val) {
  this->searchCriteria = val;
}

uint32_t ThriftFindGamesRequest::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->searchCriteria.read(iprot);
          this->__isset.searchCriteria = true;
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

uint32_t ThriftFindGamesRequest::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ThriftFindGamesRequest");

  xfer += oprot->writeFieldBegin("searchCriteria", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->searchCriteria.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ThriftFindGamesRequest &a, ThriftFindGamesRequest &b) {
  using ::std::swap;
  swap(a.searchCriteria, b.searchCriteria);
  swap(a.__isset, b.__isset);
}

ThriftFindGamesRequest::ThriftFindGamesRequest(const ThriftFindGamesRequest& other0) {
  searchCriteria = other0.searchCriteria;
  __isset = other0.__isset;
}
ThriftFindGamesRequest& ThriftFindGamesRequest::operator=(const ThriftFindGamesRequest& other1) {
  searchCriteria = other1.searchCriteria;
  __isset = other1.__isset;
  return *this;
}
void ThriftFindGamesRequest::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ThriftFindGamesRequest(";
  out << "searchCriteria=" << to_string(searchCriteria);
  out << ")";
}

} // namespace