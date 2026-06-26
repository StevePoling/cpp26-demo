cmake_minimum_required(VERSION 3.14)
project(Cpp26Demo)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(cpp26demo
    src/main.cpp
)

target_include_directories(cpp26demo PRIVATE include)
