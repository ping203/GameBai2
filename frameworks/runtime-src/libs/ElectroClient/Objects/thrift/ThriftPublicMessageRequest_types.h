/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ThriftPublicMessageRequest_TYPES_H
#define ThriftPublicMessageRequest_TYPES_H

#include <iosfwd>

#include "libs/Thrift.h"
//
#include "libs/TProtocol.h"
#include "libs/TTransport.h"

//
#include "ThriftFlattenedEsObject_types.h"


namespace es {

class ThriftPublicMessageRequest;

typedef struct _ThriftPublicMessageRequest__isset {
  _ThriftPublicMessageRequest__isset() : zoneId(false), roomId(false), message(false), esObject(false) {}
  bool zoneId :1;
  bool roomId :1;
  bool message :1;
  bool esObject :1;
} _ThriftPublicMessageRequest__isset;

class ThriftPublicMessageRequest {
 public:

  ThriftPublicMessageRequest(const ThriftPublicMessageRequest&);
  ThriftPublicMessageRequest& operator=(const ThriftPublicMessageRequest&);
  ThriftPublicMessageRequest() : zoneId(0), roomId(0), message() {
  }

  virtual ~ThriftPublicMessageRequest() throw();
  int32_t zoneId;
  int32_t roomId;
  std::string message;
   ::es::ThriftFlattenedEsObject esObject;

  _ThriftPublicMessageRequest__isset __isset;

  void __set_zoneId(const int32_t val);

  void __set_roomId(const int32_t val);

  void __set_message(const std::string& val);

  void __set_esObject(const  ::es::ThriftFlattenedEsObject& val);

  bool operator == (const ThriftPublicMessageRequest & rhs) const
  {
    if (__isset.zoneId != rhs.__isset.zoneId)
      return false;
    else if (__isset.zoneId && !(zoneId == rhs.zoneId))
      return false;
    if (__isset.roomId != rhs.__isset.roomId)
      return false;
    else if (__isset.roomId && !(roomId == rhs.roomId))
      return false;
    if (__isset.message != rhs.__isset.message)
      return false;
    else if (__isset.message && !(message == rhs.message))
      return false;
    if (__isset.esObject != rhs.__isset.esObject)
      return false;
    else if (__isset.esObject && !(esObject == rhs.esObject))
      return false;
    return true;
  }
  bool operator != (const ThriftPublicMessageRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftPublicMessageRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ThriftPublicMessageRequest &a, ThriftPublicMessageRequest &b);

inline std::ostream& operator<<(std::ostream& out, const ThriftPublicMessageRequest& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif