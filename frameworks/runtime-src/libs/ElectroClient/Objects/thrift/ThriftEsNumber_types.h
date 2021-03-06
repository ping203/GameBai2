/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ThriftEsNumber_TYPES_H
#define ThriftEsNumber_TYPES_H

#include <iosfwd>

#include "libs/Thrift.h"

#include "libs/TProtocol.h"
#include "libs/TTransport.h"




namespace es {

class ThriftEsNumber;

typedef struct _ThriftEsNumber__isset {
  _ThriftEsNumber__isset() : value(false) {}
  bool value :1;
} _ThriftEsNumber__isset;

class ThriftEsNumber {
 public:

  ThriftEsNumber(const ThriftEsNumber&);
  ThriftEsNumber& operator=(const ThriftEsNumber&);
  ThriftEsNumber() : value(0) {
  }

  virtual ~ThriftEsNumber() throw();
  double value;

  _ThriftEsNumber__isset __isset;

  void __set_value(const double val);

  bool operator == (const ThriftEsNumber & rhs) const
  {
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const ThriftEsNumber &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftEsNumber & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ThriftEsNumber &a, ThriftEsNumber &b);

inline std::ostream& operator<<(std::ostream& out, const ThriftEsNumber& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif
