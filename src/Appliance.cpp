#include "../include/Appliance.h"
#include <iostream>

void Appliance::upgrade() {
    level_++;
    std::cout << name_ << " upgraded to level " << level_ << "!\n";
}