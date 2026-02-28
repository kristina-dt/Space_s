cmake_minimum_required(VERSION 3.20)
project(MyProject)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(src)
include_directories(include)

add_executable(SpaceGame main.cpp src/Map.cpp src/Player.cpp)
