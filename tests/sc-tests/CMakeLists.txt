cmake_minimum_required(VERSION 3.10)
project(sc-test-app)

include_directories(${CMAKE_INSTALL_INCLUDEDIR}})
include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/inc)

file(GLOB_RECURSE sc-test-app_SRC FOLLOW_SYMLINKS "*.cpp")
add_executable(sc-test-app ${sc-test-app_SRC})

target_link_libraries(sc-test-app
    ${LIBGTEST_LDFLAGS}
    ${LIBGTEST_MAIN_LDFLAGS}
    ${LIBGMOCK_LDFLAGS}
    demo-front-end)