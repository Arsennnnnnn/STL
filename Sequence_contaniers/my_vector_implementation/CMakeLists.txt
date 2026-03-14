cmake_minimum_required(VERSION 3.31)
project(my_vector_implementation)

set(CMAKE_CXX_STANDARD 20)

add_executable(my_vector_implementation main.cpp
        MyVector.h)
