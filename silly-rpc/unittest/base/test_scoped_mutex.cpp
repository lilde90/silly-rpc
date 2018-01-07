// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#include <silly-rpc/base/scoped_mutex.h>
#include <gtest/gtest.h>

namespace sillyrpc {
namespace unittest {
namespace base {

TEST(ScopedMutexTest, LockCase) {
  sillyrpc::base::ScopedMutex mutex;
  int a = 1;
  mutex.lock();
  a++;
  mutex.unlock();
  ASSERT_EQ(a, 2);
}

} // namespace base
} // namespace unittest
} // namespace sillyrpc


