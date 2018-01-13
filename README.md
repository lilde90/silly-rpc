# silly-rpc
silly-rpc is a event-driven rpc framework inspired by muduo, sofa-pbrpc, brpc.
</br>
Based on reactor and epoll, silly-rpc provides a silly rpc function for net
programming

## Deps
silly-rpc required C++11 support and eventfd support.
</br>
GCC > 4.8.2
Linux kernel > 2.7
</br>
LINUX SUPPORT ONLY!
</br>


## Compile and install
get deps incluing gtest
    sh get\_deps.sh
</br>
sh build.sh to build deps source code, silly-rpc source code, silly-rpc unittest 
</br>
sh clean.sh to clean all the build results 
</br>
sh clean\_deps.sh to remove building deps 
</br>

