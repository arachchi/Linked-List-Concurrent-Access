cmake_minimum_required(VERSION 3.3)
project(Cp_Lab_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Node.cpp Node.h Node.cpp Node.h LinkedList.cpp LinkedList.h SerialLinkedList.cpp SerialLinkedList.h ParallelLinkedListWithMutex.cpp ParallelLinkedListWithMutex.h ParallelLinkedListWithReadersWritersLock.cpp ParallelLinkedListWithReadersWritersLock.h)
add_executable(Cp_Lab_2 ${SOURCE_FILES})