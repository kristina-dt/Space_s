#pragma once

#include "Appliance.h"
#include "Player.h"
#include <string>

class FuelMaker : public Appliance {
public:
    FuelMaker(int x, int y);

    std::string getType() const override;
    bool produce(Player& player) override;
    int getUpgradeCost() const override;

    int getFuelPrice() const;
};