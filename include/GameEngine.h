#pragma once
#include "InformationPlayer.h"
#include "Map.h"
#include <string>
#include <vector>
#include <ncurses.h>
class GameEngine {
    bool keepRunning;
    std::vector<std::string> map;
    InformationPlayer player;
public:
    static constexpr int WIDTH = 30;
    static constexpr int HEIGHT = 13;
    GameEngine();
    void playerMovements(InformationPlayer& player);
    void run(InformationPlayer& player);
};


