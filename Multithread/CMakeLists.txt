cmake_minimum_required(VERSION 3.21)
project(Multithread)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(Multithread main.cpp Girl.cpp Girl.h Guy.cpp Guy.h Random.h)
