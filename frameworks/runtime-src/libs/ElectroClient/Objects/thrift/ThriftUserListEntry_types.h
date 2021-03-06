/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ThriftUserListEntry_TYPES_H
#define ThriftUserListEntry_TYPES_H

#include <iosfwd>

#include "libs/Thrift.h"

#include "libs/TProtocol.h"
#include "libs/TTransport.h"


#include "ThriftFlattenedEsObject_types.h"
#include "ThriftUserVariable_types.h"


namespace es {

class ThriftUserListEntry;

typedef struct _ThriftUserListEntry__isset {
  _ThriftUserListEntry__isset() : userName(false), userVariables(false), sendingVideo(false), videoStreamName(false), roomOperator(false) {}
  bool userName :1;
  bool userVariables :1;
  bool sendingVideo :1;
  bool videoStreamName :1;
  bool roomOperator :1;
} _ThriftUserListEntry__isset;

class ThriftUserListEntry {
 public:

  ThriftUserListEntry(const ThriftUserListEntry&);
  ThriftUserListEntry& operator=(const ThriftUserListEntry&);
  ThriftUserListEntry() : userName(), sendingVideo(0), videoStreamName(), roomOperator(0) {
  }

  virtual ~ThriftUserListEntry() throw();
  std::string userName;
  std::vector< ::es::ThriftUserVariable>  userVariables;
  bool sendingVideo;
  std::string videoStreamName;
  bool roomOperator;

  _ThriftUserListEntry__isset __isset;

  void __set_userName(const std::string& val);

  void __set_userVariables(const std::vector< ::es::ThriftUserVariable> & val);

  void __set_sendingVideo(const bool val);

  void __set_videoStreamName(const std::string& val);

  void __set_roomOperator(const bool val);

  bool operator == (const ThriftUserListEntry & rhs) const
  {
    if (__isset.userName != rhs.__isset.userName)
      return false;
    else if (__isset.userName && !(userName == rhs.userName))
      return false;
    if (__isset.userVariables != rhs.__isset.userVariables)
      return false;
    else if (__isset.userVariables && !(userVariables == rhs.userVariables))
      return false;
    if (__isset.sendingVideo != rhs.__isset.sendingVideo)
      return false;
    else if (__isset.sendingVideo && !(sendingVideo == rhs.sendingVideo))
      return false;
    if (__isset.videoStreamName != rhs.__isset.videoStreamName)
      return false;
    else if (__isset.videoStreamName && !(videoStreamName == rhs.videoStreamName))
      return false;
    if (__isset.roomOperator != rhs.__isset.roomOperator)
      return false;
    else if (__isset.roomOperator && !(roomOperator == rhs.roomOperator))
      return false;
    return true;
  }
  bool operator != (const ThriftUserListEntry &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftUserListEntry & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ThriftUserListEntry &a, ThriftUserListEntry &b);

inline std::ostream& operator<<(std::ostream& out, const ThriftUserListEntry& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif
