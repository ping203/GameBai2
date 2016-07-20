/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ThriftAddBuddiesResponse_TYPES_H
#define ThriftAddBuddiesResponse_TYPES_H

#include <iosfwd>

#include "libs/Thrift.h"

#include "libs/TProtocol.h"
#include "libs/TTransport.h"




namespace es {

class ThriftAddBuddiesResponse;

typedef struct _ThriftAddBuddiesResponse__isset {
  _ThriftAddBuddiesResponse__isset() : buddiesAdded(false), buddiesNotAdded(false) {}
  bool buddiesAdded :1;
  bool buddiesNotAdded :1;
} _ThriftAddBuddiesResponse__isset;

class ThriftAddBuddiesResponse {
 public:

  ThriftAddBuddiesResponse(const ThriftAddBuddiesResponse&);
  ThriftAddBuddiesResponse& operator=(const ThriftAddBuddiesResponse&);
  ThriftAddBuddiesResponse() {
  }

  virtual ~ThriftAddBuddiesResponse() throw();
  std::vector<std::string>  buddiesAdded;
  std::vector<std::string>  buddiesNotAdded;

  _ThriftAddBuddiesResponse__isset __isset;

  void __set_buddiesAdded(const std::vector<std::string> & val);

  void __set_buddiesNotAdded(const std::vector<std::string> & val);

  bool operator == (const ThriftAddBuddiesResponse & rhs) const
  {
    if (!(buddiesAdded == rhs.buddiesAdded))
      return false;
    if (!(buddiesNotAdded == rhs.buddiesNotAdded))
      return false;
    return true;
  }
  bool operator != (const ThriftAddBuddiesResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftAddBuddiesResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ThriftAddBuddiesResponse &a, ThriftAddBuddiesResponse &b);

inline std::ostream& operator<<(std::ostream& out, const ThriftAddBuddiesResponse& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif