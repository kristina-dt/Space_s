

#pragma once
#include <ostream>

class Wallet {
private:
    int balance;
public:
    Wallet (int initialAmount) noexcept;
    Wallet (const Wallet&) = delete;
    Wallet& operator=(const Wallet) = delete;
    void withdraw(int amount);
    void deposit(int amount);
    int getBal() const;
};
std::ostream& operator<<(std::ostream& os, const Wallet& wal);

