#pragma once

#include "Appliance.h"
#include "InformationPlayer.h"
#include <string>

enum class PartAssemblerMode {
    Details,
    Decorations
};

class PartAssembler : public Appliance {
private:
    PartAssemblerMode currentMode_ = PartAssemblerMode::Details;

public:
    PartAssembler(int x, int y);

    std::string getType() const override;
    bool produce(InformationPlayer& player) override;
    int getUpgradeCost() const override;

    void setMode(PartAssemblerMode mode);
    PartAssemblerMode getMode() const;
    std::string getModeName() const;
    int getCurrentPrice() const;
    Resource::Type getResourceType() const;

    static void showAvailableModes();
};