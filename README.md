# silly-rpc
silly-rpc is a event-driven rpc framework inspired by muduo, sofa-pbrpc, brpc.
Based on reactor and epoll, silly-rpc provides a silly rpc function for net
programming;

## Deps
silly-rpc required C++11 support and eventfd support.

GCC > 4.8.2
Linux kernel > 2.7

LINUX SUPPORT ONLY!


## Compile and install
sh get\_deps.sh to get deps including gtest 
sh build.sh to build deps source code, silly-rpc source code, silly-rpc unittest 
sh clean.sh to clean all the build results 
sh clean\_deps.sh to remove building deps 

