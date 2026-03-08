//
// Created by Greta Yugay on 08.03.2026.
//

#include "Order.h"
#include <sstream>

ResourceOrder::ResourceOrder(ResourceType resource, int amount, int baseReward): resource_(resource), amount_(amount), baseReward_(baseReward) {}

std::string ResourceOrder::typeName() const {
    return "Regular";
}
std::string ResourceOrder::describe() const {
    std::ostringstream out;
    out << "[" << typeName() << "] Need "
        << amount_ << " units of "
        << toString(resource_)
        << ". Reward: " << rewardMoney() << " credits.";
    return out.str();
}
int ResourceOrder::priority() const noexcept {
    return 1;
}
int ResourceOrder::rewardMoney() const noexcept {
    return baseReward_;
}
ResourceType ResourceOrder::resourceType() const noexcept {
    return resource_;
}
int ResourceOrder::amount() const noexcept {
    return amount_;
}
std::unique_ptr<Order> ResourceOrder::clone() const {
    return std::make_unique<ResourceOrder>(*this);
}
