// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#ifndef _SILLYRPC_CORE_CHANNEL_H_
#define _SILLYRPC_CORE_CHANNEL_H_

#include <sys/epoll.h>
#include <silly-rpc/base/condition.h>
#include <silly-rpc/base/logging.h>
#include <silly-rpc/base/scoped_mutex_guard.h>
#include <silly-rpc/base/scoped_mutex.h>
#include <silly-rpc/base/silly_rpc_defs.h>

namespace sillyrpc {
namespace core {

// channel state 
// as to epoll ctl state
enum ChannelState {
  ADDChannel,
  MODChannel,
  DELChannel
};

const int channelNoneEvent = 0;
const int channelReadEvent = EPOLLIN | EPOLLPRI;
const int channelWriteEvent = EPOLLOUT;

class Channel {
public:
  inline void setEvents(int events) {
    _events = events;
  }

  inline void setRevents(int revents) {
    _revents = revents;
  }

  inline bool isNoneEvent() const {
    return _events == channelNoneEvent;
  }

  inline void setState(ChannelState state) {
    _state = state;
  }

  inline int events() {
    return _events;
  }

  inline int revents() {
    return _revents;
  }

  inline int fd() {
    return _fd;
  }

  inline ChannelState state() const {
    return _state;
  }

private:
  int _events;
  int _revents;
  int _fd;

  ChannelState _state;

private:
  DISALLOW_COPY_AND_ASSIGN(Channel);
};
} // namespace core
} // naemspace sillyrpc

#endif // _SILLYRPC_CORE_CHANNEL_H_
