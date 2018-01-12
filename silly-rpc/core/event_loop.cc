// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#include <silly-rpc/base/silly_rpc_defs.h>
#include <silly-rpc/core/event_loop.h>
#include <silly-rpc/core/channel.h>
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

void EventLoop::updateChannel(Channel* channel) {
  if (channel == NULL) {
    return;
  }
  _epoller->updateChannel(channel);
}

} // namespace core
} // naemspace sillyrpc

