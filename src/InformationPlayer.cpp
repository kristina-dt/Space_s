

#include "../include/InformationPlayer.h"
#include <iostream>

InformationPlayer::InformationPlayer(const std::string namePlayer, const std::string s, int a, float py, float px, int startMoney) : name(namePlayer),sex(s),age(a), WorkshopLevel(1), posX(px), posY(py), wallet(startMoney) {
    inventory.push_back({Resource::Type::Fuel, 5});
    inventory.push_back({Resource::Type::Food,7});
    inventory.push_back({Resource::Type::Drinks, 7});
    inventory.push_back({Resource::Type::Details, 5});
    inventory.push_back({Resource::Type::Decorations, 0});

    sellPrice[Resource::Type::Decorations] = 45;
    sellPrice[Resource::Type::Details] = 20;
    sellPrice[Resource::Type::Drinks] = 7;
    sellPrice[Resource::Type::Food] = 7;
    sellPrice[Resource::Type::Fuel] = 18;

}

std::string InformationPlayer::getName()const {
    return name;
}
std::string InformationPlayer::getSex()const {
    return sex;
}

int InformationPlayer::getLevel()const{return WorkshopLevel;}
Wallet& InformationPlayer::getWal() {return wallet;}
void InformationPlayer::SetPosition(float x, float y) {
    posX = x;
    posY = y;
}

void InformationPlayer::upgradeWorkShop(int cost) {
    try {
        wallet.withdraw(cost);
        WorkshopLevel++;
        for (auto& price : sellPrice) {
            price.second = static_cast<int>(price.second * (1.0 - WorkshopLevel * 0.03));
        }
        for (auto& price : buyPrice) {
            price.second = static_cast<int>(price.second * (1.0 - WorkshopLevel * 0.05));
        }
        std::cout<<"Congratulations! Now you have " << WorkshopLevel << " level!\n";
        std::cout<<"Now you have new prices!\n";
    }
    catch (const NotEnoughMoney& error) {
        std::cout<<"O, no. Error!!! " << error.what() << '\n';
        throw;
    }
}

bool InformationPlayer::addResource(Resource::Type type, int amount) {
    for (auto& res : inventory) {
        if (res.type == type) {
            res.amount += amount;
            return true;
        }
    }
    return false;
}

bool InformationPlayer::sell(Resource::Type type, int amount) {
    for (auto& res : inventory) {
        if (res.type == type) {
            if (res.amount > amount) {
                res.amount -= amount;
                return true;
            }
            return false;
        }
    }
    return false;
}
bool InformationPlayer::sellTakeMoney(Resource::Type type, int amount) {
    if (sell(type,amount)) {
        int totalCost = amount * sellPrice[type];
        wallet.deposit(totalCost);
        std::cout<<"Awesome!!!Sold " << amount<<" units of resource, you earn: " << totalCost << '\n';
        return true;
    }
    else {
        std::cout<<"Error!!! You can't sell this type of resource!" << '\n';
        return false;
    }
}

int InformationPlayer::getSellPrice(Resource::Type type) const {
    return sellPrice.at(type);
}
int InformationPlayer::getAmountResource(Resource::Type type) const {
    for (const auto& res : inventory) {
        if (res.type == type) {
            return res.amount;
        }
    }
    return 0;
}
void InformationPlayer::print() const {
    std::cout <<"Player's name: " << name << '\n';
    std::cout <<"Player's sex: " << sex << '\n';
    std::cout <<"Player's coordinates: " << posX << " , " << posY << '\n';
    std::cout <<"WorkShop's level: " << WorkshopLevel << '\n';
    std::cout <<"Wallet balance: " << wallet << '\n';
    std::cout<<"Inventory:\n";
    for (const auto& res : inventory) {
        std::string typeName;
        switch (res.type) {
            case Resource::Type::Fuel: typeName = "Fuel"; break;
            case Resource::Type::Food: typeName = "Food"; break;
            case Resource::Type::Drinks: typeName = "Drinks"; break;
            case Resource::Type::Details: typeName = "Details"; break;
            case Resource::Type::Decorations: typeName = "Decorations"; break;
        }
        std::cout << "  - " << typeName << ": " << res.amount << " units\n";
    }
    std::cout<<"Prices for " << WorkshopLevel << " level:\n";
    std::cout<<"Fuel purchase: "  << sellPrice.at(Resource::Type::Fuel) << '\n';
    std::cout<<"Food purchase: " << sellPrice.at(Resource::Type::Food)<<'\n';
    std::cout<<"Drinks purchase: " << sellPrice.at(Resource::Type::Drinks)<<'\n';
    std::cout<<"Details purchase: "  << sellPrice.at(Resource::Type::Details)<<'\n';
    std::cout<<"Decorations purchase: " << sellPrice.at(Resource::Type::Decorations)<<'\n';
}