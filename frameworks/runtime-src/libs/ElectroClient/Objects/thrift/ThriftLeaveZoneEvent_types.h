/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ThriftLeaveZoneEvent_TYPES_H
#define ThriftLeaveZoneEvent_TYPES_H

#include <iosfwd>

#include "libs/Thrift.h"

#include "libs/TProtocol.h"
#include "libs/TTransport.h"




namespace es {

class ThriftLeaveZoneEvent;

typedef struct _ThriftLeaveZoneEvent__isset {
  _ThriftLeaveZoneEvent__isset() : zoneId(false) {}
  bool zoneId :1;
} _ThriftLeaveZoneEvent__isset;

class ThriftLeaveZoneEvent {
 public:

  ThriftLeaveZoneEvent(const ThriftLeaveZoneEvent&);
  ThriftLeaveZoneEvent& operator=(const ThriftLeaveZoneEvent&);
  ThriftLeaveZoneEvent() : zoneId(0) {
  }

  virtual ~ThriftLeaveZoneEvent() throw();
  int32_t zoneId;

  _ThriftLeaveZoneEvent__isset __isset;

  void __set_zoneId(const int32_t val);

  bool operator == (const ThriftLeaveZoneEvent & rhs) const
  {
    if (!(zoneId == rhs.zoneId))
      return false;
    return true;
  }
  bool operator != (const ThriftLeaveZoneEvent &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftLeaveZoneEvent & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ThriftLeaveZoneEvent &a, ThriftLeaveZoneEvent &b);

inline std::ostream& operator<<(std::ostream& out, const ThriftLeaveZoneEvent& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif
