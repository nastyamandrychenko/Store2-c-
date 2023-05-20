#include "Functions.h"
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


void takeAnOrder(Cart<Product>& cart, Wallet& wallet) {
    cout << "--------------------Welcome to the ordering system!--------------------" << endl;
    if (cart.ifEmpty()) {
        cout << "Your basket is empty. Add products to make a purchase" << endl;
    }
    else {
        cart.displayCart();
        string yesNo;
        cout << "Are you sure you want to order these products? y/n" << endl;
        cin.ignore();
        getline(cin, yesNo);
        if (yesNo == "y")
        {
            if (wallet.getWalletBalance() < cart.getTotPrice()) {
                cout << " Order cancelled. Not enough money in the account!" << endl;
            }
            else {
                cout << "Order processed successfully. Thank you for your purchase!" << endl;
                double totPrice = cart.getTotPrice();
                wallet.removeFromWalletBalance(totPrice);
                cart.clearCart();
                
            };

        }
        else if (yesNo == "n") {
        }
        else {
            cout << "Invalid choice. " << endl;
        }
    }
}

void checkWallet(Cart<Product>& cart, Wallet& wallet) {
    cout << "1. My balance" << endl;
    cout << "2. Get some money" << endl;
    int walletChoice = getValidNumberInput("Enter the index: ");
    cout << endl;
    if (walletChoice == 1) {
        cout << wallet.getWalletBalance() << "$ in your account" << endl;
        cout << endl;
    }
    else if (walletChoice == 2) {
        cout << "Answer the question to get $50" << endl;
        cout << endl;
        bool answer = solveArithmeticProblems();
        if (answer == true) {
            wallet.addToWalletBalance(50);
            cout << "Good job! You got $50! Check your balance." << endl;
            cout << endl;
        }
        else {
            cout << "Incorrect answer! You don't get 50!" << endl;
            cout << endl;
        }

    }
}

void deleteFromCart(Cart<Product>& cart) {
    if (cart.ifEmpty()) {
        cout << endl;
        cout << "There are no products to delete." << endl;
        cout << endl;
    }
    else {
        int deleteChoice;
        cout << endl;
        cout << "1. Delete 1 product" << endl;
        cout << "2. Clear Cart" << endl;
        deleteChoice = getValidNumberInput("Enter the index: ");
        cout << endl;
        if (deleteChoice == 1) {
            cart.displayCart();
            int deleteCartProduct = getValidNumberInput("Enter the index of the product you want to remove from the cart: ");
            deleteCartProduct--;
            cart.deleteFromCart(deleteChoice, 1);
        }
        else if (deleteChoice == 2)
        {
            cart.clearCart();
            cout << "Cart cleared successfully" << endl;
        }
        else {
            cout << "Invalid choice. " << endl;
        }
        cout << endl;
    }
}

void addToCart(Cart<Product>& cart) {
    int productChoice;
    cout << "Choose the product group to add from:" << endl;
    cout << "1. Televisions" << endl;
    cout << "2. Phones" << endl;
    cout << "Enter your choice: ";
    int productGroup;
    cin >> productGroup;
    cout << endl;
    if (productGroup == 1) {
        vector<Television*> televisions = readData<Television>("television.txt");
        displayProducts(televisions);
        cout << endl;
        productChoice = getValidNumberInput("Enter the index of the product to add to cart: ");
        if (productChoice >= 0 && productChoice <= televisions.size()) {
            productChoice--;
            Television* selectedTV = televisions[productChoice];
            int quantity = getValidNumberInput("Enter the quantity to add: ");
            cart.addToCart(selectedTV, quantity);
        }
        else {
            cout << endl;
            cout << "Invalid. Product doesn't exist" << endl;
        }
        cout << endl;
        
    }
    else if (productGroup == 2) {
        vector<Phone*> phones = readData<Phone>("phones.txt");
        cout << endl;
        displayProducts(phones);
        cout << endl;
        productChoice = getValidNumberInput("Enter the index of the product to add to cart: ");
        if (productChoice >= 0 && productChoice <= phones.size()) {
            productChoice--;
            Phone* selectedPhone = phones[productChoice];
            cout << endl;
            int quantity = getValidNumberInput("Enter the quantity to add: ");
            cart.addToCart(selectedPhone, quantity);

        }
        else {
            cout << "Invalid. Product doesn't exist" << endl;
        }
        cout << endl;
    }
    else {
        cout << "Invalid choice." << endl;
    }
}