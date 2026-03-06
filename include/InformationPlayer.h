
#pragma once
#include "Wallet.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
struct Resource {
    enum Type{ Fuel, Food, Drinks, Details, Decorations};
    Type type;
    int amount;
};

class InformationPlayer {
private:
    std::string name;
    std::string sex;
    int age;
    int WorkshopLevel;
    std::vector<Resource> inventory;
    float posX, posY;
    Wallet wallet;
    std::map<Resource::Type, int> buyPrice;
    std::map<Resource::Type, int> sellPrice;
public:



};


