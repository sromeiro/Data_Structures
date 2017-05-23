cmake_minimum_required(VERSION 3.5)
project(Data_Structures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Project_01/menu.cpp Project_01/CyclicLinkedList.cpp Project_01/SingleNode.cpp)
add_executable(Project_01 ${SOURCE_FILES})