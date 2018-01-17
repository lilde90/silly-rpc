// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#include <silly-rpc/core/tcp_connection.h>

namespace sillyrpc {
namespace core {
TcpConnection::TcpConnection(EventLoop* loop, int fd,
    const Address& local_addr, const Address& peer_addr,
    const std::string& name) 
  :_loop(loop),
  _name(name),
  _socket(new Socket(fd)),
  _channel(new Channel(loop, fd)),
  _local_addr(local_addr),
  _peer_addr(peer_addr) {
    if (_loop == NULL) {
      LOG_FATAL("tcp connection owner loop is NULL");
    }
    _channel->setReadCallback(std::bind(&TcpConnection::handleRead, this));
    _channel->setWriteCallback(std::bind(&TcpConnection::handleWrite, this));
    _channel->setCloseCallback(std::bind(&TcpConnection::handleClose, this));
    _channel->setErrorCallback(std::bind(&TcpConnection::handleError, this));
}

TcpConnection::~TcpConnection() {
  if(_socket != NULL) {
    delete _socket;
  }

  if (_channel != NULL) {
    delete _channel;
  }

}
  


void TcpConnection::handleRead() {
  // read from channel fd;
}

void TcpConnection::handleWrite() {
  // write to buffer
}

void TcpConnection::handleClose() {
}

void TcpConnection::handleError() {
  LOG_ERROR("TcpConnection::handleError %s", _name);
}

} // namespace core
} // namespace sillyrpc
