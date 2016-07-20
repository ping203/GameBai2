/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ThriftUpdateRoomVariableRequest_TYPES_H
#define ThriftUpdateRoomVariableRequest_TYPES_H

#include <iosfwd>

#include "libs/Thrift.h"

#include "libs/TProtocol.h"
#include "libs/TTransport.h"


#include "ThriftFlattenedEsObject_types.h"


namespace es {

class ThriftUpdateRoomVariableRequest;

typedef struct _ThriftUpdateRoomVariableRequest__isset {
  _ThriftUpdateRoomVariableRequest__isset() : zoneId(false), roomId(false), name(false), valueChanged(false), value(false), lockStatusChanged(false), locked(false) {}
  bool zoneId :1;
  bool roomId :1;
  bool name :1;
  bool valueChanged :1;
  bool value :1;
  bool lockStatusChanged :1;
  bool locked :1;
} _ThriftUpdateRoomVariableRequest__isset;

class ThriftUpdateRoomVariableRequest {
 public:

  ThriftUpdateRoomVariableRequest(const ThriftUpdateRoomVariableRequest&);
  ThriftUpdateRoomVariableRequest& operator=(const ThriftUpdateRoomVariableRequest&);
  ThriftUpdateRoomVariableRequest() : zoneId(0), roomId(0), name(), valueChanged(0), lockStatusChanged(0), locked(0) {
  }

  virtual ~ThriftUpdateRoomVariableRequest() throw();
  int32_t zoneId;
  int32_t roomId;
  std::string name;
  bool valueChanged;
   ::es::ThriftFlattenedEsObject value;
  bool lockStatusChanged;
  bool locked;

  _ThriftUpdateRoomVariableRequest__isset __isset;

  void __set_zoneId(const int32_t val);

  void __set_roomId(const int32_t val);

  void __set_name(const std::string& val);

  void __set_valueChanged(const bool val);

  void __set_value(const  ::es::ThriftFlattenedEsObject& val);

  void __set_lockStatusChanged(const bool val);

  void __set_locked(const bool val);

  bool operator == (const ThriftUpdateRoomVariableRequest & rhs) const
  {
    if (!(zoneId == rhs.zoneId))
      return false;
    if (!(roomId == rhs.roomId))
      return false;
    if (!(name == rhs.name))
      return false;
    if (!(valueChanged == rhs.valueChanged))
      return false;
    if (!(value == rhs.value))
      return false;
    if (!(lockStatusChanged == rhs.lockStatusChanged))
      return false;
    if (!(locked == rhs.locked))
      return false;
    return true;
  }
  bool operator != (const ThriftUpdateRoomVariableRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftUpdateRoomVariableRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ThriftUpdateRoomVariableRequest &a, ThriftUpdateRoomVariableRequest &b);

inline std::ostream& operator<<(std::ostream& out, const ThriftUpdateRoomVariableRequest& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif