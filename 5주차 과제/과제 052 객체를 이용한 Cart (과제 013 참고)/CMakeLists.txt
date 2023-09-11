cmake_minimum_required(VERSION 3.24)
project(task6_objectCart)

set(CMAKE_CXX_STANDARD 17)

add_executable(task6_objectCart main.cpp Cart.h Checkout.h Item.h Cart.cpp Checkout.cpp)
