// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#ifndef _SILLYRPC_BASE_SCOPED_MUTEX_H_
#define _SILLYRPC_BASE_SCOPED_MUTEX_H_

#include <pthread.h>

namespace sillyrpc {
namespace base {

class ScopedMutex {
public:
  ScopedMutex() {
    pthread_mutex_init(&_mutex, NULL);
  }
  ~ScopedMutex() {
    pthread_mutex_destroy(&_mutex);
  }

  void lock() {
    pthread_mutex_lock(&_mutex);
  }

  void unlock() {
    pthread_mutex_unlock(&_mutex);
  }

  pthread_mutex_t& getMutex() {
    return _mutex;
  }

private:
  pthread_mutex_t _mutex;

};

} // namespace base
} // namespace sillyrpc

#endif // _SILLYRPC_BASE_SCOPED_MUTEX_H_
