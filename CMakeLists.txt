cmake_minimum_required(VERSION 3.27)
project(lili)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(./src)

add_executable(lili
        main.cpp)
