//
// Created by Greta Yugay on 08.03.2026.
//

#ifndef SPACE_S_ORDER_H
#define SPACE_S_ORDER_H

#include <cstdint>
#include <memory>
#include <string>
enum class ResourceType {
    Fuel,
    Food,
    Drinks,
    Details,
    Decorations
};

inline std::string toString(ResourceType type) {
    switch (type) {
        case ResourceType::Fuel:        return "Fuel";
        case ResourceType::Food:        return "Food";
        case ResourceType::Drinks:      return "Drinks";
        case ResourceType::Details:     return "Details";
        case ResourceType::Decorations: return "Decorations";
    }
    return "Unknown";
}

class Order {
public:
    virtual ~Order() = default;
    virtual std::string typeName() const = 0;
    virtual std::string describe() const = 0;
    virtual int priority() const noexcept = 0;
    virtual int rewardMoney() const noexcept = 0;

    virtual std::unique_ptr<Order> clone() const = 0;
};
class ResourceOrder final : public Order {
private:
    ResourceType resource_;
    int amount_;
    int baseReward_;
public:
    ResourceOrder(ResourceType resource, int amount, int baseReward);
    std::string typeName() const override;
    std::string describe() const override;
    int priority() const noexcept override;
    int rewardMoney() const noexcept override;
    ResourceType resourceType() const noexcept override;
    int amount() const noexcept override;
    std::unique_ptr<Order> clone() const override;
};


#endif //SPACE_S_ORDER_H