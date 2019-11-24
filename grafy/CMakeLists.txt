cmake_minimum_required(VERSION 3.15)
project(grafy)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(grafy
        main.cpp Graph.cpp Graph.h List.cpp List.h)
