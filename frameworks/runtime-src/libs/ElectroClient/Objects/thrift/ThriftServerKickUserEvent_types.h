/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ThriftServerKickUserEvent_TYPES_H
#define ThriftServerKickUserEvent_TYPES_H

#include <iosfwd>

#include "libs/Thrift.h"

#include "libs/TProtocol.h"
#include "libs/TTransport.h"


#include "ThriftFlattenedEsObjectRO_types.h"
#include "ThriftErrorType_types.h"


namespace es {

class ThriftServerKickUserEvent;

typedef struct _ThriftServerKickUserEvent__isset {
  _ThriftServerKickUserEvent__isset() : error(false), esObject(false) {}
  bool error :1;
  bool esObject :1;
} _ThriftServerKickUserEvent__isset;

class ThriftServerKickUserEvent {
 public:

  ThriftServerKickUserEvent(const ThriftServerKickUserEvent&);
  ThriftServerKickUserEvent& operator=(const ThriftServerKickUserEvent&);
  ThriftServerKickUserEvent() : error(( ::es::ThriftErrorType::type)0) {
  }

  virtual ~ThriftServerKickUserEvent() throw();
   ::es::ThriftErrorType::type error;
   ::es::ThriftFlattenedEsObjectRO esObject;

  _ThriftServerKickUserEvent__isset __isset;

  void __set_error(const  ::es::ThriftErrorType::type val);

  void __set_esObject(const  ::es::ThriftFlattenedEsObjectRO& val);

  bool operator == (const ThriftServerKickUserEvent & rhs) const
  {
    if (__isset.error != rhs.__isset.error)
      return false;
    else if (__isset.error && !(error == rhs.error))
      return false;
    if (__isset.esObject != rhs.__isset.esObject)
      return false;
    else if (__isset.esObject && !(esObject == rhs.esObject))
      return false;
    return true;
  }
  bool operator != (const ThriftServerKickUserEvent &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftServerKickUserEvent & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ThriftServerKickUserEvent &a, ThriftServerKickUserEvent &b);

inline std::ostream& operator<<(std::ostream& out, const ThriftServerKickUserEvent& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif