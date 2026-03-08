#pragma once

#include "Appliance.h"
#include "FuelMaker.h"
#include "PartAssembler.h"
#include "FoodMaker.h"
#include "Player.h"
#include <vector>
#include <memory>
#include <iostream>

class ProductionManager {
private:
    std::vector<std::unique_ptr<Appliance>> appliances_;

public:
    ProductionManager();
    Appliance* getAppliance(int index);
    size_t getCount() const;
    void showAllAppliances() const;
    void produceAll(Player& player);
    void produceAt(size_t index, Player& player);
    void upgradeAppliance(size_t index, Player& player);
    void configurePartAssembler(int index, int modeIndex);
    void configureFoodDrinksStation(int index, int modeIndex);
    std::string getProductName(int index) const;

    int getProductPrice(int index) const;
};