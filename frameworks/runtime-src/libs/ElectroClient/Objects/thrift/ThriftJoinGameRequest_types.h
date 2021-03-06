/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ThriftJoinGameRequest_TYPES_H
#define ThriftJoinGameRequest_TYPES_H

#include <iosfwd>

#include "libs/Thrift.h"

#include "libs/TProtocol.h"
#include "libs/TTransport.h"




namespace es {

class ThriftJoinGameRequest;

typedef struct _ThriftJoinGameRequest__isset {
  _ThriftJoinGameRequest__isset() : gameId(false), password(false) {}
  bool gameId :1;
  bool password :1;
} _ThriftJoinGameRequest__isset;

class ThriftJoinGameRequest {
 public:

  ThriftJoinGameRequest(const ThriftJoinGameRequest&);
  ThriftJoinGameRequest& operator=(const ThriftJoinGameRequest&);
  ThriftJoinGameRequest() : gameId(0), password() {
  }

  virtual ~ThriftJoinGameRequest() throw();
  int32_t gameId;
  std::string password;

  _ThriftJoinGameRequest__isset __isset;

  void __set_gameId(const int32_t val);

  void __set_password(const std::string& val);

  bool operator == (const ThriftJoinGameRequest & rhs) const
  {
    if (!(gameId == rhs.gameId))
      return false;
    if (!(password == rhs.password))
      return false;
    return true;
  }
  bool operator != (const ThriftJoinGameRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftJoinGameRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ThriftJoinGameRequest &a, ThriftJoinGameRequest &b);

inline std::ostream& operator<<(std::ostream& out, const ThriftJoinGameRequest& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif
