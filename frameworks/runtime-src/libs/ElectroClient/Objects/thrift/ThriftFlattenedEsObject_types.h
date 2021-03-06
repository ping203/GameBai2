/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ThriftFlattenedEsObject_TYPES_H
#define ThriftFlattenedEsObject_TYPES_H

#include <iosfwd>

#include "libs/Thrift.h"

#include "libs/TProtocol.h"
#include "libs/TTransport.h"




namespace es {

class ThriftFlattenedEsObject;

typedef struct _ThriftFlattenedEsObject__isset {
  _ThriftFlattenedEsObject__isset() : encodedEntries(false) {}
  bool encodedEntries :1;
} _ThriftFlattenedEsObject__isset;

class ThriftFlattenedEsObject {
 public:

  ThriftFlattenedEsObject(const ThriftFlattenedEsObject&);
  ThriftFlattenedEsObject& operator=(const ThriftFlattenedEsObject&);
  ThriftFlattenedEsObject() {
  }

  virtual ~ThriftFlattenedEsObject() throw();
  std::vector<int8_t>  encodedEntries;

  _ThriftFlattenedEsObject__isset __isset;

  void __set_encodedEntries(const std::vector<int8_t> & val);

  bool operator == (const ThriftFlattenedEsObject & rhs) const
  {
    if (!(encodedEntries == rhs.encodedEntries))
      return false;
    return true;
  }
  bool operator != (const ThriftFlattenedEsObject &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftFlattenedEsObject & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ThriftFlattenedEsObject &a, ThriftFlattenedEsObject &b);

inline std::ostream& operator<<(std::ostream& out, const ThriftFlattenedEsObject& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif
