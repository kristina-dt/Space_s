cmake_minimum_required(VERSION 3.20)
project(MyProject)
set(CMAKE_CXX_STANDARD 23)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

find_package(Curses REQUIRED)
include(cmake/config.cmake)

add_subdirectory(src)
include_directories(include)

add_executable(SpaceGame main.cpp
        src/Map.cpp
        src/NotEnoughMoney.cpp
        src/GameEngine.cpp
        src/Appliance.cpp
        src/FoodMaker.cpp
        src/FuelMaker.cpp
        src/InformationPlayer.cpp
        src/Order.cpp
        src/PartAssembler.cpp
        src/ProductionManager.cpp
        src/ResourceOrder.cpp
        src/Ship.cpp
        src/UrgentOrder.cpp
        src/Wallet.cpp
)
target_link_libraries(SpaceGame PRIVATE GameLogic ${CURSES_LIBRARIES})

enable_testing()

add_executable(
        test_ex
        test/test_ex.cpp
)
target_link_libraries(
        test_ex
        GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(test_ex)
