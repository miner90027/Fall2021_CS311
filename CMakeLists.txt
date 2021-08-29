cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp)
add_subdirectory(TestSeperateProject)
add_executable(test testSeperateProject/main2.cpp)