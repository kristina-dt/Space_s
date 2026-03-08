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
};


#endif //SPACE_S_ORDER_H