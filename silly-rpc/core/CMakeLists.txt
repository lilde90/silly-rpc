cmake_minimum_required(VERSION 2.6)
include_directories(../../)
AUX_SOURCE_DIRECTORY(. base_src)
set(CXX_FLAGS
 -DCHECK_PTHREAD_RETURN_VALUE
 -D_FILE_OFFSET_BITS=64
 -Wall
 -Wextra
 -Werror
 -Wconversion
 -Wno-unused-parameter
 -Wold-style-cast
 -Woverloaded-virtual
 -Wpointer-arith
 -Wshadow
 -Wwrite-strings
 -g
 -march=native
 -std=c++0x
 -rdynamic
 )
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")
set(CMAKE_CXX_COMPILER "g++")
add_library(silly-rpc_core ${base_src})
target_link_libraries(silly-rpc_core pthread rt)
