cmake_minimum_required(VERSION 3.10)

project(SpeedyTest VERSION 1.0)

set(CMAKE_CXX_STANDARD          11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory("${PROJECT_SOURCE_DIR}/../include/" "${PROJECT_SOURCE_DIR}/../build/Speedy")

add_executable(SpeedyTest main.cpp)

target_include_directories(SpeedyTest PUBLIC "${PROJECT_SOURCE_DIR}/../include")