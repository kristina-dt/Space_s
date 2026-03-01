

class Wallet {
private:
    int balance;
public:
    explicit Wallet (int initialMoney) : balance(initialMoney) {
        if (initialMoney<0) {
            balance =0;
        }
    }
    Wallet(const Wallet&) = delete;
    Wallet& operator=(const Wallet&) = delete;
    Wallet(Wallet&& other) noexcept : balance(other.balance) {
        other.balance = 0;
    }
};