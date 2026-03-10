add_executable(test_wallet test_wallet.cpp)
target_link_libraries(test_wallet
        GTest::gtest_main
        GameLogic
)
target_include_directories(test_wallet PRIVATE ${CMAKE_SOURCE_DIR}/include)
include(GoogleTest)
gtest_discover_tests(test_wallet)
