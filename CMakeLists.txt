cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(TestOriginal)
add_executable(masterOrig TestOriginal/main.cpp)
add_subdirectory(TestSeperateProject)
add_executable(masterTest testSeperateProject/main2.cpp)