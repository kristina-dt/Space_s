#include <gtest/gtest.h>
#include "../include/Wallet.h"
#include "../include/NotEnoughMoney.h"
TEST(WalletTest, Constructor) {
    Wallet wallet(100);
    EXPECT_EQ(wallet.getBal(), 100);
}

TEST(WalletTest, ConstructorNegative) {
    Wallet wallet(-50);
    EXPECT_EQ(wallet.getBal(), 0);
}