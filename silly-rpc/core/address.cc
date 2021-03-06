// Copyright 2017 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
#include <netdb.h>
#include <strings.h>
#include <silly-rpc/core/socket.h>
#include <silly-rpc/core/address.h>
#include <silly-rpc/base/logging.h>
#include <silly-rpc/base/silly_rpc_defs.h>

namespace sillyrpc {
namespace core {

Address::Address() {
  bzero(&_addr, sizeof(_addr));
  _addr.sin_family = AF_INET;
  _addr.sin_port = 0;
}

Address::Address(uint16_t port) {
  bzero(&_addr, sizeof(_addr));
  _addr.sin_family = AF_INET;
  _addr.sin_port = port;
}

Address::Address(std::string ip, uint16_t port) {
  bzero(&_addr, sizeof(_addr));
}

std::string Address::toIp() const {
  char buf[sillyrpc::base::MAX_IP_ADDRESS_BUF_SIZE] = { 0 };
  sillyrpc::core::toIp(buf, sizeof(buf), getSockAddr());
  return buf;
}

std::string Address::toIpPort() const {
  char buf[sillyrpc::base::MAX_IP_ADDRESS_BUF_SIZE] = { 0 };
  sillyrpc::core::toIpPort(buf, sizeof(buf), getSockAddr());
  return buf;
}

uint16_t Address::toPort() const {
  return be16toh(_addr.sin_port);
}

uint32_t Address::ipNetEndian() const {
  return _addr.sin_addr.s_addr;
}

bool resolve(std::string ip_address, Address* result) {
  if (result == NULL) {
    return false;
  }
  struct hostent hent;
  struct hostent* he = NULL;
  int herrno = 0;
  bzero(&hent, sizeof(hent));
  char resolve_buff[sillyrpc::base::MAX_RESOLVE_BUF_SIZE] = { 0 };
  int ret = gethostbyname_r(ip_address.c_str(), &hent, 
      resolve_buff, sizeof(resolve_buff), &he, &herrno);
  if (ret == 0 && he != NULL &&
      he->h_addrtype == AF_INET && he->h_length == sizeof(uint32_t)) {
    result->getSockAddrIn().sin_addr = *reinterpret_cast<struct in_addr*>(he->h_addr);
    return true;
  } else {
    if (ret) {
      LOG_ERROR("resolve address failed");
    }
    return false;
  }
}


} // namespace core
} // namespace sillyrpc
