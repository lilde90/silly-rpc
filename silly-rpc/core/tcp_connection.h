// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//

#ifndef _SILLYRPC_CORE_TCP_CONNECTION_H_
#define _SILLYRPC_CORE_TCP_CONNECTION_H_

#include <functional>
#include <string>
#include <silly-rpc/base/silly_rpc_defs.h>
#include <silly-rpc/core/address.h>
#include <silly-rpc/core/event_loop.h>
#include <silly-rpc/core/channel.h>
#include <silly-rpc/core/socket.h>

namespace sillyrpc {
namespace core {

class TcpConnection {
public:
  TcpConnection(EventLoop* loop, int fd, const Address& local_addr,
      const Address& peer_addr, const std::string& name);

  ~TcpConnection();

  EventLoop* getLoop() const {
    return _loop;
  }

  void setMessageCallback(const MessageCallback& cb) {
    _message_callback = cb;
  }

  void setConnectionCallback(const ConnectionCallback& cb) {
    _connection_callback = cb;
  }
private:
  EventLoop* _loop;
  const std::string _name;

  Socket* _socket;
  Channel* _channel;
  const Address _local_addr;
  const Address _peer_addr;
  MessageCallback _message_callback;
  ConnectionCallback _connection_callback;
  CloseCallback _close_callback;

private:
  void handleRead();
  void handleWrite();
  void handleClose();
  void handleError();

private:
  DISALLOW_COPY_AND_ASSIGN(TcpConnection);
};
} // namespace core
} // namespace sillyrpc

#endif // _SILLYRPC_CORE_TCP_CONNECTION_H_
