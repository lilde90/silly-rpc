// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#ifndef _SILLYRPC_CORE_ACCEPTOR_H_
#define _SILLYRPC_CORE_ACCEPTOR_H_
#include <functional>
#include <silly-rpc/base/silly_rpc_defs.h>
#include <silly-rpc/core/channel.h>
#include <silly-rpc/core/socket.h>
#include <silly-rpc/core/event_loop.h>
namespace sillyrpc {
namespace core {
class Acceptor {
public:
  typedef std::function<void(int sockfd, const Address&)> NewConnectionCallback;

  Acceptor(EventLoop* loop, const Address& listen_addr);

  void setNewConnectionCallback(const NewConnectionCallback& cb) {
    _new_connection_callback = cb;
  }

  void listen();

  ~Acceptor();

private:
  void handleRead();
private:
  EventLoop* _loop;
  Socket _accept_socket;
  Channel _accept_channel;
  NewConnectionCallback _new_connection_callback;
  bool _listening;

private:
  DISALLOW_COPY_AND_ASSIGN(Acceptor);

};

} // namespace core
} // namespace sillyrpc

#endif // _SILLYRPC_CORE_ACCEPTOR_H_
