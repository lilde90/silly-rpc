// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#ifndef _SILLYRPC_BASE_SCOPED_MUTEX_GUARD_H_
#define _SILLYRPC_BASE_SCOPED_MUTEX_GUARD_H_

#include <silly-rpc/base/scoped_mutex.h>

namespace sillyrpc {
namespace base {

class ScopedMutexGuard {
public:
  ScopedMutexGuard(ScopedMutex& mutex) :
    _mutex(mutex) {
    _mutex.lock();
  }
  ~ScopedMutexGuard() {
    _mutex.unlock();
  }
private:
  ScopedMutex _mutex;
};

} // namespace base
} // namespace sillyrpc

#endif // _SILLYRPC_BASE_SCOPED_MUTEX_GUARD_H_
