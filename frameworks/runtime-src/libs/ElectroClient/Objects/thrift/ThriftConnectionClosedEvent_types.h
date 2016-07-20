/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ThriftConnectionClosedEvent_TYPES_H
#define ThriftConnectionClosedEvent_TYPES_H

#include <iosfwd>

#include "libs/Thrift.h"
#include "libs/TProtocol.h"
#include "libs/TTransport.h"



namespace es {

class ThriftConnectionClosedEvent;

typedef struct _ThriftConnectionClosedEvent__isset {
  _ThriftConnectionClosedEvent__isset() : connectionId(false) {}
  bool connectionId :1;
} _ThriftConnectionClosedEvent__isset;

class ThriftConnectionClosedEvent {
 public:

  ThriftConnectionClosedEvent(const ThriftConnectionClosedEvent&);
  ThriftConnectionClosedEvent& operator=(const ThriftConnectionClosedEvent&);
  ThriftConnectionClosedEvent() : connectionId(0) {
  }

  virtual ~ThriftConnectionClosedEvent() throw();
  int32_t connectionId;

  _ThriftConnectionClosedEvent__isset __isset;

  void __set_connectionId(const int32_t val);

  bool operator == (const ThriftConnectionClosedEvent & rhs) const
  {
    if (__isset.connectionId != rhs.__isset.connectionId)
      return false;
    else if (__isset.connectionId && !(connectionId == rhs.connectionId))
      return false;
    return true;
  }
  bool operator != (const ThriftConnectionClosedEvent &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftConnectionClosedEvent & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ThriftConnectionClosedEvent &a, ThriftConnectionClosedEvent &b);

inline std::ostream& operator<<(std::ostream& out, const ThriftConnectionClosedEvent& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif