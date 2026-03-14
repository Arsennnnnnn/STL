cmake_minimum_required(VERSION 3.31)
project(my_stack)

set(CMAKE_CXX_STANDARD 20)

add_executable(my_stack main.cpp
        my_stack.h
        my_vector.h)
