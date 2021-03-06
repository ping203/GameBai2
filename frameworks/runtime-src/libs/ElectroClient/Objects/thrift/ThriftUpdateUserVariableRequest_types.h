/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ThriftUpdateUserVariableRequest_TYPES_H
#define ThriftUpdateUserVariableRequest_TYPES_H

#include <iosfwd>

#include "libs/Thrift.h"

#include "libs/TProtocol.h"
#include "libs/TTransport.h"


#include "ThriftFlattenedEsObject_types.h"


namespace es {

class ThriftUpdateUserVariableRequest;

typedef struct _ThriftUpdateUserVariableRequest__isset {
  _ThriftUpdateUserVariableRequest__isset() : name(false), value(false) {}
  bool name :1;
  bool value :1;
} _ThriftUpdateUserVariableRequest__isset;

class ThriftUpdateUserVariableRequest {
 public:

  ThriftUpdateUserVariableRequest(const ThriftUpdateUserVariableRequest&);
  ThriftUpdateUserVariableRequest& operator=(const ThriftUpdateUserVariableRequest&);
  ThriftUpdateUserVariableRequest() : name() {
  }

  virtual ~ThriftUpdateUserVariableRequest() throw();
  std::string name;
   ::es::ThriftFlattenedEsObject value;

  _ThriftUpdateUserVariableRequest__isset __isset;

  void __set_name(const std::string& val);

  void __set_value(const  ::es::ThriftFlattenedEsObject& val);

  bool operator == (const ThriftUpdateUserVariableRequest & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const ThriftUpdateUserVariableRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftUpdateUserVariableRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ThriftUpdateUserVariableRequest &a, ThriftUpdateUserVariableRequest &b);

inline std::ostream& operator<<(std::ostream& out, const ThriftUpdateUserVariableRequest& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif
