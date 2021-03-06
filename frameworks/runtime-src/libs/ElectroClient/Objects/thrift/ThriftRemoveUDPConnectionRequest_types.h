/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ThriftRemoveUDPConnectionRequest_TYPES_H
#define ThriftRemoveUDPConnectionRequest_TYPES_H

#include <iosfwd>

#include "libs/Thrift.h"

#include "libs/TProtocol.h"
#include "libs/TTransport.h"




namespace es {

class ThriftRemoveUDPConnectionRequest;

typedef struct _ThriftRemoveUDPConnectionRequest__isset {
  _ThriftRemoveUDPConnectionRequest__isset() : port(false) {}
  bool port :1;
} _ThriftRemoveUDPConnectionRequest__isset;

class ThriftRemoveUDPConnectionRequest {
 public:

  ThriftRemoveUDPConnectionRequest(const ThriftRemoveUDPConnectionRequest&);
  ThriftRemoveUDPConnectionRequest& operator=(const ThriftRemoveUDPConnectionRequest&);
  ThriftRemoveUDPConnectionRequest() : port(0) {
  }

  virtual ~ThriftRemoveUDPConnectionRequest() throw();
  int32_t port;

  _ThriftRemoveUDPConnectionRequest__isset __isset;

  void __set_port(const int32_t val);

  bool operator == (const ThriftRemoveUDPConnectionRequest & rhs) const
  {
    if (!(port == rhs.port))
      return false;
    return true;
  }
  bool operator != (const ThriftRemoveUDPConnectionRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftRemoveUDPConnectionRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ThriftRemoveUDPConnectionRequest &a, ThriftRemoveUDPConnectionRequest &b);

inline std::ostream& operator<<(std::ostream& out, const ThriftRemoveUDPConnectionRequest& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif
