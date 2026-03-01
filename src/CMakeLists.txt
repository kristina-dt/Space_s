add_library(GameLogic
        Player.cpp
        Map.cpp
        GameEngine.cpp
)
target_include_directories(GameLogic  PUBLIC ../include)