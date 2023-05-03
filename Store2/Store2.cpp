#include "Authorization.h"
#include "Product.h"
#include "Television.h"
#include "Phone.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class StoreProducts {
    Product** products;
    int numberOfProd;
    int maxNumOfProd;
public:
    StoreProducts() {
        products = NULL;
        numberOfProd = 0;
        maxNumOfProd = 0;
    };
    ~StoreProducts() {
        for (int i = 0; i < numberOfProd; i++) {
            delete products[i];
        }
        delete[] products;
    };

  

    void addItem(const Product& product) {
        if(numberOfProd == maxNumOfProd){
            int newMax = 0;
            if (maxNumOfProd == 0) {
                newMax += 1;
            }
            else {
                newMax = maxNumOfProd * 2;
            }
            Product** newProducts = new Product * [newMax];
            for (int i = 0; i < numberOfProd; i++) {
                newProducts[i] = products[i];
            }
            delete[] products;
            products = newProducts;
            maxNumOfProd = newMax;
        }
        products[numberOfProd] = new Product(product);
        numberOfProd++;
        
    };

    void printProducts() const {
        for (int i = 0; i < numberOfProd; i++) {
            cout << products[i]-> getName() << " - $" << products[i]->getPrice() << " - Quantity: " << products[i]->getDescription() << "\n";
        }
    }
    int getNumberOfProducts() const{
        return numberOfProd;
    }

    Product* getProduct(int index) const {
        if (index < 0 || index >= numberOfProd) {
            return NULL;
        }
        return products[index];
    }

    
};

int main()
{
    string password, userName;
    cout << "User name:" << endl;
    cin >> userName;
    cout << "Password:" << endl;
    cin >> password;
    Authorization logIn(password, userName);

    /* if (logIn.checkLogIn(userName, password) == true) {
         cout << "Login was successful!";
     } else{
         cout << "Wrong password or username! Try again!";
     }*/

    Product first("TV", 12.50, "Good", "Samsung");
    first.setPrice(15);
    cout << "name: " << first.getName() << endl << "price: " << first.getPrice() << endl << "Description: " << first.getDescription() << endl << "Model: " << first.getModel() << endl;
    Television TV("js", 17, "Amazing", "Samsung", "16x13");
    first.setPrice(20);
    cout << "name: " << TV.getScreenSize() << endl;
    first.getModel();
    first.getDescription();
    first.getName();
    first.getPrice();
    //cout << "User name: " << logIn.getUserName() << endl << "Password: " << logIn.getPassword() << endl;

    StoreProducts store;
    cout << "How many products do you want to add? ";
    int numProducts;
    cin >> numProducts;
    ofstream outFile("products.txt", ios_base::app);

    int whatType;
    cout << "What type of product do you want to add?" << endl <<"1.Television"<< endl << "2.Phone"<<endl;
    cin >> whatType;

    if (whatType == 1) {
        for (int i = 0; i < numProducts; i++) {
            string name;
            double price;
            string description;
            string model;
            string screenSize;
            cout << "Enter the name of " << i + 1 << " product " << ": ";
            cin >> name;

            cout << "Enter the price of " << i + 1 << " product " << ": ";
            cin >> price;

            cout << "Enter the description of " << i + 1 << " product " << ": ";
            cin >> description;
            cout << "Enter the model of " << i + 1 << " product " << ": ";
            cin >> model;
            cout << "Enter the screen size of " << i + 1 << " product " << ": ";
            cin >> screenSize;
            Television t(name, price, description, model, screenSize);
            t.writeToStream(outFile);
            store.addItem(t);
        }
    }
    else if (whatType == 2) {
        for (int i = 0; i < numProducts; i++) {
            string name;
            double price;
            string description;
            string model;
            int cameraQuality;
            cout << "Enter the name of " << i + 1 << " product " << ": ";
            cin >> name;

            cout << "Enter the price of " << i + 1 << " product " << ": ";
            cin >> price;

            cout << "Enter the description of " << i + 1 << " product " << ": ";
            cin >> description;
            cout << "Enter the model of " << i + 1 << " product " << ": ";
            cin >> model;
            cout << "Enter the camera quality of " << i + 1 << " product " << ": ";
            cin >> cameraQuality;
            Phone p(name, price, description, model, cameraQuality);
            p.writeToStream(outFile);
            store.addItem(p);
        }
   }
    outFile.close();
 

    /*store.printProducts();*/
}

