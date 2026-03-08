
#include "ProductionManager.h"

ProductionManager::ProductionManager() {
    appliances_.push_back(std::make_unique<FuelMaker>(5, 10));
    appliances_.push_back(std::make_unique<PartAssembler>(8, 12));
    appliances_.push_back(std::make_unique<FoodAndDrinksStation>(3, 7));
    std::cout << "\nProduction Manager initialized with "
              << appliances_.size() << " appliances\n";
    std::cout << "   Station 0: Fuel Synthesizer at (5, 10)\n";
    std::cout << "   Station 1: Universal Assembler at (8, 12)\n";
    std::cout << "   Station 2: Food & Drinks Station at (3, 7)\n";
}

Appliance* ProductionManager::getAppliance(int index) {
    if (index >= 0 && index < static_cast<int>(appliances_.size())) {
        return appliances_[index].get();
    }
    std::cout << "Invalid appliance index! Use 0-" << appliances_.size()-1 << "\n";
    return nullptr;
}

size_t ProductionManager::getCount() const {
    return appliances_.size();
}

int ProductionManager::findNearbyAppliance(int playerX, int playerY) const {
    for (size_t i = 0; i < appliances_.size(); ++i) {
        if (appliances_[i]->canInteract(playerX, playerY)) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

Position ProductionManager::getAppliancePosition(int index) const {
    if (index >= 0 && index < static_cast<int>(appliances_.size())) {
        return appliances_[index]->getPosition();
    }
    return Position(-1, -1);
}

void ProductionManager::produceAll(Player& player) {
    std::cout << "\n🔨🔨🔨 PRODUCTION CYCLE 🔨🔨🔨\n";

    for (size_t i = 0; i < appliances_.size(); ++i) {
        std::cout << "\n▶ Station #" << i << " (" << appliances_[i]->getType() << "):\n";
        appliances_[i]->produce(player);
    }

    std::cout << "\n Production cycle completed!\n";
}

void ProductionManager::produceAt(size_t index, Player& player) {
    if (index < appliances_.size()) {
        std::cout << "\n▶ Station #" << index << " (" << appliances_[index]->getType() << "):\n";
        appliances_[index]->produce(player);
    } else {
        std::cout << "Invalid station index! Use 0-" << appliances_.size()-1 << "\n";
    }
}

void ProductionManager::upgradeAppliance(size_t index, Player& player) {
    if (index >= appliances_.size()) {
        std::cout << "Invalid station index! Use 0-" << appliances_.size()-1 << "\n";
        return;
    }

    Appliance* app = appliances_[index].get();
    int cost = app->getUpgradeCost();

    std::cout << "\n⚡ UPGRADE ATTEMPT ⚡\n";
    std::cout << "   Station: " << app->getType() << "\n";
    std::cout << "   Current level: " << app->getLevel() << "\n";
    std::cout << "   Upgrade cost: " << cost << " credits\n";

    try {
        player.spendMoney(cost);

        app->upgrade();

        std::cout << " Upgrade successful!\n";
        std::cout << "   New level: " << app->getLevel() << "\n";
        std::cout << "   New product price: " << getProductPrice(index) << " credits\n";

    } catch (const std::exception& e) {
        std::cout << " Upgrade failed: " << e.what() << "\n";
        std::cout << "   You need " << cost << " credits to upgrade\n";
    }
}

void ProductionManager::configurePartAssembler(int index, int modeIndex) {
    if (index < 0 || index >= static_cast<int>(appliances_.size())) {
        std::cout << " Invalid station index!\n";
        return;
    }

    PartAssembler* assembler = dynamic_cast<PartAssembler*>(appliances_[index].get());

    if (assembler) {
        PartAssemblerMode mode;
        std::string modeName;

        switch(modeIndex) {
            case 0:
                mode = PartAssemblerMode::Details;
                modeName = "Details";
                break;
            case 1:
                mode = PartAssemblerMode::Decorations;
                modeName = "Decorations";
                break;
            default:
                std::cout << "Invalid mode! Use 0 (Details) or 1 (Decorations)\n";
                return;
        }

        assembler->setMode(mode);
        std::cout << " Part Assembler now produces: " << modeName << "\n";

    } else {
        std::cout << "Station #" << index << " is not a Part Assembler!\n";
        std::cout << "   This station is: " << appliances_[index]->getType() << "\n";
    }
}

void ProductionManager::configureFoodDrinksStation(int index, int modeIndex) {

    if (index < 0 || index >= static_cast<int>(appliances_.size())) {
        std::cout << "Invalid station index!\n";
        return;
    }

    FoodAndDrinksStation* station = dynamic_cast<FoodAndDrinksStation*>(appliances_[index].get());

    if (station) {
        FoodDrinksMode mode;
        std::string modeName;

        switch(modeIndex) {
            case 0:
                mode = FoodDrinksMode::Food;
                modeName = "Food";
                break;
            case 1:
                mode = FoodDrinksMode::Drinks;
                modeName = "Drinks";
                break;
            default:
                std::cout << "Invalid mode! Use 0 (Food) or 1 (Drinks)\n";
                return;
        }

        station->setMode(mode);
        std::cout << "Food & Drinks Station now produces: " << modeName << "\n";

    } else {
        std::cout << "Station #" << index << " is not a Food & Drinks Station!\n";
        std::cout << " This station is: " << appliances_[index]->getType() << "\n";
    }
}

std::string ProductionManager::getProductName(int index) const {
    if (index < 0 || index >= static_cast<int>(appliances_.size())) {
        return "Unknown";
    }
    std::string type = appliances_[index]->getType();

    if (type == "FuelMaker") {
        return "Fuel";
    }
    else if (type == "PartAssembler") {
        PartAssembler* assembler = dynamic_cast<PartAssembler*>(appliances_[index].get());
        if (assembler) {
            return assembler->getModeName();
        }
        return "Unknown";
    }
    else if (type == "FoodAndDrinksStation") {
        FoodAndDrinksStation* station = dynamic_cast<FoodAndDrinksStation*>(appliances_[index].get());
        if (station) {
            return station->getModeName();
        }
        return "Unknown";
    }

    return "Unknown";
}

int ProductionManager::getProductPrice(int index) const {
    if (index < 0 || index >= static_cast<int>(appliances_.size())) {
        return 0;
    }

    std::string type = appliances_[index]->getType();

    if (type == "FuelMaker") {
        FuelMaker* maker = dynamic_cast<FuelMaker*>(appliances_[index].get());
        return maker ? maker->getFuelPrice() : 0;
    }
    else if (type == "PartAssembler") {
        PartAssembler* assembler = dynamic_cast<PartAssembler*>(appliances_[index].get());
        return assembler ? assembler->getCurrentPrice() : 0;
    }
    else if (type == "FoodAndDrinksStation") {
        FoodAndDrinksStation* station = dynamic_cast<FoodAndDrinksStation*>(appliances_[index].get());
        return station ? station->getCurrentPrice() : 0;
    }

    return 0;
}