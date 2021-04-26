cmake_minimum_required(VERSION 3.10)
project(demo-back-end)

add_library(demo-back-end SHARED demo_back_end.cpp)
target_link_libraries(demo-back-end demo-protocol-service)
target_include_directories(demo-back-end INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

set(include-header-location "${CMAKE_SOURCE_DIR}/inc")
set(src-location "${CMAKE_SOURCE_DIR}/src")

include_directories(${include-header-location} ${src-location})

install(TARGETS demo-back-end
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
