#include "Wallet.h"
#include <string>

Wallet::Wallet(int initialAmount) noexcept : balance(initialAmount) {
    if (initialAmount<0) {
        balance = 0;
    }
}
Wallet::Wallet(Wallet &&other) noexcept : balance(other.balance) {
    other.balance = 0;
}
void Wallet::withdraw(int amount) {
    if (amount > balance) {
        throw NotEnoughMoney( "Not enough money. Need:" + std::to_string(amount) +
            ", available: " + std::to_string(balance));
    }
    balance -= amount;
}
void Wallet::deposit(int amount) {
    balance+=amount;
}
int Wallet::getBal() const {
    return balance;
}





