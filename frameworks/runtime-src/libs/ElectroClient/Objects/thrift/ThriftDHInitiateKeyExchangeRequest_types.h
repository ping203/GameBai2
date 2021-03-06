/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ThriftDHInitiateKeyExchangeRequest_TYPES_H
#define ThriftDHInitiateKeyExchangeRequest_TYPES_H

#include <iosfwd>

#include "libs/Thrift.h"

#include "libs/TProtocol.h"
#include "libs/TTransport.h"


#include "ThriftFlattenedEsObject_types.h"


namespace es {

class ThriftDHInitiateKeyExchangeRequest;


class ThriftDHInitiateKeyExchangeRequest {
 public:

  ThriftDHInitiateKeyExchangeRequest(const ThriftDHInitiateKeyExchangeRequest&);
  ThriftDHInitiateKeyExchangeRequest& operator=(const ThriftDHInitiateKeyExchangeRequest&);
  ThriftDHInitiateKeyExchangeRequest() {
  }

  virtual ~ThriftDHInitiateKeyExchangeRequest() throw();

  bool operator == (const ThriftDHInitiateKeyExchangeRequest & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ThriftDHInitiateKeyExchangeRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftDHInitiateKeyExchangeRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ThriftDHInitiateKeyExchangeRequest &a, ThriftDHInitiateKeyExchangeRequest &b);

inline std::ostream& operator<<(std::ostream& out, const ThriftDHInitiateKeyExchangeRequest& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif
