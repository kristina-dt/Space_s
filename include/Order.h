#pragma once

#include "InformationPlayer.h"
#include <memory>
#include <string>

class Order {
public:
    virtual ~Order() = default;

    virtual std::string typeName() const = 0;
    virtual std::string describe() const = 0;
    virtual int priority() const noexcept = 0;
    virtual int rewardMoney() const noexcept = 0;

    virtual Resource::Type resourceType() const noexcept = 0;
    virtual int amount() const noexcept = 0;

    virtual std::unique_ptr<Order> clone() const = 0;
};


