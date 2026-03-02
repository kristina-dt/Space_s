#include "GameEngine.h"
#include "../include/GameEngine.h"

GameEngine::GameEngine(): player(2,2){
    gameMap={
        "------------------------------",
        "|                            |",
        "|                            |",
        "|                            |",
        "|                            |",
        "|                            |",
        "|                            |",
        "|                            |",
        "|                            |",
        "|                            |",
        "|                            |",
        "|                            |",
        "------------------------------",
        };
}

void GameEngine::drawOnce() {
    gameMap.WholeMap(gameMap, player);
}

