#include "../include/FoodAndDrinksStation.h"
#include <iostream>

FoodAndDrinksStation::FoodAndDrinksStation(int x, int y) {
    name_ = "Food & Drinks Station";
    position_ = Position(x, y);
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

Resource::Type FoodAndDrinksStation::getResourceType() const {
    switch(currentMode_) {
        case FoodDrinksMode::Food: return Resource::Type::Food;
        case FoodDrinksMode::Drinks: return Resource::Type::Drinks;
        default: return Resource::Type::Food;
    }
}

int FoodAndDrinksStation::getCurrentPrice() const {
    switch(currentMode_) {
        case FoodDrinksMode::Food:
            return 30 + (level_ - 1) * 12;
        case FoodDrinksMode::Drinks:
            return 20 + (level_ - 1) * 8;
        default:
            return 0;
    }
}

bool FoodAndDrinksStation::produce(InformationPlayer& player) {
    int price = getCurrentPrice();
    Resource::Type resourceType = getResourceType();
    std::string typeName = getModeName();

    // Проверяем, может ли игрок заплатить
    Wallet& wallet = player.getWal();
    if (wallet.getAmount() < price) {
        std::cout << "Not enough money! Need " << price
                  << ", have " << wallet.getAmount() << "\n";
        return false;
    }

    // Списываем деньги
    wallet.spend(price);

    // Добавляем ресурс
    player.addResource(resourceType, 1);

    std::cout << "🍳 " << name_ << " (Lvl " << level_ << ") produced 1 " << typeName << "\n";
    std::cout << "   Price: " << price << " credits\n";
    std::cout << "   Money left: " << wallet.getAmount() << "\n";
    std::cout << "   Total " << typeName << ": "
              << player.getAmountResource(resourceType) << "\n";

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