
#pragma once
#include "Wallet.h"
#include <string>
#include <vector>
#include <map>
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
    std::vector<Resource> inventory;
    static constexpr float posX = 2.2, posY=2.2;
    Wallet wallet;
    std::map<Resource::Type, int> sellPrice;
public:
    InformationPlayer (const std::string namePlayer, const std::string s, int a, float py, float px, int startMoney);
    std::string getName()const;
    std::string getSex()const;
    constexpr float getX()const{return posX;};
    constexpr float getY()const{return posY;};
    Wallet& getWal();
    void SetPosition(float x, float y);
    bool sell(Resource::Type type, int amount);
    bool addResource(Resource::Type type, int amount);
    bool sellTakeMoney(Resource::Type type, int amount);
    int getSellPrice(Resource::Type type) const;
    int getAmountResource(Resource::Type type) const;
    void print() const;
};


