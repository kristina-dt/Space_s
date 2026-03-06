

#include "../include/InformationPlayer.h"
#include <iostream>

InformationPlayer::InformationPlayer(const std::string namePlayer, const std::string s, int a, float py, float px, int startMoney) : name(namePlayer),sex(s),age(a), WorkshopLevel(1), posX(px), posY(py), wallet(startMoney) {
    inventory.push_back({Resource::Type::Fuel, 5});
    inventory.push_back({Resource::Type::Food,7});
    inventory.push_back({Resource::Type::Drinks, 7});
    inventory.push_back({Resource::Type::Details, 5});
    inventory.push_back({Resource::Type::Decorations, 0});
    buyPrice[Resource::Type::Details] = 16;
    buyPrice[Resource::Type::Food] = 5;
    buyPrice[Resource::Type::Drinks] = 5;
    buyPrice[Resource::Type::Fuel] = 15;
    buyPrice[Resource::Type::Decorations] = 30;

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
bool InformationPlayer::buyResource(Resource::Type type, int amount) {
    int totalPrice = amount * buyPrice[type];
    try {
        wallet.withdraw(totalPrice);
        addResource(type, amount);
        std::cout<<"Purchased " << amount << " units of resource, you spent: " << totalPrice << '\n';
        return true;
    }
    catch (const NotEnoughMoney& error) {
        std::cout<<"Error! " << error.what() << '\n';
        return false;

    }

}