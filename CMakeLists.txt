cmake_minimum_required(VERSION 3.12)
project(OssCZipLib C)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_C_STANDARD 11)

find_package(ZLIB)

add_library(ossczip library.c library.h)

target_link_libraries(ossczip ${ZLIB_LIBRARIES})

add_executable(TestZlib test_zlib.c library.c)
target_link_libraries(TestZlib ${ZLIB_LIBRARIES})

install(TARGETS ossczip
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)