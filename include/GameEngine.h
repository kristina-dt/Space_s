#pragma once
#include "Player.h"
#include "Map.h"
#include <string>
#include <vector>
class GameEngine {
    std::vector<std::string> map;
    Player player;
    Map gameMap;
public:
    static constexpr int WIDTH = 30;
    static constexpr int HEIGHT = 13;
    GameEngine();
    void drawOnce();
};


