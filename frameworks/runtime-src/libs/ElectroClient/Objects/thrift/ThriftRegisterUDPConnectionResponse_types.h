/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ThriftRegisterUDPConnectionResponse_TYPES_H
#define ThriftRegisterUDPConnectionResponse_TYPES_H

#include <iosfwd>

#include "libs/Thrift.h"

#include "libs/TProtocol.h"
#include "libs/TTransport.h"


#include "ThriftErrorType_types.h"


namespace es {

class ThriftRegisterUDPConnectionResponse;

typedef struct _ThriftRegisterUDPConnectionResponse__isset {
  _ThriftRegisterUDPConnectionResponse__isset() : successful(false), sessionKey(false), error(false) {}
  bool successful :1;
  bool sessionKey :1;
  bool error :1;
} _ThriftRegisterUDPConnectionResponse__isset;

class ThriftRegisterUDPConnectionResponse {
 public:

  ThriftRegisterUDPConnectionResponse(const ThriftRegisterUDPConnectionResponse&);
  ThriftRegisterUDPConnectionResponse& operator=(const ThriftRegisterUDPConnectionResponse&);
  ThriftRegisterUDPConnectionResponse() : successful(0), sessionKey(0), error(( ::es::ThriftErrorType::type)0) {
  }

  virtual ~ThriftRegisterUDPConnectionResponse() throw();
  bool successful;
  int32_t sessionKey;
   ::es::ThriftErrorType::type error;

  _ThriftRegisterUDPConnectionResponse__isset __isset;

  void __set_successful(const bool val);

  void __set_sessionKey(const int32_t val);

  void __set_error(const  ::es::ThriftErrorType::type val);

  bool operator == (const ThriftRegisterUDPConnectionResponse & rhs) const
  {
    if (!(successful == rhs.successful))
      return false;
    if (!(sessionKey == rhs.sessionKey))
      return false;
    if (!(error == rhs.error))
      return false;
    return true;
  }
  bool operator != (const ThriftRegisterUDPConnectionResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftRegisterUDPConnectionResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ThriftRegisterUDPConnectionResponse &a, ThriftRegisterUDPConnectionResponse &b);

inline std::ostream& operator<<(std::ostream& out, const ThriftRegisterUDPConnectionResponse& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif
