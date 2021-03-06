/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ThriftAggregatePluginMessageEvent_TYPES_H
#define ThriftAggregatePluginMessageEvent_TYPES_H

#include <iosfwd>

#include "libs/Thrift.h"

#include "libs/TProtocol.h"
#include "libs/TTransport.h"


#include "ThriftFlattenedEsObjectRO_types.h"


namespace es {

class ThriftAggregatePluginMessageEvent;

typedef struct _ThriftAggregatePluginMessageEvent__isset {
  _ThriftAggregatePluginMessageEvent__isset() : pluginName(false), esObjects(false), originZoneId(false), originRoomId(false) {}
  bool pluginName :1;
  bool esObjects :1;
  bool originZoneId :1;
  bool originRoomId :1;
} _ThriftAggregatePluginMessageEvent__isset;

class ThriftAggregatePluginMessageEvent {
 public:

  ThriftAggregatePluginMessageEvent(const ThriftAggregatePluginMessageEvent&);
  ThriftAggregatePluginMessageEvent& operator=(const ThriftAggregatePluginMessageEvent&);
  ThriftAggregatePluginMessageEvent() : pluginName(), originZoneId(0), originRoomId(0) {
  }

  virtual ~ThriftAggregatePluginMessageEvent() throw();
  std::string pluginName;
  std::vector< ::es::ThriftFlattenedEsObjectRO>  esObjects;
  int32_t originZoneId;
  int32_t originRoomId;

  _ThriftAggregatePluginMessageEvent__isset __isset;

  void __set_pluginName(const std::string& val);

  void __set_esObjects(const std::vector< ::es::ThriftFlattenedEsObjectRO> & val);

  void __set_originZoneId(const int32_t val);

  void __set_originRoomId(const int32_t val);

  bool operator == (const ThriftAggregatePluginMessageEvent & rhs) const
  {
    if (!(pluginName == rhs.pluginName))
      return false;
    if (!(esObjects == rhs.esObjects))
      return false;
    if (!(originZoneId == rhs.originZoneId))
      return false;
    if (!(originRoomId == rhs.originRoomId))
      return false;
    return true;
  }
  bool operator != (const ThriftAggregatePluginMessageEvent &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftAggregatePluginMessageEvent & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ThriftAggregatePluginMessageEvent &a, ThriftAggregatePluginMessageEvent &b);

inline std::ostream& operator<<(std::ostream& out, const ThriftAggregatePluginMessageEvent& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif
