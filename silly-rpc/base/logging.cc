// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#include <cstdio>
#include <cstdlib> // abort();
#include <time.h>
#include <sys/time.h>
#include <silly-rpc/base/logging.h>
#include <silly-rpc/base/silly_rpc_defs.h>

namespace sillyrpc {
namespace base {

void log_handler(const char* filename, int line, 
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
  fprintf(stderr, "[sillyrpc][%s]",
      level_names[level]);
  fflush(stderr);

  if (level == LOG_LEVEL_FATAL) {
    abort();
  }

}

} // namespace base
} // namespace sillyrpc