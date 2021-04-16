cmake_minimum_required(VERSION 3.10)
project(grpc-demo-protocol)
cmake_minimum_required(VERSION 3.10)
project(grpc-demo-protocol)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/src/protocol/cmake")
find_package(Protobuf REQUIRED)
find_package(GRPC REQUIRED)