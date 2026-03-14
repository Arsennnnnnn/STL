cmake_minimum_required(VERSION 3.31)
project(my_set)

set(CMAKE_CXX_STANDARD 20)

add_executable(my_set main.cpp
        my_set.h
        my_pair.h)
