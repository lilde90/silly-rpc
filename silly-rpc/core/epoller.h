// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#ifndef _SILLYRPC_CORE_EPOLLER_H_
#define _SILLYRPC_CORE_EPOLLER_H_

#include <vector>
#include <unordered_map>
#include <sys/epoll.h>
#include <silly-rpc/base/logging.h>
#include <silly-rpc/base/silly_rpc_defs.h>
#include <silly-rpc/core/channel.h>

namespace sillyrpc {
namespace core {

class Epoller {
public:
  Epoller() : 
    _epoll_fd(epoll_create(sillyrpc::base::EPOLL_CREATE_INIT_FD_SIZE)),
    _events(sillyrpc::base::EVENTS_VECTOR_INIT_SIZE) {
    if (_epoll_fd < 0) {
      LOG_ERROR("create epoll fd failed");
    }
  }
  ~Epoller() {
    if (_epoll_fd > 0) {
      close(_epoll_fd);
    }
  }

public:
  int poll(std::vector<Channel*>& channels, int timeout_in_ms);
  int updateChannel(Channel* channel);
  int updateImpl(Channel* channel, int op);
private:

  int _epoll_fd;
  std::vector<struct epoll_event> _events;
  std::unordered_map<int, Channel*> _fd_channel_map;

private:
  DISALLOW_COPY_AND_ASSIGN(Epoller);

};

} // namespace core
} // naemspace sillyrpc

#endif // _SILLYRPC_CORE_EPOLLER_H_
