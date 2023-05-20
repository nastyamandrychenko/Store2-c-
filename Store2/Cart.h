#ifndef CART_H
#define CART_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include  <sstream>
using namespace std;

template <typename T>
class Cart {
private:
    vector<pair<T*, int>> productsCart;
    double totalPrice;
    const int maxItems = 10;
    int totalQuantity;

public:
    Cart();
    void addToCart(T* product, int quantity);
    double getTotPrice();
    void displayCart();
    void addProductToCart(int index, int quantity);
    bool ifEmpty() const;
    void clearCart();
};
#endif;