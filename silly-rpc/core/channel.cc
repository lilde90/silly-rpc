// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//

#include <silly-rpc/core/channel.h>

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
} // namespace core
} // naemspace sillyrpc
