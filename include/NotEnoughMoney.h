//
// Created by Arina on 06.03.2026.
//
#pragma once

#include <string>
#include <stdexcept>

class NotEnoughMoney : public std::runtime_error {
public:
    explicit NotEnoughMoney(const std::string& message) : std:: runtime_error(message) {}
};


