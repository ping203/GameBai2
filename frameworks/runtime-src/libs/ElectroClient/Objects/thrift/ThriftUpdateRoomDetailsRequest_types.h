/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ThriftUpdateRoomDetailsRequest_TYPES_H
#define ThriftUpdateRoomDetailsRequest_TYPES_H

#include <iosfwd>

#include "libs/Thrift.h"

#include "libs/TProtocol.h"
#include "libs/TTransport.h"




namespace es {

class ThriftUpdateRoomDetailsRequest;

typedef struct _ThriftUpdateRoomDetailsRequest__isset {
  _ThriftUpdateRoomDetailsRequest__isset() : zoneId(false), roomId(false), capacityUpdate(false), capacity(false), roomDescriptionUpdate(false), roomDescription(false), roomNameUpdate(false), roomName(false), passwordUpdate(false), password(false), hiddenUpdate(false), hidden(false) {}
  bool zoneId :1;
  bool roomId :1;
  bool capacityUpdate :1;
  bool capacity :1;
  bool roomDescriptionUpdate :1;
  bool roomDescription :1;
  bool roomNameUpdate :1;
  bool roomName :1;
  bool passwordUpdate :1;
  bool password :1;
  bool hiddenUpdate :1;
  bool hidden :1;
} _ThriftUpdateRoomDetailsRequest__isset;

class ThriftUpdateRoomDetailsRequest {
 public:

  ThriftUpdateRoomDetailsRequest(const ThriftUpdateRoomDetailsRequest&);
  ThriftUpdateRoomDetailsRequest& operator=(const ThriftUpdateRoomDetailsRequest&);
  ThriftUpdateRoomDetailsRequest() : zoneId(0), roomId(0), capacityUpdate(0), capacity(0), roomDescriptionUpdate(0), roomDescription(), roomNameUpdate(0), roomName(), passwordUpdate(0), password(), hiddenUpdate(0), hidden(0) {
  }

  virtual ~ThriftUpdateRoomDetailsRequest() throw();
  int32_t zoneId;
  int32_t roomId;
  bool capacityUpdate;
  int32_t capacity;
  bool roomDescriptionUpdate;
  std::string roomDescription;
  bool roomNameUpdate;
  std::string roomName;
  bool passwordUpdate;
  std::string password;
  bool hiddenUpdate;
  bool hidden;

  _ThriftUpdateRoomDetailsRequest__isset __isset;

  void __set_zoneId(const int32_t val);

  void __set_roomId(const int32_t val);

  void __set_capacityUpdate(const bool val);

  void __set_capacity(const int32_t val);

  void __set_roomDescriptionUpdate(const bool val);

  void __set_roomDescription(const std::string& val);

  void __set_roomNameUpdate(const bool val);

  void __set_roomName(const std::string& val);

  void __set_passwordUpdate(const bool val);

  void __set_password(const std::string& val);

  void __set_hiddenUpdate(const bool val);

  void __set_hidden(const bool val);

  bool operator == (const ThriftUpdateRoomDetailsRequest & rhs) const
  {
    if (!(zoneId == rhs.zoneId))
      return false;
    if (!(roomId == rhs.roomId))
      return false;
    if (!(capacityUpdate == rhs.capacityUpdate))
      return false;
    if (!(capacity == rhs.capacity))
      return false;
    if (!(roomDescriptionUpdate == rhs.roomDescriptionUpdate))
      return false;
    if (!(roomDescription == rhs.roomDescription))
      return false;
    if (!(roomNameUpdate == rhs.roomNameUpdate))
      return false;
    if (!(roomName == rhs.roomName))
      return false;
    if (!(passwordUpdate == rhs.passwordUpdate))
      return false;
    if (!(password == rhs.password))
      return false;
    if (!(hiddenUpdate == rhs.hiddenUpdate))
      return false;
    if (!(hidden == rhs.hidden))
      return false;
    return true;
  }
  bool operator != (const ThriftUpdateRoomDetailsRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftUpdateRoomDetailsRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ThriftUpdateRoomDetailsRequest &a, ThriftUpdateRoomDetailsRequest &b);

inline std::ostream& operator<<(std::ostream& out, const ThriftUpdateRoomDetailsRequest& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif