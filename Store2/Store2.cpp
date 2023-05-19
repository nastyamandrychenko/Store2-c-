#include "Authorization.h"
#include "Product.h"
#include "Television.h"
#include "Phone.h"
#include "Func.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include  <sstream>
using namespace std;

template <typename T>
class Cart {
    vector<pair<T*, int>> productsCart; // Each pair consists of two elements: a pointer to a T object (T*) and an integer (int)
    double totalPrice;
    const int maxItems = 10;
    int totalQuantity;
public:
    Cart() : totalPrice(0.0) {};
    void addToCart(T* product, int quantity) {
        if (productsCart.size() >= maxItems || totalQuantity>= maxItems) {
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
    double getTotPrice() {
        return totalPrice;
    };

    void displayCart() {
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
    vector<pair<T*, int>> getProductsCart() const {
        return productsCart;
    };
   
    
    void decreaseQuantity(int index, int quantity) {
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


    bool ifEmpty() const {
        return productsCart.empty();
    };
 
};

int main()
{

    cout << "**********************************************" << endl;
    cout << "*                  WELCOME                   *" << endl;
    cout << "*           TO ELECTRONIC STORE!             *" << endl;
    cout << "*                                            *" << endl;
    cout << "**********************************************" << endl;
    cout << endl;

    //string password, userName;
    //cout << "User name:" << endl;
    //cin >> userName;
    //cout << "Password:" << endl;
    //cin >> password;
    //Authorization logIn(password, userName);

    //if (logIn.checkLogIn(userName, password) == true) {
    //    cout << "Login was successful!";
    //}
    //else {
    //    cout << "Wrong password or username! Try again!";
    //    return 0; // Exit the program if login fails
    //}

    Cart<Product> cart;

    int whichPart, choice;
    while (true) {

        cout << "Menu Options:" << endl;
        cout << "1. Administrator" << endl;
        cout << "2. Customer" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        whichPart = getValidNumberInput("Enter your choice: ");

        switch (whichPart) {
        case 1: {
            while (true) {
                // Administrator
                cout << "Menu Options:" << endl;
                cout << "1. Display All Products" << endl;
                cout << "2. Modify Product" << endl;
                cout << "3. Delete Product" << endl;
                cout << "4. Add Product" << endl;
                cout << "5. Exit" << endl;

                choice = getValidNumberInput("Enter your choice: ");
                switch (choice) {
                case 1: {
                    displayProducts();
                    cout << endl;
                    break;
                }
                case 2: {
                    modifyProduct();
                    cout << endl;
                    break;
                }
                case 3: {
                    deleteProduct();
                    cout << endl;
                    break;
                }case 4: {
                    addProduct();
                    cout << endl;
                    break;
                }
                case 5: {
                    std::cout << "Returning to the main menu..." << std::endl;
                    cout << endl;
                    break;
                }
                default: {
                    std::cout << "Invalid choice. Please select a valid option." << std::endl;
                    cout << endl;
                    break;
                }
                }
                if (choice == 5) {
                    break;
                }
            }
            break;
        }case 2: {

            int productChoice;
            // Customer
            while (true) {
                cout << "Customer Menu Options:" << endl;
                cout << "1. Display Products" << endl;
                cout << "2. Add Product to Cart" << endl;
                cout << "3. Display Cart" << endl;
                cout << "4. Delete Products from Cart" << endl;
                cout << "5. Back to Main Menu" << endl;
                choice = getValidNumberInput("Enter your choice: ");
                cout << endl;
                switch (choice) {
                case 1: {
                    displayProducts();
                    cout << endl;
                    break;
                }case 2: {
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
                            break;
                        }
                        cout << endl;
                        /*cout << cart.getTotPrice() << endl;
                        cart.displayCart();*/
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
                            break;
                        }
                        cout << endl;
                    }
                    else {
                        cout << "Invalid choice. Please select a valid option." << endl;
                    }


                    break;
                }case 3: {
                    cout << endl; 
                    cart.displayCart();
                    cout << "Total price: " << cart.getTotPrice() << endl;
                   
                    cout << endl;
                    break;

                }case 4: {
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
                            deleteChoice--;
                            cart.decreaseQuantity(deleteChoice, 1);
                        }
                        cout << endl;
                    }
                }case 5: {
                    break;
                }
                       
                }
                if (choice == 5) {
                    cout << endl;
                    std::cout << "Returning to the main menu..." << std::endl;
                    break;  // Break out of the inner while loop
                }
            }

        }case 3: {
                std::cout << "Exiting the program..." << std::endl;
                break;  // Break out of the inner while loop
            }
        default: {
            cout << "Invalid choice. Please select a valid option." << endl;
            break;
        };
        }if (whichPart == 3) {
            return 0;  // Break out of the outer while loop to exit the program
        }
        }

    }
