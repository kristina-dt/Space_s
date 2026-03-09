#include "GameEngine.h"

GameEngine::GameEngine(): player(2,2){
    map={
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

void GameEngine::playerMovements(InformationPlayer &player) {
    int button = getch();
    int nextX = player.getx();
    int nextY = player.gety();

    switch (button) {
        case KEY_UP: case 'w': nextX -= 1.0f; break;
        case KEY_DOWN:  case 's': nextY += 1.0f; break;
        case KEY_LEFT:  case 'a': nextX -= 1.0f; break;
        case KEY_RIGHT: case 'd': nextX += 1.0f; break;
        case 'q': case 'Q':
            this->keepRunning = false;
            break;
    }

    if (nextX >= 0 && nextX <= (WIDTH - 3) && nextY >= 0 && nextY < HEIGHT) {
        player.SetPosition(nextX, nextY);
    }
}

void GameEngine::run(const std::vector<std::string> &map, InformationPlayer &player) {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    this->keepRunning = true;

    while(this->keepRunning) {
        Map::WholeMap(map, player);
        playerMovements(player);
    }

    endwin();
}



