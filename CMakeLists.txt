cmake_minimum_required(VERSION 3.5...3.14)

project(SrvEmail LANGUAGES CXX)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)





add_executable(${PROJECT_NAME}
    main.cpp
    "include/tools.h"
    "source/tools.cpp"
)