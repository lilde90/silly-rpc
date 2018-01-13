// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#include <silly-rpc/core/connector.h>
namespace sillyrpc {
namespace core {

Connector::Connector(EventLoop* loop, const Address& server_addr) :
  _loop(loop),
  _server_addr(server_addr),
  _connected(false) {
}

Connector::~Connector() {
}

void Connector::start() {
  _connected = true;
}

void Connector::restart() {
}

void Connector::stop() {
}

} // namespace core
} // namespace sillyrpc
