#include "../include/Wallet.h"
#include <string>
#include "../include/NotEnoughMoney.h"

Wallet::Wallet(int initialAmount) noexcept : balance(initialAmount) {
    if (initialAmount<0) {
        balance = 0;
    }
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
std::ostream& operator<<(std::ostream& os, const Wallet& wal) {
    os << "Wallet Balance: " << wal.getBal() << " credits";
    return os;

}





