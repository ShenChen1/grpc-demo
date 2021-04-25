cmake_minimum_required(VERSION 3.10)
project(grpc-demo-protocol)

include(cmake/grpc.cmake)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/src/protocol/cmake")
find_package(Protobuf REQUIRED)
find_package(GRPC REQUIRED)

grpc_generate_sources(GENERATED_GRPC_SRC
    "${CMAKE_CURRENT_SOURCE_DIR}/proto/rpc.proto")
protobuf_generate_cpp(GENERATED_PB_SRC GENERATED_PB_HDR
    "${CMAKE_CURRENT_SOURCE_DIR}/proto/rpc.proto")

set(GRPC_WRAPPER_CLIENT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/client")
set(GRPC_WRAPPER_SERVICE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/service")

file(GLOB_RECURSE GRPC_WRAPPER_SERVICE_SRC "${GRPC_WRAPPER_SERVICE_DIR}/*.cpp")
file(GLOB_RECURSE GRPC_WRAPPER_CLIENT_SRC "${GRPC_WRAPPER_CLIENT_DIR}/*.cpp")

add_library(demo-protocol-generated STATIC "${GENERATED_GRPC_SRC}" "${GENERATED_PB_SRC}")
target_include_directories(demo-protocol-generated PUBLIC "${CMAKE_CURRENT_BINARY_DIR}")
target_link_libraries(demo-protocol-generated "${GRPC_LINK_LIBRARIES}")

set(include-header-location "${CMAKE_SOURCE_DIR}/src" "${CMAKE_SOURCE_DIR}/src/protocol")
include_directories("${include-header-location}")

add_library(demo-protocol-service SHARED "${GRPC_WRAPPER_SERVICE_SRC}")
target_include_directories(demo-protocol-service PUBLIC "${GRPC_WRAPPER_SERVICE_DIR}" "${include-header-location}")
target_link_libraries(demo-protocol-service demo-protocol-generated)

add_library(demo-protocol-client SHARED "${GRPC_WRAPPER_CLIENT_SRC}")
target_include_directories(demo-protocol-client PUBLIC "${GRPC_WRAPPER_CLIENT_DIR}" "${include-header-location}")
target_link_libraries(demo-protocol-client demo-protocol-generated)

install(TARGETS demo-protocol-client demo-protocol-service LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}")