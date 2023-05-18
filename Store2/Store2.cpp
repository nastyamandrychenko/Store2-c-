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


int main()
{

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

    cout << "**********************************************" << endl;
    cout << "*                  WELCOME                   *" << endl;
    cout << "*           TO ELECTRONIC STORE!             *" << endl;
    cout << "*                                            *" << endl;
    cout << "**********************************************" << endl;
    cout << endl;

    int choice;
    while (true) {
        cout << "Menu Options:" << endl;
        cout << "1. Display All Products" << endl;
        cout << "2. Modify Product" << endl;
        cout << "3. Delete Product" << endl;
        cout << "4. Add Product" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter an integer." << endl;
            // Clear the input stream
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (choice) {
        case 1: {
            displayProducts();
            break;
        }
        case 2: {
            modifyProduct();
            break;
        }
        case 3: {
            deleteProduct();

            break;
        }case 4: {
            addProduct();

            break;
        }
        }

    }
}
