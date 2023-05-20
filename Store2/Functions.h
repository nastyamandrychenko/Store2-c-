#ifndef FUNCTIONS_H    
#define FUNCTIONS_H
#include "Product.h"
#include "Television.h"
#include "Phone.h"
#include "Func.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include  <sstream>
#include "Cart.h"
#include "Wallet.h"
using namespace std;

void addToCart(Cart<Product>& cart);
void deleteFromCart(Cart<Product>& cart);
void checkWallet(Cart<Product>& cart);
#endif