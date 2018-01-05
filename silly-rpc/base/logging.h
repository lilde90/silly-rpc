// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#ifndef _SILLYRPC_BASE_LOGGING_H_
#define _SILLYRPC_BASE_LOGGING_H_

#include <stdarg.h>

namespace sillyrpc {
namespace base {

enum LogLevel {
  LOG_LEVEL_FATAL     = 0,
  LOG_LEVEL_INFO      = 1,
  LOG_LEVEL_NOTICE    = 2,
  LOG_LEVEL_TRACE     = 3,
  LOG_LEVEL_WARNING   = 4,
  LOG_LEVEL_ERROR     = 5,
  LOG_LEVEL_DEBUG     = 6,
};

void log_handler(const char* filename, int line, LogLevel level, const char* fmt, va_list arg);

#define LOG(level, fmt, arg...) \
  yarpc::base::log_handler(__FILE__, __LINE__, \
      yarpc::base::LOG_LEVEL_##level,\
      fmt, ##arg)

#define LOG_FATAL(fmt, arg...) \
  LOG(FATAL, fmt, ##arg);
#define LOG_INFO(fmt, arg...) \
  LOG(INFO, fmt, ##arg);
#define LOG_NOTICE(fmt, arg...) \
  LOG(NOTICE, fmt, ##arg)
#define LOG_TRACE(fmt, arg...) \
  LOG(TRACE, fmt, ##arg)
#define LOG_WARNING(fmt, arg...) \
  LOG(WARNING, fmt, ##arg)
#define LOG_ERROR(fmt, arg...) \
  LOG(ERROR, fmt, ##arg)
#define LOG_DEBUG(fmt, arg...) \
  LOG(DEBUG, fmt, ##arg)

} // namespace base
} // namespace sillyrpc

#endif // _SILLYRPC_YARPC_BASE_LOGGING_H_
