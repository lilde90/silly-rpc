// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//

#include <sys/epoll.h>
#include <silly-rpc/core/channel.h>
#include <silly-rpc/core/event_loop.h>

namespace sillyrpc {
namespace core {

void Channel::handleEvent() {
  if (_revents & EPOLLERR) {
    _error_callback();
  }

  if (_revents & (EPOLLIN | EPOLLPRI)) {
    _read_callback();
  }

  if (_revents & EPOLLOUT) {
    _write_callback();
  }

}

Channel::Channel(EventLoop* loop, int fd) :
  _loop(loop),
  _events(0),
  _revents(0),
  _fd(fd),
  _state(ADDChannel) {
}

void Channel::update() {
  _loop->updateChannel(this);
}

} // namespace core
} // naemspace sillyrpc
