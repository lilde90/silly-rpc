// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#ifndef _SILLYRPC_CORE_CHANNEL_H_
#define _SILLYRPC_CORE_CHANNEL_H_

#include <functional>
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
  typedef std::function<void()> EventCallback;

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

  void enableReading() {
    _events |= (EPOLLIN | EPOLLPRI);
    //update();
  }

  void disableReading() {
    _events &= ~(EPOLLIN | EPOLLPRI);
    //update();
  }

  void enableWriting() {
    _events |= EPOLLOUT;
    //update();
  }

  void disableWriting() {
    _events &= ~EPOLLOUT;
    //update();
  }

  inline void isReading() {
    return _events & (EPOLLIN | EPOLLPRI);
  }

  inline void isWriting() {
    return _events & EPOLLOUT;
  }

  void 
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

  void setReadCallback(EventCallback& read_callback) {
    _read_callback = read_callback;
  }

  void setWriteCallback(EventCallback& write_callback) {
    _write_callback = write_callback;
  }

  void setErrorCallback(EventCallback& error_callback) {
    _error_callback = error_callback;
  }

public:
  void handleEvent();

private:
  int _events;
  int _revents;
  int _fd;

  ChannelState _state;

  EventCallback _read_callback;
  EventCallback _write_callback;
  EventCallback _error_callback;

private:
  DISALLOW_COPY_AND_ASSIGN(Channel);
};
} // namespace core
} // naemspace sillyrpc

#endif // _SILLYRPC_CORE_CHANNEL_H_
