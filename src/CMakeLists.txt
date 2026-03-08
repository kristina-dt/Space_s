add_library(GameLogic
        Map.cpp
        NotEnoughMoney.cpp
        ../include/NotEnoughMoney.h
        Order.cpp
)
target_include_directories(GameLogic  PUBLIC ../include)