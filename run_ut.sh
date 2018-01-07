# Copyright 2018 lilde90. All Rights Reserved.
# Author: Pan Li (panli.me@gmail.com)
#!/bin/bash
# Run All The Unittest
cd ./silly-rpc/unittest/base/
./silly-rpc_unittest_*
cd ../core/
./silly-rpc_unittest_*
