cmake_minimum_required(VERSION 3.16)

project(lab5)
include_directories(include)

add_executable(lab5 ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Point.cpp)