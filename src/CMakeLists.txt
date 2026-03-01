add_library(GameLogic
        Player.cpp
        Map.cpp
        Wallet.cpp
        ../include/Wallet.h
)
target_include_directories(GameLogic  PUBLIC ../include)