#Master CMakeLists.txt file
#This file contains an executable for the main file in each subdirectory.

cmake_minimum_required(VERSION 3.20)
project(Fall2021_CS311)

set(CMAKE_CXX_STANDARD 17)

#all of the subdirectories
add_subdirectory(TestOriginal)
add_subdirectory(TestSeperateProject)

#all of the executable files
add_executable(masterTest testSeperateProject/main2.cpp)
add_executable(masterOrig TestOriginal/main.cpp)