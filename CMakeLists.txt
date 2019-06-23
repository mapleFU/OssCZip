cmake_minimum_required(VERSION 3.12)
project(OssCZipLib C)

set(CMAKE_C_STANDARD 11)

find_package(ZLIB)

add_library(OssCZipLib library.c library.h)

target_link_libraries(OssCZipLib ${ZLIB_LIBRARIES})

add_executable(TestZlib test_zlib.c library.c)
target_link_libraries(TestZlib ${ZLIB_LIBRARIES})