cmake_minimum_required(VERSION 3.15)
project(project_03)

set(CMAKE_CXX_STANDARD 17)

add_executable(main
               main.cpp
               AvlTree.h
               BinarySearchTree.h
               SplayTree.h)

add_executable(shuffle_demo
               shuffleVector.cpp)

add_executable(random_demo
               randomNumber.cpp)

add_executable(write_to_file_demo
               writeToFile.cpp)

add_executable(timing_demo
               timing.cpp)