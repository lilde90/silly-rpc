// Copyright 2018 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#ifndef _SILLYRPC_BASE_SILLY_RPC_DEFS_H_
#define _SILLYRPC_BASE_SILLY_RPC_DEFS_H_

namespace sillyrpc {
namespace base {

static const int MAX_LOGGING_BUF_SIZE = 1024;
static const int TM_YEAR_OFFSET = 1900;
static const int EPOLL_CREATE_INIT_FD_SIZE = 1024;
static const int EVENTS_VECTOR_INIT_SIZE = 32;

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);              \
  TypeName& operator=(const TypeName&)

} // namespace base
} // namespace sillyrpc

#endif // _SILLYRPC_BASE_SILLY_RPC_DEFS_H_
