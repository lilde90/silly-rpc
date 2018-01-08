// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#include <unistd.h>
#include <silly-rpc/core/epoller.h>

namespace sillyrpc {
namespace core {

int Epoller::poll(std::vector<Channel*>& active_channels, int timeout_in_ms) {
  int event_num =  epoll_wait(_epoll_fd, &*_events.begin(), 
      static_cast<int>(_events.size()), timeout_in_ms);

  if (event_num < 0) {
    LOG_ERROR("epoll wait failed");
    return -1;
  }

  if (event_num == 0) {
    LOG_INFO("nothing happen");
    return -1;
  }
  // fill channels
  for (size_t i = 0; i < _events.size(); i++) {
    Channel* channel = static_cast<Channel*>(_events[i].data.ptr);
    // set channel prop;
    channel->setRevents(_events[i].events);
    active_channels.push_back(channel);
  }

  if (event_num == static_cast<int>(_events.size())) {
    _events.resize(_events.size() * 2);
  }

  return event_num;
}

} // namespace core
} // naemspace sillyrpc
