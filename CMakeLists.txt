cmake_minimum_required(VERSION 3.20)
project(MyProject)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(src)
include_directories(include)

add_executable(SpaceGame main.cpp
        src/wallet.cpp
        include/wallet.h)
target_link_libraries(SpaceGame PRIVATE GameLogic)