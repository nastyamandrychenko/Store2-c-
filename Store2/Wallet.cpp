#include"Wallet.h"

void Wallet::setWalletBalance(double num) {
    walletBalance = num;
};
double Wallet::getWalletBalance() {
    return walletBalance;
};
void Wallet::addToWalletBalance(double add) {
    walletBalance += add;
};
void Wallet::removeFromWalletBalance(double remove) {
    walletBalance = walletBalance - remove;
};