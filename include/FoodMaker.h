#pragma once

#include "Appliance.h"
#include "Player.h"

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
    bool produce(Player& player) override;
    int getUpgradeCost() const override;

    void setMode(FoodDrinksMode mode);
    FoodDrinksMode getMode() const;
    std::string getModeName() const;
    int getCurrentPrice() const;

    static void showAvailableModes();
};