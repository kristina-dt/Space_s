#pragma once

#include "Order.h"

#include <memory>
#include <optional>
#include <string>

class Ship {
private:
    float x_;
    float y_;
    float speed_;
    bool active_;
    std::optional<std::shared_ptr<Order>> order_;

public:
    static constexpr float START_X = 120.0f;
    static constexpr float DOCK_X = 20.0f;
    static constexpr float DEFAULT_SPEED = 2.0f;

    Ship();
    Ship(float startX, float y, float speed);
    Ship(float startX, float y, float speed, std::shared_ptr<Order> order);

    void update();

    bool isDocked() const noexcept;
    bool hasOrder() const noexcept;
    bool isActive() const noexcept;



    float getX() const noexcept;
    float getY() const noexcept;
    float getSpeed() const noexcept;

    std::string getOrderInfo() const;
    std::shared_ptr<Order> getOrder() const noexcept;

    void setOrder(std::shared_ptr<Order> order);
    void clearOrder();
    int completeOrderAndGetReward();
};


