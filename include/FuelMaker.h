#include "Appliance.h"
#include <iostream>

class FuelMaker : public Appliance {
public:
    FuelMaker() {name_ = "Fuel Synthesizer";}

    std::string getType() const override {
        return "FuelMaker";
    }

    bool produce(Player& player) override {
        std::cout << "Producing " << getProductionRate() << " units of Fuel." << std::endl;
        return true;
    }

    void upgrade() override {
        std::cout << "Upgrading Fuel Maker. Cost: " << getUpgradeCost() << std::endl;
        level_++;
    }

    int getUpgradeCost() const override {
        return 100 * level_;
    }
};