

#pragma once
#include <ostream>
#include "NotEnoughMoney.h"

class Wallet {
private:
    int balance;
public:
    Wallet (int initialAmount) noexcept;
    Wallet (const Wallet&) = default;
    Wallet& operator=(const Wallet) = delete;
    Wallet(Wallet&& other) noexcept;


};


