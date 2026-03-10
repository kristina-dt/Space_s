#pragma once

#include "Appliance.h"
#include "InformationPlayer.h"
#include <string>

enum class FoodDrinksMode {
    Food,
    Drinks
};

class FoodAndDrinksStation : public Appliance {
private:
    FoodDrinksMode currentMode_ = FoodDrinksMode::Food;

public:
    FoodAndDrinksStation(int x, int y);

    std::string getType() const override;
    bool produce(InformationPlayer& player) override;
    int getUpgradeCost() const override;

    void setMode(FoodDrinksMode mode);
    FoodDrinksMode getMode() const;
    std::string getModeName() const;
    int getCurrentPrice() const;
    Resource::Type getResourceType() const;

    static void showAvailableModes();
};