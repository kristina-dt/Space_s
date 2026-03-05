add_library(GameLogic
        Map.cpp
        NotEnoughMoney.cpp
        ../include/NotEnoughMoney.h
)
target_include_directories(GameLogic  PUBLIC ../include)