# Copyright 2018 lilde90. All Rights Reserved.
# Author: Pan Li (panli.me@gmail.com)
#!/bin/bash
#
#compile gmock
cd ./googletest/
cmake .
make -j12
cd ../

#compile gtest
cd ./googletest/googletest
cmake .
make -j12
cd ../../

#compile silly-rpc
cd silly-rpc
cmake .
make -j12
cd ..

