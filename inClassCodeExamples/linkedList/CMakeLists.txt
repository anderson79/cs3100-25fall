cmake_minimum_required(VERSION 4.0)
project(linkedList)

set(CMAKE_CXX_STANDARD 20)

add_executable(linkedList main.cpp
        Student.cpp
        Student.h
        GradeNode.cpp
        GradeNode.h
)
