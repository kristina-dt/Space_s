#pragma once

#include "Appliance.h"
#include "InformationPlayer.h"
#include <string>

class FuelMaker : public Appliance {
public:
    FuelMaker(int x, int y);

    std::string getType() const override;
    bool produce(InformationPlayer& player) override;
    int getUpgradeCost() const override;

    int getFuelPrice() const;
};