# Copyright 2018 lilde90. All Rights Reserved.
# Author: Pan Li (panli.me@gmail.com)
#!/bin/bash
#
cd ./googletest/
cmake .
make -j12
cd ./googletest/
cmake .
make -j12
cd ../../
cd silly-rpc
cmake .
make -j12
cd ..
