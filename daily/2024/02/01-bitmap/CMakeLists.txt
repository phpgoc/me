cmake_minimum_required(VERSION 3.28)
project(01_bitmap)

set(CMAKE_CXX_STANDARD 17)

add_library(01_bitmap bitmap.cpp)

add_executable(test test.cpp)
target_link_libraries(test 01_bitmap)