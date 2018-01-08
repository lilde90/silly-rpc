// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#include <cstdio>
#include <cstdlib> // abort();
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <silly-rpc/base/logging.h>
#include <silly-rpc/base/silly_rpc_defs.h>

namespace sillyrpc {
namespace base {

void log_handler_impl(const char* filename, int line, 
    LogLevel level, const char* fmt, va_list arg) {
  static const char* level_names[] = {
    "FATAL",
    "INFO",
    "NOTICE",
    "TRACE",
    "WARNING",
    "ERROR",
    "DEBUG"
  };
  char buf[MAX_LOGGING_BUF_SIZE] = { 0 };
  vsnprintf(buf, sizeof(buf), fmt, arg);

  struct timeval now_timeval;
  gettimeofday(&now_timeval, NULL);
  const time_t seconds = now_timeval.tv_sec;
  struct tm t;
  localtime_r(&seconds, &t);
  fprintf(stderr, "[sillyrpc][%s][%04d-%02d-%02d::%02d::%02d::%02d.%06d][%s:%d %lld] %s\n",
      level_names[level],
      t.tm_year + TM_YEAR_OFFSET,
      t.tm_mon,
      t.tm_mday,
      t.tm_hour,
      t.tm_min,
      t.tm_sec,
      static_cast<int>(now_timeval.tv_usec),
      filename,
      line,
      static_cast<unsigned long long int>(pthread_self()),
      buf);
      
  fflush(stderr);

  if (level == LOG_LEVEL_FATAL) {
    abort();
  }

}

void log_handler(const char* filename, int line, LogLevel level, const char* fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  log_handler_impl(filename, line, level, fmt, ap);
  va_end(ap);
}

} // namespace base
} // namespace sillyrpc
