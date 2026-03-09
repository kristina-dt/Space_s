#include "Map.h"
#include "GameEngine.h"
#include <iostream>

void Map::WholeMap(const std::vector<std::string> &map, const InformationPlayer& player) {
    for (int i = 0; i < GameEngine::WIDTH; ++i) {
        for (int j = 0; j < GameEngine::HEIGHT; ++j) {
            if (i==(player.getY()) && j==(player.getX())) {
                printw("[^]");
                j+=2;
            }
            if (j < GameEngine::WIDTH) {
                addch(map[i][j]);
            }
        }
    }
}
