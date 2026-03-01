#include "Player.h"
#include <iostream>
Player::Player(int startX, int startY) : x(startX), y(startY){}

constexpr int Player::getX() const{
    return x;
}

constexpr int Player::getY() const{
    return y;
}

