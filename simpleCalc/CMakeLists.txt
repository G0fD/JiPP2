cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(simpleCalc)

add_executable(simpleCalc
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/calc.cpp)

target_include_directories(simpleCalc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)