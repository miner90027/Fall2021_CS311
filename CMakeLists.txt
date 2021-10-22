#Master CMakeLists.txt file
#This file contains an executable for the main file in each subdirectory.

cmake_minimum_required(VERSION 3.20)
project(Fall2021_CS311)

set(CMAKE_CXX_STANDARD 17)

#all of the subdirectories
add_subdirectory(Project1)
add_subdirectory(Project2)
add_subdirectory(Project3)
add_subdirectory(Project4)
add_subdirectory(Project5)

#all of the executable files
add_executable(GlobeProject1 Project1/delivery_test.cpp Project1/delivery.cpp Project1/delivery.h)
add_executable(GlobeProject2 Project2/ssarray_test.cpp Project2/ssarray.h)
add_executable(GlobeProject3 Project3/dp3_test.cpp Project3/dp3.h Project3/dp3.cpp)
add_executable(GlobeProject4 Project4/hdtcount_test.cpp Project4/hdtcount.cpp Project4/hdtcount.h)
add_executable(GlobeProject5 Project5/fsarray.cpp Project5/fsarray.h Project5/fstarray_test.cpp)