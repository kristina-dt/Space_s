#include "Map.h"
#include "GameEngine.h"
#include <iostream>

void Map::WholeMap(const std::vector<std::string> &map, const Player& player) {
    for (int i = 0; i < GameEngine::WIDTH; ++i) {
        for (int j = 0; j < GameEngine::HEIGHT; ++j) {
            if (i==(player.getX()) && j==(player.getY())) {
                std::cout<<'[^]';
            }
            std::cout << map[i][j];
        }
    }
    std::cout<<'\n';
}
