#include "Cart.h"
#include "Product.h"
#include "Func.h"
#include <iostream>
#include <string> 
#include <vector> 

template <typename T>
Cart<T>::Cart() : totalPrice(0.0), totalQuantity(0) {}

template <typename T>
 void Cart<T>::addToCart(T* product, int quantity) {
        if (productsCart.size() >= maxItems || totalQuantity >= maxItems) {
            cout << "Maximum item limit reached. Cannot add more items to the cart." << endl;
            return;

        }
        else if (quantity > maxItems) {
            cout << "You cannot add more than 10 items to your shopping cart." << endl;
            return;

        }
        else {
            for (auto& item : productsCart) {
                if (item.first->getName() == product->getName() &&
                    item.first->getPrice() == product->getPrice() &&
                    item.first->getDescription() == product->getDescription() &&
                    item.first->getModel() == product->getModel() &&
                    item.first->getAdditionalAttribute() == product->getAdditionalAttribute()) {
                    item.second += quantity;
                    totalPrice += stod(product->getPrice()) * quantity;
                    return;
                }

            }
            productsCart.push_back(make_pair(product, quantity));
            totalPrice += stod(product->getPrice()) * quantity;
            totalQuantity += quantity;
        }
    };

 template <typename T>
    double Cart<T>::getTotPrice() {
        return totalPrice;
    };

template <typename T>
  void Cart<T>::displayCart() {
        if (productsCart.empty()) {
            cout << "Cart is empty." << endl;
        }
        else {
            vector<T*> products;

            for (const auto& item : productsCart) {
                products.push_back(item.first);
            }
            displayProducts(products);
            cout << "Quantity in Cart:" << endl;
            for (const auto& item : productsCart) {
                int quantity = item.second;
                cout << "Product: " << item.first->getName() << ", Quantity: " << quantity << endl;
            }
        }
    };


    template <typename T>
    void Cart<T>::addProductToCart(int index, int quantity) {
        if (index < 0 || index > productsCart.size()) {
            cout << "Invalid index. Please enter a valid index from the cart." << endl;
            return;
        }

        auto& item = productsCart[index];
        if (quantity >= item.second) {
            // Remove the item from the cart
            totalQuantity -= item.second;
            totalPrice -= stod(item.first->getPrice()) * item.second;
            productsCart.erase(productsCart.begin() + index);
        }
        else {
            // Decrease the quantity of the item
            item.second -= quantity;
            totalQuantity -= quantity;
            totalPrice -= stod(item.first->getPrice()) * quantity;
        }
    };

    template <typename T>
    bool Cart<T>::ifEmpty() const {
        return productsCart.empty();
    };


    template <typename T>
    void Cart<T>::clearCart() {
        productsCart.clear();
        totalPrice = 0.0;
        totalQuantity = 0;
    }

    template class Cart<Product>;

