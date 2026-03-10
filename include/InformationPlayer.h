
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
    float posX , posY;
    Wallet wallet;
    std::map<Resource::Type, int> sellPrice;
public:
    static constexpr float startX = 2.0f;
    static constexpr float startY = 2.2f;
    InformationPlayer (const std::string namePlayer, const std::string s, int a, float py, float px, int startMoney);
    std::string getName()const;
    std::string getSex()const;
    float getX()const{return posX;};
    float getY()const{return posY;};
    Wallet& getWal();
    void SetPosition(float x, float y);
    bool sell(Resource::Type type, int amount);
    bool addResource(Resource::Type type, int amount);
    bool sellTakeMoney(Resource::Type type, int amount);
    int getSellPrice(Resource::Type type) const;
    int getAmountResource(Resource::Type type) const;
    void print() const;
};


