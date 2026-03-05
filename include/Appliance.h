#pragma once
#include <string>
#include <memory>

class Appliance {
public:
    virtual ~Appliance() = default;

    virtual std::string getType() const = 0;
    virtual bool produce(Player& player) = 0;
    virtual void upgrade() = 0;
    virtual int getLevel() const { return level; }
    virtual int getUpgradeCost() const = 0;

    int getProductionRate() const { return baseProductionRate * (1 + level * 0.5); }

protected:
    int level = 1;
    int baseProductionRate = 10;
    std::string name;
};