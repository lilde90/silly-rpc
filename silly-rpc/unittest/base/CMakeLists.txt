cmake_minimum_required(VERSION 2.6)
include_directories(../../../)
include_directories(../../../googletest/googletest/include/)
link_directories(../../../googletest/googlemock/)
link_directories(../../../googletest/googletest/)
AUX_SOURCE_DIRECTORY(. unittest_base_src)
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
 -lpthread
 )
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")
set(CMAKE_CXX_COMPILER "g++")
if (NOT GTEST_DIR)
  set (GTEST_DIR ${CMAKE_SOURCE_DIR}../../../googletest/googletest)
endif()

if (IS_DIRECTORY ${GTEST_DIR})
  add_subdirectory(${GTEST_DIR}, ${GTEST_DIR})
  add_subdirectory(${GTEST_DIR}, ${GTEST_DIR})
endif()
add_executable(silly-rpc_unittest_base_test_scoped_mutex test_scoped_mutex.cpp)
target_link_libraries(silly-rpc_unittest_base_test_scoped_mutex gtest gmock_main pthread rt)
add_test(NAME test_scoped_mutex COMMAND silly-rpc_unittest_base_test_scoped_mutex)
