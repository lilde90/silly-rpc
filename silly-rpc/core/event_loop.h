// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#ifndef _SILLYRPC_CORE_EVENT_LOOP_H_
#define _SILLYRPC_CORE_EVENT_LOOP_H_

#include <silly-rpc/base/silly_rpc_defs.h>
#include <silly-rpc/core/epoller.h>

namespace sillyrpc {
namespace core {
class Channel;
class EventLoop {
public:
  void loop();
  void quit();
  void updateChannel(Channel* channel);
private:
  Epoller* _epoller;
  bool _looping;
  bool _quit;
  std::vector<Channel*> _active_channels;
  
private:
  DISALLOW_COPY_AND_ASSIGN(EventLoop);
};
} // namespace core
} // naemspace sillyrpc

#endif // _SILLYRPC_CORE_EVENT_LOOP_H_
