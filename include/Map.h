#pragma once
#include "InformationPlayer.h"
#include <vector>
#include <string>
class Map {
public:
   void WholeMap(const std::vector<std::string>& map, const InformationPlayer& player);
};

