cmake_minimum_required(VERSION 3.10)
project(grpc-demo-daemon)

include_directories(${include-header-location} ${src-location})
link_directories(${include-header-location} ${src-location})

add_executable(demo-daemon main.cpp)
target_link_libraries(demo-daemon demo-back-end)
install(TARGETS demo-daemon DESTINATION ${CMAKE_INSTALL_SBINDIR})