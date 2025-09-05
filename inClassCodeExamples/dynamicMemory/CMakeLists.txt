cmake_minimum_required(VERSION 4.0)
project(dynamicMemory)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=vla")
add_executable(dynamicMemory main.cpp)
