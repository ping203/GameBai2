/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ThriftCreateRoomRequest_TYPES_H
#define ThriftCreateRoomRequest_TYPES_H

#include <iosfwd>

#include "libs/Thrift.h"

#include "libs/TProtocol.h"
#include "libs/TTransport.h"


#include "ThriftFlattenedEsObject_types.h"
#include "ThriftPluginListEntry_types.h"
#include "ThriftRoomVariable_types.h"


namespace es {

class ThriftCreateRoomRequest;

typedef struct _ThriftCreateRoomRequest__isset {
  _ThriftCreateRoomRequest__isset() : zoneName(false), zoneId(false), roomName(false), capacity(false), password(false), roomDescription(false), persistent(false), hidden(false), receivingRoomListUpdates(false), receivingRoomAttributeUpdates(false), receivingUserListUpdates(false), receivingUserVariableUpdates(false), receivingRoomVariableUpdates(false), receivingVideoEvents(false), nonOperatorUpdateAllowed(false), nonOperatorVariableUpdateAllowed(false), createOrJoinRoom(false), plugins(false), variables(false), usingLanguageFilter(false), languageFilterSpecified(false), languageFilterName(false), languageFilterDeliverMessageOnFailure(false), languageFilterFailuresBeforeKick(false), languageFilterKicksBeforeBan(false), languageFilterBanDuration(false), languageFilterResetAfterKick(false), usingFloodingFilter(false), floodingFilterSpecified(false), floodingFilterName(false), floodingFilterFailuresBeforeKick(false), floodingFilterKicksBeforeBan(false), floodingFilterBanDuration(false), floodingFilterResetAfterKick(false) {}
  bool zoneName :1;
  bool zoneId :1;
  bool roomName :1;
  bool capacity :1;
  bool password :1;
  bool roomDescription :1;
  bool persistent :1;
  bool hidden :1;
  bool receivingRoomListUpdates :1;
  bool receivingRoomAttributeUpdates :1;
  bool receivingUserListUpdates :1;
  bool receivingUserVariableUpdates :1;
  bool receivingRoomVariableUpdates :1;
  bool receivingVideoEvents :1;
  bool nonOperatorUpdateAllowed :1;
  bool nonOperatorVariableUpdateAllowed :1;
  bool createOrJoinRoom :1;
  bool plugins :1;
  bool variables :1;
  bool usingLanguageFilter :1;
  bool languageFilterSpecified :1;
  bool languageFilterName :1;
  bool languageFilterDeliverMessageOnFailure :1;
  bool languageFilterFailuresBeforeKick :1;
  bool languageFilterKicksBeforeBan :1;
  bool languageFilterBanDuration :1;
  bool languageFilterResetAfterKick :1;
  bool usingFloodingFilter :1;
  bool floodingFilterSpecified :1;
  bool floodingFilterName :1;
  bool floodingFilterFailuresBeforeKick :1;
  bool floodingFilterKicksBeforeBan :1;
  bool floodingFilterBanDuration :1;
  bool floodingFilterResetAfterKick :1;
} _ThriftCreateRoomRequest__isset;

class ThriftCreateRoomRequest {
 public:

  ThriftCreateRoomRequest(const ThriftCreateRoomRequest&);
  ThriftCreateRoomRequest& operator=(const ThriftCreateRoomRequest&);
  ThriftCreateRoomRequest() : zoneName(), zoneId(0), roomName(), capacity(0), password(), roomDescription(), persistent(0), hidden(0), receivingRoomListUpdates(0), receivingRoomAttributeUpdates(0), receivingUserListUpdates(0), receivingUserVariableUpdates(0), receivingRoomVariableUpdates(0), receivingVideoEvents(0), nonOperatorUpdateAllowed(0), nonOperatorVariableUpdateAllowed(0), createOrJoinRoom(0), usingLanguageFilter(0), languageFilterSpecified(0), languageFilterName(), languageFilterDeliverMessageOnFailure(0), languageFilterFailuresBeforeKick(0), languageFilterKicksBeforeBan(0), languageFilterBanDuration(0), languageFilterResetAfterKick(0), usingFloodingFilter(0), floodingFilterSpecified(0), floodingFilterName(), floodingFilterFailuresBeforeKick(0), floodingFilterKicksBeforeBan(0), floodingFilterBanDuration(0), floodingFilterResetAfterKick(0) {
  }

  virtual ~ThriftCreateRoomRequest() throw();
  std::string zoneName;
  int32_t zoneId;
  std::string roomName;
  int32_t capacity;
  std::string password;
  std::string roomDescription;
  bool persistent;
  bool hidden;
  bool receivingRoomListUpdates;
  bool receivingRoomAttributeUpdates;
  bool receivingUserListUpdates;
  bool receivingUserVariableUpdates;
  bool receivingRoomVariableUpdates;
  bool receivingVideoEvents;
  bool nonOperatorUpdateAllowed;
  bool nonOperatorVariableUpdateAllowed;
  bool createOrJoinRoom;
  std::vector< ::es::ThriftPluginListEntry>  plugins;
  std::vector< ::es::ThriftRoomVariable>  variables;
  bool usingLanguageFilter;
  bool languageFilterSpecified;
  std::string languageFilterName;
  bool languageFilterDeliverMessageOnFailure;
  int32_t languageFilterFailuresBeforeKick;
  int32_t languageFilterKicksBeforeBan;
  int32_t languageFilterBanDuration;
  bool languageFilterResetAfterKick;
  bool usingFloodingFilter;
  bool floodingFilterSpecified;
  std::string floodingFilterName;
  int32_t floodingFilterFailuresBeforeKick;
  int32_t floodingFilterKicksBeforeBan;
  int32_t floodingFilterBanDuration;
  bool floodingFilterResetAfterKick;

  _ThriftCreateRoomRequest__isset __isset;

  void __set_zoneName(const std::string& val);

  void __set_zoneId(const int32_t val);

  void __set_roomName(const std::string& val);

  void __set_capacity(const int32_t val);

  void __set_password(const std::string& val);

  void __set_roomDescription(const std::string& val);

  void __set_persistent(const bool val);

  void __set_hidden(const bool val);

  void __set_receivingRoomListUpdates(const bool val);

  void __set_receivingRoomAttributeUpdates(const bool val);

  void __set_receivingUserListUpdates(const bool val);

  void __set_receivingUserVariableUpdates(const bool val);

  void __set_receivingRoomVariableUpdates(const bool val);

  void __set_receivingVideoEvents(const bool val);

  void __set_nonOperatorUpdateAllowed(const bool val);

  void __set_nonOperatorVariableUpdateAllowed(const bool val);

  void __set_createOrJoinRoom(const bool val);

  void __set_plugins(const std::vector< ::es::ThriftPluginListEntry> & val);

  void __set_variables(const std::vector< ::es::ThriftRoomVariable> & val);

  void __set_usingLanguageFilter(const bool val);

  void __set_languageFilterSpecified(const bool val);

  void __set_languageFilterName(const std::string& val);

  void __set_languageFilterDeliverMessageOnFailure(const bool val);

  void __set_languageFilterFailuresBeforeKick(const int32_t val);

  void __set_languageFilterKicksBeforeBan(const int32_t val);

  void __set_languageFilterBanDuration(const int32_t val);

  void __set_languageFilterResetAfterKick(const bool val);

  void __set_usingFloodingFilter(const bool val);

  void __set_floodingFilterSpecified(const bool val);

  void __set_floodingFilterName(const std::string& val);

  void __set_floodingFilterFailuresBeforeKick(const int32_t val);

  void __set_floodingFilterKicksBeforeBan(const int32_t val);

  void __set_floodingFilterBanDuration(const int32_t val);

  void __set_floodingFilterResetAfterKick(const bool val);

  bool operator == (const ThriftCreateRoomRequest & rhs) const
  {
    if (!(zoneName == rhs.zoneName))
      return false;
    if (!(zoneId == rhs.zoneId))
      return false;
    if (!(roomName == rhs.roomName))
      return false;
    if (!(capacity == rhs.capacity))
      return false;
    if (!(password == rhs.password))
      return false;
    if (!(roomDescription == rhs.roomDescription))
      return false;
    if (!(persistent == rhs.persistent))
      return false;
    if (!(hidden == rhs.hidden))
      return false;
    if (!(receivingRoomListUpdates == rhs.receivingRoomListUpdates))
      return false;
    if (!(receivingRoomAttributeUpdates == rhs.receivingRoomAttributeUpdates))
      return false;
    if (!(receivingUserListUpdates == rhs.receivingUserListUpdates))
      return false;
    if (!(receivingUserVariableUpdates == rhs.receivingUserVariableUpdates))
      return false;
    if (!(receivingRoomVariableUpdates == rhs.receivingRoomVariableUpdates))
      return false;
    if (!(receivingVideoEvents == rhs.receivingVideoEvents))
      return false;
    if (!(nonOperatorUpdateAllowed == rhs.nonOperatorUpdateAllowed))
      return false;
    if (!(nonOperatorVariableUpdateAllowed == rhs.nonOperatorVariableUpdateAllowed))
      return false;
    if (!(createOrJoinRoom == rhs.createOrJoinRoom))
      return false;
    if (!(plugins == rhs.plugins))
      return false;
    if (!(variables == rhs.variables))
      return false;
    if (!(usingLanguageFilter == rhs.usingLanguageFilter))
      return false;
    if (!(languageFilterSpecified == rhs.languageFilterSpecified))
      return false;
    if (!(languageFilterName == rhs.languageFilterName))
      return false;
    if (!(languageFilterDeliverMessageOnFailure == rhs.languageFilterDeliverMessageOnFailure))
      return false;
    if (!(languageFilterFailuresBeforeKick == rhs.languageFilterFailuresBeforeKick))
      return false;
    if (!(languageFilterKicksBeforeBan == rhs.languageFilterKicksBeforeBan))
      return false;
    if (!(languageFilterBanDuration == rhs.languageFilterBanDuration))
      return false;
    if (!(languageFilterResetAfterKick == rhs.languageFilterResetAfterKick))
      return false;
    if (!(usingFloodingFilter == rhs.usingFloodingFilter))
      return false;
    if (!(floodingFilterSpecified == rhs.floodingFilterSpecified))
      return false;
    if (!(floodingFilterName == rhs.floodingFilterName))
      return false;
    if (!(floodingFilterFailuresBeforeKick == rhs.floodingFilterFailuresBeforeKick))
      return false;
    if (!(floodingFilterKicksBeforeBan == rhs.floodingFilterKicksBeforeBan))
      return false;
    if (!(floodingFilterBanDuration == rhs.floodingFilterBanDuration))
      return false;
    if (!(floodingFilterResetAfterKick == rhs.floodingFilterResetAfterKick))
      return false;
    return true;
  }
  bool operator != (const ThriftCreateRoomRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftCreateRoomRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ThriftCreateRoomRequest &a, ThriftCreateRoomRequest &b);

inline std::ostream& operator<<(std::ostream& out, const ThriftCreateRoomRequest& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif