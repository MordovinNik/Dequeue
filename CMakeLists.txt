cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(PROJECT_NAME DEQueue)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} 
src/main.cpp
src/Dequeue.h
)
