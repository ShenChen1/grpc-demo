cmake_minimum_required(VERSION 3.10)
project(demo-front-end)

set(include-header-location "${CMAKE_SOURCE_DIR}/inc")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}" "${include-header-location}")

add_library(demo-front-end SHARED front_end.cpp)
target_include_directories(demo-front-end INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(demo-front-end demo-protocol-client)