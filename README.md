# grpc-demo

# build
```
cmake -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=root
cmake --build build -v
cmake  --install build -v
```

# run
```
root@sc:/opt/grpc-demo# LD_LIBRARY_PATH=./root/lib/ ./root/bin/demo-daemon

root@sc:/opt/grpc-demo# ./build/tests/sc-tests/sc-test-app
Running main() from /build/googletest-j5yxiC/googletest-1.10.0/googletest/src/gtest_main.cc
[==========] Running 3 tests from 3 test suites.
[----------] Global test environment set-up.
[----------] 1 test from DummyTest
[ RUN      ] DummyTest.CheckNothing
[       OK ] DummyTest.CheckNothing (0 ms)
[----------] 1 test from DummyTest (0 ms total)

[----------] 1 test from DummyRun
[ RUN      ] DummyRun.CheckReturnedValue
[       OK ] DummyRun.CheckReturnedValue (1 ms)
[----------] 1 test from DummyRun (1 ms total)

[----------] 1 test from DummyRunAsync
[ RUN      ] DummyRunAsync.CheckReturnedValue
[       OK ] DummyRunAsync.CheckReturnedValue (0 ms)
[----------] 1 test from DummyRunAsync (0 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 3 test suites ran. (1 ms total)
[  PASSED  ] 3 tests.
```

# test with grpc_cli
```
root@sc:/opt/grpc-demo# ./grpc_cli call unix:/tmp/grpc-rpc rpc.Demo.run "Request: 'peter'"
connecting to unix:/tmp/grpc-rpc
Response: "Hello peter"
Rpc succeeded with OK status
```