
#include "../include/Ship.h"
Ship::Ship()
    : x_(START_X),
      y_(5.0f),
      speed_(DEFAULT_SPEED),
      active_(true),
      order_(std::nullopt) {}

Ship::Ship(float startX, float y, float speed)
    : x_(startX),
      y_(y),
      speed_(speed),
      active_(true),
      order_(std::nullopt) {}

Ship::Ship(float startX, float y, float speed, std::shared_ptr<Order> order)
    : x_(startX),
      y_(y),
      speed_(speed),
      active_(true),
      order_(std::move(order)) {}

void Ship::update() {
    if (!active_) {
        return;
    }

    if (x_ > DOCK_X) {
        x_ -= speed_;
        if (x_ < DOCK_X) {
            x_ = DOCK_X;
        }
    }
}

bool Ship::isDocked() const noexcept {
    return x_ <= DOCK_X;
}

bool Ship::hasOrder() const noexcept {
    return order_.has_value() && static_cast<bool>(*order_);
}

bool Ship::isActive() const noexcept {
    return active_;
}

float Ship::getX() const noexcept {
    return x_;
}

float Ship::getY() const noexcept {
    return y_;
}

float Ship::getSpeed() const noexcept {
    return speed_;
}

std::string Ship::getOrderInfo() const {
    if (!hasOrder()) {
        return "This ship has no order.";
    }
    return (*order_)->describe();
}

std::shared_ptr<Order> Ship::getOrder() const noexcept {
    if (!hasOrder()) {
        return nullptr;
    }
    return *order_;
}

void Ship::setOrder(std::shared_ptr<Order> order) {
    order_ = std::move(order);
}

void Ship::clearOrder() {
    order_ = std::nullopt;
}

int Ship::completeOrderAndGetReward() {
    if (!hasOrder()) {
        return 0;
    }

    const int reward = (*order_)->rewardMoney();
    clearOrder();
    active_ = false;
    return reward;
}