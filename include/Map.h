#pragma once
#include <vector>
#include <string>

class Map {
    std::vector<std::string> map;
public:
    static constexpr int WIDTH = 30;
    static constexpr int HEIGHT = 13;
    Map();
    void draw() const;
};
