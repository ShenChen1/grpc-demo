cmake_minimum_required(VERSION 3.10)
project(demo-tests)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBGTEST REQUIRED gtest)
pkg_check_modules(LIBGTEST_MAIN REQUIRED gtest_main)
pkg_check_modules(LIBGMOCK REQUIRED gmock)

include_directories(${LIBGTEST_INCLUDE_DIRS} ${LIBGTEST_MAIN_INCLUDE_DIRS} ${LIBGMOCK_INCLUDE_DIRS})
add_compile_options(${LIBGTEST_CFLAGS_OTHER} ${LIBGTEST_MAIN_CFLAGS_OTHER} ${LIBGMOCK_CFLAGS_OTHER})

add_subdirectory(sc-tests)
add_subdirectory(unit-tests)