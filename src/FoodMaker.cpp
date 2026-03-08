#include "FoodAndDrinksStation.h"
#include <iostream>

FoodAndDrinksStation::FoodAndDrinksStation() {
    name_ = "Food & Drinks Station";
}

std::string FoodAndDrinksStation::getType() const {
    return "FoodAndDrinksStation";
}

void FoodAndDrinksStation::setMode(FoodDrinksMode mode) {
    currentMode_ = mode;
    std::cout << name_ << " switched to: " << getModeName() << "\n";
}

FoodDrinksMode FoodAndDrinksStation::getMode() const {
    return currentMode_;
}

std::string FoodAndDrinksStation::getModeName() const {
    switch(currentMode_) {
        case FoodDrinksMode::Food: return "Food";
        case FoodDrinksMode::Drinks: return "Drinks";
        default: return "Unknown";
    }
}

int FoodAndDrinksStation::getCurrentPrice() const {
    switch(currentMode_) {
        case FoodDrinksMode::Food:
            return 30 + (level_ - 1) * 12;     // Food: 30, 42, 54...(cost of 1 unit)
        case FoodDrinksMode::Drinks:
            return 20 + (level_ - 1) * 8;      // Drinks: 20, 28, 36...
        default:
            return 0;
    }
}

bool FoodAndDrinksStation::produce(Player& player) {
    int price = getCurrentPrice();
    std::string productName = getModeName();

    player.addResource(productName, 1);

    std::cout << name_ << " (Lvl " << level_ << ") produced 1 " << productName << "\n";
    std::cout << "   Price: " << price << " credits\n";
    std::cout << "   Total " << productName << ": "
              << player.getResourceAmount(productName) << "\n";

    return true;
}

int FoodAndDrinksStation::getUpgradeCost() const {
    return 180 * level_;
}

void FoodAndDrinksStation::showAvailableModes() {
    std::cout << "\n=== Available Modes ===\n";
    std::cout << "0. Food\n";
    std::cout << "1. Drinks\n";
    std::cout << "=======================\n";
}