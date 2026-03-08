#include "FuelMaker.h"
#include <iostream>

FuelMaker::FuelMaker() {
    name_ = "Fuel Synthesizer";
}

std::string FuelMaker::getType() const {
    return "FuelMaker";
}

int FuelMaker::getFuelPrice() const {
    return 20 + (level_ - 1) * 10;
} //cost of fuel increase with the level

bool FuelMaker::produce(Player& player) {
    int price = getFuelPrice();
    int amount = 1;

    player.addResource("Fuel", amount);

    std::cout << name_ << " produced 1 unit of Fuel\n";
    std::cout << "   Price per unit: " << price << " credits\n";
    std::cout << "   Total fuel: " << player.getResourceAmount("Fuel") << "\n";

    return true;
}

int FuelMaker::getUpgradeCost() const {
    return 150 * level_; .
}