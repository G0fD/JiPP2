cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(matrixApp)

add_executable(matrixApp
        ${CMAKE_CURRENT_SOURCE_DIR}/matrixApp/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/matrixLib/matrix.cpp)

target_include_directories(matrixApp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/matrixLib)