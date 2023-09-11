cmake_minimum_required(VERSION 3.24)
project(StackException)

set(CMAKE_CXX_STANDARD 17)

add_executable(StackException Stack.h StackException.h main.cpp)
