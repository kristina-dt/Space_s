// Appliance.h
#pragma once


struct Position {
    int x;
    int y;

    Position(int x = 0, int y = 0) : x(x), y(y) {}

    bool isNearby(int playerX, int playerY, int distance = 2) const {
        int dx = playerX - x;
        int dy = playerY - y;
        return (dx * dx + dy * dy) <= distance * distance;
    }

    std::string toString() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};
class Appliance {
public:
    virtual ~Appliance() = default;
    virtual std::string getType() const = 0;
    virtual bool produce(Player& player) = 0;
    virtual int getUpgradeCost() const = 0;

    virtual void upgrade();
    int getLevel() const { return level_; }
    std::string getName() const { return name_; }

protected:
    Appliance() = default;

    int level_ = 1;
    std::string name_;
};