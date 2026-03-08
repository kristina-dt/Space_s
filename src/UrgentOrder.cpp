
#include "../include/UrgentOrder.h"
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
UrgentOrder::UrgentOrder(Resource::Type resource, int amount, int baseReward, int urgencyBonus)
    : resource_(resource),
      amount_(amount),
      baseReward_(baseReward),
      urgencyBonus_(urgencyBonus) {}

std::string UrgentOrder::typeName() const {
    return "Urgent";
}
std::string UrgentOrder::describe() const {
    std::ostringstream out;
    out << "[" << typeName() << "] Need "
        << amount_ << " units of "
        << resourceTypeToString(resource_)
        << " as soon as possible. Reward: "
        << rewardMoney() << " credits.";
    return out.str();
}
int UrgentOrder::priority() const noexcept {
    return 2;
}
int UrgentOrder::rewardMoney() const noexcept {
    return baseReward_ + urgencyBonus_;
}
Resource::Type UrgentOrder::resourceType() const noexcept {
    return resource_;
}
int UrgentOrder::amount() const noexcept {
    return amount_;
}
std::unique_ptr<Order> UrgentOrder::clone() const {
    return std::make_unique<UrgentOrder>(*this);
}
