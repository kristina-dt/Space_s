// Appliance.h
#pragma once


class Appliance {
public:
    virtual ~Appliance() = default;
    virtual std::string getType() const = 0;
    virtual bool produce(Player& player) = 0;
    virtual int getUpgradeCost() const = 0;

    virtual void upgrade();
    int getLevel() const { return level_; }
    std::string getName() const { return name_; }

protected:
    Appliance() = default;x

    int level_ = 1;
    std::string name_;
};