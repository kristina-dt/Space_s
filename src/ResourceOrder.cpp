
#include "../include/ResourceOrder.h"
#include <sstream>

namespace {
    std::string resourceTypeToString(Resource::Type type) {
        switch (type) {
            case Resource::Fuel:        return "Fuel";
            case Resource::Food:        return "Food";
            case Resource::Drinks:      return "Drinks";
            case Resource::Details:     return "Details";
            case Resource::Decorations: return "Decorations";
        }
        return "Unknown";
    }
}
ResourceOrder::ResourceOrder(Resource::Type resource, int amount, int baseReward)
    : resource_(resource), amount_(amount), baseReward_(baseReward) {}

std::string ResourceOrder::typeName() const {
    return "Regular";
}
std::string ResourceOrder::describe() const {
    std::ostringstream out;
    out << "[" << typeName() << "] Need "
        << amount_ << " units of "
        << resourceTypeToString(resource_)
        << ". Reward: " << rewardMoney() << " credits.";
    return out.str();
}
int ResourceOrder::priority() const noexcept {
    return 1;
}
int ResourceOrder::rewardMoney() const noexcept {
    return baseReward_;
}
Resource::Type ResourceOrder::resourceType() const noexcept {
    return resource_;
}
int ResourceOrder::amount() const noexcept {
    return amount_;
}
std::unique_ptr<Order> ResourceOrder::clone() const {
    return std::make_unique<ResourceOrder>(*this);
}