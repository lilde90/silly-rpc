// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#ifndef _SILLYRPC_CORE_TCP_SERVER_H_
#define _SILLYRPC_CORE_TCP_SERVER_H_

#include <string>
#include <silly-rpc/core/event_loop.h>

namespace sillyrpc {
namespace core {

class TcpServer {
private:
  EventLoop* _loop;
  const std::string _name;
};

} // namespace core
} // namespace sillyrpc

#endif // _SILLYRPC_CORE_TCP_SERVER_H_
