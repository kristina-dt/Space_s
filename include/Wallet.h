

#pragma once
#include <ostream>

class Wallet {
private:
    int balance;
public:
    Wallet (int initialAmount) noexcept;
    void withdraw(int amount);
    void deposit(int amount);
    int getBal() const;
};
std::ostream& operator<<(std::ostream& os, const Wallet& wal);

