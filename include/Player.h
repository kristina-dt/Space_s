#pragma once
class Player {
    int x,y;
public:
    Player(int startX , int startY);
    constexpr int getX() const;
    constexpr int getY() const;
};
