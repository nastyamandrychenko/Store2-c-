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
#include "Cart.h"
#include "Wallet.h"
#include "Functions.h"





int main()
{

    cout << "**********************************************" << endl;
    cout << "*                  WELCOME                   *" << endl;
    cout << "*           TO ELECTRONIC STORE!             *" << endl;
    cout << "*                                            *" << endl;
    cout << "**********************************************" << endl;
    cout << endl;

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
            string password, userName;
            cout << "User name:" << endl;
            cin >> userName;
            cout << "Password:" << endl;
            cin >> password;
            Authorization logIn(password, userName);

            if (logIn.checkLogIn(userName, password) == true) {
                cout << "Login was successful!";
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
            }
            else {
                cout << "Wrong password or username! Try again!";
                continue; // Go back to the menu options
            }
            break;
           
        }case 2: {

            // Customer
            while (true) {
                cout << "Customer Menu Options:" << endl;
                cout << "1. Display Products" << endl;
                cout << "2. Add Product to Cart" << endl;
                cout << "3. Display Cart" << endl;
                cout << "4. Delete Products from Cart" << endl;
                cout << "5. Wallet" << endl;
                cout << "6. To make a purchase" << endl;
                cout << "7. Back to Main Menu" << endl;
       
                choice = getValidNumberInput("Enter your choice: ");
                cout << endl;
                switch (choice) {
                case 1: {
                    displayProducts();
                    cout << endl;
                    break;
                }case 2: {
                    addToCart(cart);
                    break;
                }case 3: {
                    cout << endl; 
                    cart.displayCart();
                    cout << "Total price: " << cart.getTotPrice() << endl;
                   
                    cout << endl;
                    break;

                }case 4: {
                    deleteFromCart(cart);
                    break;
                }case 5: {
                    checkWallet(cart);
                    break;

                }
                case 6: {
                   
                    break;
                }
                case 7: {
                    break;
                }
                       
                }
                if (choice == 7) {
                    cout << endl;
                    cout << "Returning to the main menu..." << endl;
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
