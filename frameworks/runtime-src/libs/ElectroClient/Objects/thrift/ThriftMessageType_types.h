/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ThriftMessageType_TYPES_H
#define ThriftMessageType_TYPES_H

#include <iosfwd>

#include "libs/Thrift.h"

#include "libs/TProtocol.h"
#include "libs/TTransport.h"




namespace es {

struct ThriftMessageType {
  enum type {
    ThriftMessageType_CrossDomainRequest = 1,
    ThriftMessageType_CreateRoomRequest = 2,
    ThriftMessageType_JoinRoomRequest = 3,
    ThriftMessageType_LoginRequest = 4,
    ThriftMessageType_LogOutRequest = 5,
    ThriftMessageType_ValidateAdditionalLoginRequest = 6,
    ThriftMessageType_ValidateAdditionalLoginResponse = 7,
    ThriftMessageType_PublicMessageRequest = 8,
    ThriftMessageType_PrivateMessageRequest = 9,
    ThriftMessageType_LeaveRoomRequest = 10,
    ThriftMessageType_CreateRoomVariableRequest = 11,
    ThriftMessageType_DeleteRoomVariableRequest = 12,
    ThriftMessageType_UpdateRoomVariableRequest = 13,
    ThriftMessageType_GetZonesRequest = 14,
    ThriftMessageType_GetRoomsInZoneRequest = 15,
    ThriftMessageType_UpdateRoomDetailsRequest = 16,
    ThriftMessageType_AddRoomOperatorRequest = 17,
    ThriftMessageType_RemoveRoomOperatorRequest = 18,
    ThriftMessageType_FindZoneAndRoomByNameRequest = 19,
    ThriftMessageType_GetUsersInRoomRequest = 20,
    ThriftMessageType_DeleteUserVariableRequest = 21,
    ThriftMessageType_UpdateUserVariableRequest = 22,
    ThriftMessageType_AddBuddiesRequest = 23,
    ThriftMessageType_RemoveBuddiesRequest = 24,
    ThriftMessageType_EvictUserFromRoomRequest = 25,
    ThriftMessageType_GetUserCountRequest = 26,
    ThriftMessageType_PluginRequest = 27,
    ThriftMessageType_CreateOrJoinGameRequest = 28,
    ThriftMessageType_JoinGameRequest = 29,
    ThriftMessageType_FindGamesRequest = 30,
    ThriftMessageType_GetUserVariablesRequest = 31,
    ThriftMessageType_AggregatePluginRequest = 32,
    ThriftMessageType_GetServerLocalTimeRequest = 33,
    ThriftMessageType_GetGameTypesRequest = 34,
    ThriftMessageType_ConnectionResponse = 35,
    ThriftMessageType_CrossDomainResponse = 36,
    ThriftMessageType_LoginResponse = 37,
    ThriftMessageType_GetZonesResponse = 38,
    ThriftMessageType_GetRoomsInZoneResponse = 39,
    ThriftMessageType_GenericErrorResponse = 40,
    ThriftMessageType_FindZoneAndRoomByNameResponse = 41,
    ThriftMessageType_GetUsersInRoomResponse = 42,
    ThriftMessageType_GetUserCountResponse = 43,
    ThriftMessageType_CreateOrJoinGameResponse = 44,
    ThriftMessageType_FindGamesResponse = 45,
    ThriftMessageType_GetUserVariablesResponse = 46,
    ThriftMessageType_AddBuddiesResponse = 47,
    ThriftMessageType_RemoveBuddiesResponse = 48,
    ThriftMessageType_GetServerLocalTimeResponse = 49,
    ThriftMessageType_GetGameTypesResponse = 50,
    ThriftMessageType_PublicMessageEvent = 51,
    ThriftMessageType_PrivateMessageEvent = 52,
    ThriftMessageType_SessionIdleEvent = 53,
    ThriftMessageType_JoinRoomEvent = 54,
    ThriftMessageType_JoinZoneEvent = 55,
    ThriftMessageType_UserUpdateEvent = 56,
    ThriftMessageType_ZoneUpdateEvent = 57,
    ThriftMessageType_LeaveRoomEvent = 58,
    ThriftMessageType_LeaveZoneEvent = 59,
    ThriftMessageType_RoomVariableUpdateEvent = 60,
    ThriftMessageType_UpdateRoomDetailsEvent = 61,
    ThriftMessageType_BuddyStatusUpdatedEvent = 62,
    ThriftMessageType_UserEvictedFromRoomEvent = 63,
    ThriftMessageType_UserVariableUpdateEvent = 64,
    ThriftMessageType_PluginMessageEvent = 65,
    ThriftMessageType_AggregatePluginMessageEvent = 66,
    ThriftMessageType_RegistryConnectToPreferredGatewayRequest = 67,
    ThriftMessageType_DisconnectedEvent = 68,
    ThriftMessageType_GatewayStartupExceptionsMessage = 69,
    ThriftMessageType_RegistryLoginResponse = 70,
    ThriftMessageType_RegistryConnectionResponse = 71,
    ThriftMessageType_GatewayKickUserRequest = 72,
    ThriftMessageType_ServerKickUserEvent = 73,
    ThriftMessageType_UdpBackchannelEvent = 74,
    ThriftMessageType_Unknown = 75,
    ThriftMessageType_RtmpPlayVideo = 76,
    ThriftMessageType_RtmpEventResponse = 77,
    ThriftMessageType_RtmpRecordVideo = 78,
    ThriftMessageType_RtmpPublishVideo = 79,
    ThriftMessageType_RtmpUnpublishVideo = 80,
    ThriftMessageType_RtmpAppendVideo = 81,
    ThriftMessageType_RtmpStreamingStart = 82,
    ThriftMessageType_RtmpStreamingStop = 83,
    ThriftMessageType_DHInitiate = 84,
    ThriftMessageType_DHPublicNumbers = 85,
    ThriftMessageType_DHSharedModulusRequest = 86,
    ThriftMessageType_DHSharedModulusResponse = 87,
    ThriftMessageType_EncryptionStateChange = 88,
    ThriftMessageType_ConnectionAttemptResponse = 89,
    ThriftMessageType_ConnectionClosedEvent = 90,
    ThriftMessageType_RegisterUDPConnectionRequest = 91,
    ThriftMessageType_RegisterUDPConnectionResponse = 92,
    ThriftMessageType_RemoveUDPConnectionRequest = 93,
    ThriftMessageType_RemoveUDPConnectionResponse = 94,
    ThriftMessageType_PingRequest = 95,
    ThriftMessageType_PingResponse = 96,
    ThriftMessageType_IdleTimeoutWarningEvent = 97,
    ThriftMessageType_MarkGatewayClientLoggedInMessage = 98
  };
};

//extern const std::map<int, const char*> _ThriftMessageType_VALUES_TO_NAMES;

} // namespace

#endif