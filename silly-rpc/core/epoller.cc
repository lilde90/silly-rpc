// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#include <string.h>
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
    // set channel prop
    channel->setRevents(_events[i].events);
    active_channels.push_back(channel);
  }

  if (event_num == static_cast<int>(_events.size())) {
    _events.resize(_events.size() * 2);
  }

  return event_num;
}

int Epoller::updateChannel(Channel* channel) {
  if (channel == NULL) {
    return -1;
  }
  int fd = channel->fd();
  ChannelState state = channel->state();
  if (state == MODChannel) {
    if (channel->isNoneEvent()) {
      int ret = updateImpl(channel, EPOLL_CTL_DEL);
      if (ret < 0) {
        LOG_ERROR("updateImpl EPOLL_CTL_DEL failed");
        return ret;
      }
      channel->setState(DELChannel);
    } else {
      int ret = updateImpl(channel, EPOLL_CTL_MOD);
      if (ret < 0) {
        LOG_ERROR("updateImpl EPOLL_CTL_MOD failed");
        return ret;
      }
    }
  } else {
    if (state == ADDChannel) { 
      // set fd and channel map; 
      _fd_channel_map[fd] = channel; 
    }
    int ret = updateImpl(channel, EPOLL_CTL_ADD);
    if (ret < 0) {
      LOG_ERROR("updateImpl EPOLL_CTL_ADD failed");
      return ret;
    }
    channel->setState(ADDChannel);
  }
  return 0;
}

int Epoller::updateImpl(Channel* channel, int op) {
  struct epoll_event event;
  bzero(&event, sizeof(event));
  event.events = channel->events();
  event.data.ptr = channel;
  int ret = epoll_ctl(_epoll_fd, op, channel->fd(), &event);
  if (ret < 0) {
    LOG_ERROR("epoll ctl failed");
    return ret;
  }
  return 0;
}

int Epoller::removeChannel(Channel* channel) {
  if (channel == NULL) {
    return -1;
  }
  int fd = channel->fd();
  ChannelState state = channel->state();
  size_t n = _fd_channel_map.erase(fd);
  if (n != 1) {
    LOG_FATAL("fd channel map internal error");
    return -1;
  }

  if (state == MODChannel) {
    updateImpl(channel, EPOLL_CTL_DEL);
  }
  channel->setState(ADDChannel);
  return 0;
}

} // namespace core
} // naemspace sillyrpc
