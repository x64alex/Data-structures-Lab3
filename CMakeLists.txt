cmake_minimum_required(VERSION 3.21)
project(Data_structures_Lab3)

set(CMAKE_CXX_STANDARD 14)

include_directories(PriorityQueue)

add_executable(Data_structures_Lab3
        PriorityQueue/App.cpp
        PriorityQueue/ExtendedTest.cpp
        PriorityQueue/ExtendedTest.h
        PriorityQueue/PriorityQueue.cpp
        PriorityQueue/PriorityQueue.h
        PriorityQueue/ShortTest.cpp
        PriorityQueue/ShortTest.h)
