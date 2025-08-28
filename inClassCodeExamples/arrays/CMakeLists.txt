cmake_minimum_required(VERSION 4.0)
project(arrayDemo)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")
message("${CMAKE_CXX_FLAGS}")
add_executable(arrays main.cpp)

