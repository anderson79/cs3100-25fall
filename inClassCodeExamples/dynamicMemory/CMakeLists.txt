cmake_minimum_required(VERSION 4.0)
project(dynamicMemory)

set(CMAKE_CXX_STANDARD 20)

# g++ has an extension that allows variable length arrays (vla)
# we don't want this as it allows variable sized arrays on the stack
# this compiler flag will disable that feature
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message("GNU compiler detected, disabling variable length arrays")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=vla")
endif()


add_executable(dynamicMemory main.cpp)
