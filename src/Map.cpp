#include "Map.h"
#include <iostream>
Map::Map() {
    map = {
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

void Map::draw() const{
    for (const auto& row : map) {
        std::cout << row << '\n';
    }
}
