cmake_minimum_required(VERSION 3.10)
project(grpc-demo)

set(CMAKE_CXX_STANDARD 17)
if("${CMAKE_BUILD_TYPE}" STREQUAL "")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()
add_compile_options(-Wall -Wextra -Werror)

add_subdirectory(protocol)
add_subdirectory(back-end)
add_subdirectory(front-end)
add_subdirectory(daemon)