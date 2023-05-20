#ifndef WALLET_H
#define WALLET_H
class Wallet {
    double walletBalance;
public:
    Wallet(double wallet_) : walletBalance(wallet_) {};

    void setWalletBalance(double num);
    double getWalletBalance();
    void addToWalletBalance(double add);
    void removeFromWalletBalance(double remove);

};
#endif;
