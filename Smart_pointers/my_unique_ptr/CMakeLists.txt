cmake_minimum_required(VERSION 3.31)
project(my_unique_ptr)

set(CMAKE_CXX_STANDARD 20)

add_executable(my_unique_ptr main.cpp
        my_unique_ptr.h)
