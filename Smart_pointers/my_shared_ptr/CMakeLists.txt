cmake_minimum_required(VERSION 3.31)
project(my_shared_ptr)

set(CMAKE_CXX_STANDARD 20)

add_executable(my_shared_ptr main.cpp
        my_shared_ptr.h)
