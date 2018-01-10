// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#include <silly-rpc/base/silly_rpc_defs.h>
#include <silly-rpc/core/event_loop.h>
#include <unistd.h>

namespace sillyrpc {
namespace core {
void EventLoop::loop() {
  _looping = true;
  while(!_quit) {
    _active_channels.clear();
    _epoller->poll(_active_channels, sillyrpc::base::POLL_DEFAULT_TIMEOUT_MS);
    for (auto channel : _active_channels) {
      channel->handleEvent();
    }
  }
  _looping = false;
}

void EventLoop::quit() {
  _quit = true;
}

} // namespace core
} // naemspace sillyrpc

