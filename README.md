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
</br>
`sh get_deps.sh`
</br>
build deps source code, silly-rpc source code, silly-rpc unittest 
</br>
`sh build.sh`
</br>
clean all the build results 
</br>
`sh clean.sh`
</br>
remove building deps 
</br>
`sh clean_deps.sh`

