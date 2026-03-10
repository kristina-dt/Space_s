cmake_minimum_required(VERSION 3.20)
project(SpaceGame)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

include_directories(include)

add_subdirectory(src)

add_executable(SpaceGame main.cpp)
target_link_libraries(SpaceGame PRIVATE GameLogic)

enable_testing()

add_executable(
        test_wallet
        test/test_wallet.cpp
)

target_link_libraries(
        test_wallet
        GameLogic
        GTest::gtest_main
)

add_executable(
        test_ex
        test/test_ex.cpp
)

target_link_libraries(
        test_ex
        GameLogic
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_wallet)
gtest_discover_tests(test_ex)

