//
// Created by Greta Yugay on 08.03.2026.
//

#ifndef SPACE_S_ORDER_H
#define SPACE_S_ORDER_H

#include <cstdint>
#include <memory>
#include <string>

enum class ResourceType : std::uint8_t { Fuel, Food, Drinks, Details, Decorations };
std::string to_string(ResourceType t);

class Order {
public:
    virtual ~Order() = default;
    virtual std::string typeName() const = 0;
    virtual std::string describe() const = 0;
    virtual int priority() const noexcept = 0;
    virtual int rewardMoney() const noexcept = 0;

    virtual std::unique_ptr<Order> clone() const = 0;
};


#endif //SPACE_S_ORDER_H