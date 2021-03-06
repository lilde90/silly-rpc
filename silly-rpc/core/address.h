// Copyright 2017 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//

#ifndef _SILLYRPC_CORE_ADDRESS_H_
#define _SILLYRPC_CORE_ADDRESS_H_

#include <netinet/in.h>
#include <string>
#include <functional>
#include <silly-rpc/core/socket.h>

namespace sillyrpc {
namespace core {

class Address {
public:
  Address();
  Address(uint16_t port);
  Address(std::string ip, uint16_t port);

  Address(const struct sockaddr_in& addr)
    :_addr(addr) {
  }


  std::string toIp() const;
  std::string toIpPort() const;
  uint16_t toPort() const;

  sa_family_t family() const {
    return _addr.sin_family;
  }

  const struct sockaddr* getSockAddr() const {
    return sillyrpc::core::sockaddr_cast(&_addr);
  }

  void setSockAddr(const struct sockaddr_in& addr) {
    _addr = addr;
  }

  struct sockaddr_in& getSockAddrIn() {
    return _addr;
  }

  uint32_t ipNetEndian() const;

  uint16_t portNetEndian() const {
    return _addr.sin_port;
  }

  static bool resolve(std::string ip_address, Address* result);

private:
  struct sockaddr_in _addr;
};

} // namespace core
} // namespace sillyrpc

#endif // _SILLYRPC_CORE_ADDRESS_H_
