
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
    InformationPlayer (const std::string namePlayer, const std::string s, int a, float py, float px, int startMoney);
    std::string getName()const;
    std::string getSex()const;
    constexpr float getX()const;
    constexpr float getY()const;
    int getLevel()const;
    Wallet& getWal();
    void SetPosition(float x, float y);
    void upgradeWorkShop(int cost);
    bool addResource(Resource::Type type, int amount);
    bool buyResource(Resource::Type type, int amount);
    bool sell(Resource::Type type, int amount);
    bool sellTakeMoney(Resource::Type type, int amount);






};


