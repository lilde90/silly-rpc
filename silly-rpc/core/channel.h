// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#ifndef _SILLYRPC_CORE_CHANNEL_H_
#define _SILLYRPC_CORE_CHANNEL_H_

#include <silly-rpc/base/condition.h>
#include <silly-rpc/base/logging.h>
#include <silly-rpc/base/scoped_mutex_guard.h>
#include <silly-rpc/base/scoped_mutex.h>
#include <silly-rpc/base/silly_rpc_defs.h>

namespace sillyrpc {
namespace core {
class Channel {
public:
  inline void setEevents(int events) {
    _events = events;
  }

  inline void setRevents(int revents) {
    _revents = revents;
  }

  inline int events() {
    return _events;
  }

  inline int revents() {
    return _revents;
  }

private:
  int _events;
  int _revents;

private:
  DISALLOW_COPY_AND_ASSIGN(Channel);
};
} // namespace core
} // naemspace sillyrpc

#endif // _SILLYRPC_CORE_CHANNEL_H_
