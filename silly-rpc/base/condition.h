// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#ifndef _SILLYRPC_BASE_CONDITION_H_
#define _SILLYRPC_BASE_CONDITION_H_

#include <cstdlib>
#include <pthread.h>
#include <sys/time.h>
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

  bool timedwait(int timeout_in_ms) {
    struct timeval now_timeval;
    gettimeofday(&now_timeval, NULL);
    struct timespec timeout_timespec; 
    unsigned long usec = now_timeval.tv_usec + timeout_in_ms * 1000;
    timeout_timespec.tv_sec = now_timeval.tv_sec + usec / 1000 / 1000;
    timeout_timespec.tv_nsec = (usec % (1000 * 1000)) * 1000;
    int error = pthread_cond_timedwait(&cond, &(_mutex.getMutex()), &timeout_timespec);
    return error == 0;
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
