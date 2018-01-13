// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#ifndef _SILLYRPC_CORE_CONNECTOR_H_
#define _SILLYRPC_CORE_CONNECTOR_H_

#include <functional>
#include <silly-rpc/core/address.h>
#include <silly-rpc/core/event_loop.h>
#include <silly-rpc/base/silly_rpc_defs.h>

namespace sillyrpc {
namespace core {

class Connector {
public:
  typedef std::function<void(int)> NewConnectionCallback;
  Connector(EventLoop* loop, const Address& server_addr);
  ~Connector();

  void start();
  void restart();
  void stop();

  const Address& serverAddress() const {
    return _server_addr;
  }
private:
  EventLoop* _loop;
  Address _server_addr;
  bool _connected;
  Channel* _channel;
private:

  void connect();


private:
  DISALLOW_COPY_AND_ASSIGN(Connector);
};

} // namespace core
} // namespace sillyrpc

#endif // _SILLYRPC_CORE_CONNECTOR_H_
