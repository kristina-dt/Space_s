
#pragma once

#include "Order.h""
class UrgentOrder {
private:
    Resource::Type resource_;
    int amount_;
    int baseReward_;
    int urgencyBonus_;
public:
    UrgentOrder(Resource::Type resource, int amount, int baseReward, int urgencyBonus);

    std::string typeName() const override;
    std::string describe() const override;
    int priority() const noexcept override;
    int rewardMoney() const noexcept override;

    Resource::Type resourceType() const noexcept override;
    int amount() const noexcept override;

    std::unique_ptr<Order> clone() const override;

};


