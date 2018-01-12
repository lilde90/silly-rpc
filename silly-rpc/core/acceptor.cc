// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
//
#include <silly-rpc/base/logging.h>
#include <silly-rpc/core/acceptor.h>
#include <silly-rpc/core/socket.h>

namespace sillyrpc {
namespace core {

Acceptor::Acceptor(EventLoop* loop, const Address& listen_addr) 
  : _loop(loop),
  _listening(false) {
    _accept_socket.setReuseAddr(true);
    _accept_socket.setReusePort(true);
    _accept_socket.bind(listen_addr);
    _accept_channel.setReadCallback(std::bind(&Acceptor::handleRead, this));
}

Acceptor::~Acceptor() {
  // channel disable
}
void Acceptor::listen() {
  _listening = true;
  _accept_socket.listen();
  // TODO:channel enable reading;
  channel->enableReading();

}

void Acceptor::handleRead() {
  Address peer_address;
  int conn_fd = _accept_socket.accept(&peer_address);
  if (conn_fd > 0) {
    if (_new_connection_callback) {
      _new_connection_callback(conn_fd, peer_address);
    } else {
      sillyrpc::core::close(conn_fd);
    }
  } else {
    LOG_ERROR("error in handleRead");
  }
}

} // namespace core
} // namespace sillyrpc
