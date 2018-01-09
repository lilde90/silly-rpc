// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#ifndef _SILLYRPC_CORE_EVENT_LOOP_H_
#define _SILLYRPC_CORE_EVENT_LOOP_H_

#include <silly-rpc/base/silly_rpc_defs.h>
#include <silly-rpc/core/channel.h>
#include <silly-rpc/core/epoller.h>

namespace sillyrpc {
namespace core {
class EventLoop {
private:
  Channel* _channel;
  Epoller* _epoller;
private:
  DISALLOW_COPY_AND_ASSIGN(EventLoop);
};
} // namespace core
} // naemspace sillyrpc

#endif // _SILLYRPC_CORE_EVENT_LOOP_H_
