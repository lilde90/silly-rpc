# Copyright 2017 lilde90. All Rights Reserved.
# Author: Pan Li (panli.me@gmail.com)
#!/bin/bash
#

cd ./silly-rpc
if [ -f Makefile ]; then
  make clean
  cd base
  if [ -f Makefile ]; then
    make clean
  fi
  cd ..
  cd core
  if [ -f Makefile ]; then
    make clean
  fi
  cd ..
fi

rm -f CMakeCache.txt
rm -rf CMakeFiles
rm -f Makefile
rm -f cmake_install.cmake

rm -f ./*/CMakeCache.txt
rm -rf ./*/CMakeFiles
rm -f ./*/Makefile
rm -f ./*/cmake_install.cmake
rm -rf ./*/*.a

# remove unittest CMake Files
rm -f ./unittest/*/CMakeCache.txt
rm -rf ./unittest/*/CMakeFiles
rm -f ./unittest/*/Makefile
rm -f ./unittest/*/cmake_install.cmake
rm -rf ./unittest/*/*.a

cd ..
rm -rf googletest
