cmake_minimum_required(VERSION 3.31)
project(my_queue)

set(CMAKE_CXX_STANDARD 20)

add_executable(my_queue main.cpp
        my_queue.h
        my_vector.h)
