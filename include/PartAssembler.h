#pragma once
#include "Appliance.h"
#include "Player.h"
#include <variant>
#include <string>
#include <iostream>

struct Decorations {
    std::string getName() const { return "Circuit"; }
    int getBaseValue() const { return 50; }
    int getProductionAmount(int rate) const { return rate / 2; }  // Вдвое меньше
};

struct Details {
    std::string getName() const { return "Decoration"; }
    int getBaseValue() const { return 30; }
    int getProductionAmount(int rate) const { return rate; }
};


class PartAssembler : public Appliance {
private:
    ProductType currentProduct = std::variant<Details, Decorations>{};
public:
    PartAssembler() {
        name_ = "Part Assembler";
        baseProductionRate_ = 10;
        level_ = 1;
    }

    std::string getType() const override {
        return "PartAssembler";
    }

    template<typename T>
    void setProduct() {
        currentProduct_ = T{};
        std::cout << "Part Assembler switched to: "
                  << getCurrentProductName() << std::endl;
    }

    void setProductByIndex(int index) {
        switch(index) {
            case 0: currentProduct_ = Details{}; break;
            case 1: currentProduct_ = Decorations{}; break;
            default: currentProduct_ = SimpleGear{};
        }
        std::cout << "Part Assembler switched to: "
                  << getCurrentProductName() << std::endl;
    }

    std::string getCurrentProductName() const {
        return std::visit([](const auto& product) {
            return product.getName();
        }, currentProduct_);
    }

    int getCurrentProductValue() const {
        return std::visit([](const auto& product) {
            return product.getBaseValue();
        }, currentProduct_);
    }
    static void showAvailableProducts() {
        std::cout << "\n=== Available Products ===\n";
        std::cout << "0. Simple Gear (Basic part) - 20 solars\n";
        std::cout << "1. Decorations - 30 solars\n";
        std::cout << "========================\n";
    }
};