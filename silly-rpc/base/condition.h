// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#ifndef _SILLYRPC_BASE_CONDITION_H_
#define _SILLYRPC_BASE_CONDITION_H_

#include <pthread.h>
#include <silly-rpc/base/scoped_mutex.h>

namespace sillyrpc {
namespace base {

class Condition {

  Condition(ScopedMutex mutex) : _mutex(mutex) {
    pthread_cond_init(&_cond, NULL);
  }

  ~Condition() {
    pthread_cond_destroy(&_cond);
  }

  void timedwait(int timeout_in_ms) {
    //return pthread_cond_timedwait(&_cond, &_mutex);
  }

  void wait() {
    pthread_cond_wait(&_cond, &(_mutex.getMutex()));
  }
  void signal() {
    pthread_cond_signal(&_cond);
  }
  void broadcast() {
    pthread_cond_broadcast(&_cond);
  }
private:
  ScopedMutex _mutex;
  pthread_cond_t _cond;
};

} // namespace base
} // namespace sillyrpc

#endif // _SILLYRPC_BASE_CONDITION_H_
