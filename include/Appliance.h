#pragma once

#include "InformationPlayer.h"
#include <string>

struct Position {
    int x;
    int y;

    Position(int x = 0, int y = 0) : x(x), y(y) {}

    bool isNearby(float playerX, float playerY, float distance = 2.0f) const {
        float dx = playerX - x;
        float dy = playerY - y;
        return (dx * dx + dy * dy) <= distance * distance;
    }

    std::string toString() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};

class Appliance {
protected:
    Appliance() = default;

    int level_ = 1;
    std::string name_;
    Position position_;
public:
    virtual ~Appliance() = default;

    virtual std::string getType() const = 0;
    virtual bool produce(InformationPlayer& player) = 0;
    virtual int getUpgradeCost() const = 0;

    virtual void upgrade();

    int getLevel() const { return level_; }
    std::string getName() const { return name_; }
    Position getPosition() const { return position_; }

    bool canInteract(float playerX, float playerY, float distance = 2.0f) const {
        return position_.isNearby(playerX, playerY, distance);
    }

};