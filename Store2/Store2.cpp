#include "Authorization.h"
#include "Product.h"
#include "Television.h"
#include "Phone.h"
#include <iostream>
//#include  <bits/stdc++.h>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//class StoreProducts {
//    Product** products;
//    int numberOfProd;
//    int maxNumOfProd;
//public:
//    StoreProducts() {
//        products = NULL;
//        numberOfProd = 0;
//        maxNumOfProd = 0;
//    };
//    ~StoreProducts() {
//        for (int i = 0; i < numberOfProd; i++) {
//            delete products[i];
//        }
//        delete[] products;
//    };
//
//  
//
//    void addItem(const Product& product) {
//        if(numberOfProd == maxNumOfProd){
//            int newMax = 0;
//            if (maxNumOfProd == 0) {
//                newMax += 1;
//            }
//            else {
//                newMax = maxNumOfProd * 2;
//            }
//            Product** newProducts = new Product * [newMax];
//            for (int i = 0; i < numberOfProd; i++) {
//                newProducts[i] = products[i];
//            }
//            delete[] products;
//            products = newProducts;
//            maxNumOfProd = newMax;
//        }
//        products[numberOfProd] = new Product(product);
//        numberOfProd++;
//        
//    };
//    
//
//    void printProducts() const {
//        for (int i = 0; i < numberOfProd; i++) {
//            cout << products[i]-> getName() << " - $" << products[i]->getPrice() << " - Quantity: " << products[i]->getDescription() << "\n";
//        }
//    }
//    int getNumberOfProducts() const{
//        return numberOfProd;
//    }
//
//    Product* getProduct(int index) const {
//        if (index < 0 || index >= numberOfProd) {
//            return NULL;
//        }
//        return products[index];
//    }
//
//    
//};

void check(string &str) {
   /* if (str.find_first_not_of("0123456789") == string::npos) {
        cout << "The value " << str << " is Integer" << endl;
    }
    else {
        cout << "The value " << str << " is Not Integer" << endl;
    }*/

    while (str.find_first_not_of("0123456789") != string::npos) {
        cout << "Not integer!";
        cin >> str;
    };
   
};

vector<Product*> products;

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

    /*Product first("TV", "12.50", "Good", "Samsung");
    first.setPrice("15");
    cout << "name: " << first.getName() << endl << "price: " << first.getPrice() << endl << "Description: " << first.getDescription() << endl << "Model: " << first.getModel() << endl;
    Television TV("js", "17", "Amazing", "Samsung", "16x13");
    first.setPrice("20");
    cout << "name: " << TV.getScreenSize() << endl;
    first.getModel();
    first.getDescription();
    first.getName();
    first.getPrice();*/
    //cout << "User name: " << logIn.getUserName() << endl << "Password: " << logIn.getPassword() << endl;

   /* StoreProducts store;*/
    cout << "How many products do you want to add? ";
    int numProducts;
    cin >> numProducts;
  
    Television t;
    Phone p;
    int whatType;
    cout << "What type of product do you want to add?" << endl <<"1.Television"<< endl << "2.Phone"<<endl;
    cin >> whatType;
   
   
    
    if (whatType == 1) {
       
        ofstream TelevisionFile("television.txt", ios_base::app);
        for (int i = 0; i < numProducts; i++) {
            string name;
            string price;
            string description;
            string model;
            string screenSize;

            cout << "Enter the name of " << i + 1 << " product " << ": ";
            cin.ignore();
            cin >> name;

            cout << "Enter the price of " << i + 1 << " product " << ": ";
            cin.ignore();
            cin >> price;
            cout << "Enter the description of " << i + 1 << " product " << ": ";
            cin.ignore();
            cin >> description;
            cout << "Enter the model of " << i + 1 << " product " << ": ";
            cin.ignore();
            cin >> model;
            cout << "Enter the screen size of " << i + 1 << " product " << ": ";
            cin.ignore();
            cin >> screenSize;
           
            t.setDescription(description);
            t.setModel(model);
            t.setName(name);
            t.setPrice(price);
            t.setScreenSize(screenSize);
            t.writeToStream(TelevisionFile);
            /*store.addItem(t);*/
            
        }
        TelevisionFile.close();
    }
    else if (whatType == 2) {
        
        ofstream PhonesFile("phones.txt", ios_base::app);
        for (int i = 0; i < numProducts; i++) {
            string name;
            string price;
            string description;
            string model;
            string cameraQ;

            cout << "Enter the name of " << i + 1 << " product " << ": ";
            cin.ignore();
            cin >> name;

            cout << "Enter the price of " << i + 1 << " product " << ": ";
            cin.ignore();
            cin >> price;
            cout << "Enter the description of " << i + 1 << " product " << ": ";
            cin.ignore();
            cin >> description;
            cout << "Enter the model of " << i + 1 << " product " << ": ";
            cin.ignore();
            cin >> model;
            cout << "Enter the camera quality of " << i + 1 << " product " << ": ";
            cin.ignore();
            cin >> cameraQ;
            check(cameraQ);
            
            

            p.setDescription(description);
            p.setModel(model);
            p.setName(name);
            p.setPrice(price);
            p.setcameraQuality(cameraQ);
            p.writeToStream(PhonesFile);
          /*  store.addItem(p);*/
            
          
        }
        PhonesFile.close();
   }


    ifstream televisionRead("television.txt");
    if (!televisionRead.is_open()) {
        cout << "Error opening file!" << endl;
    }
    int numObjects = 0;
    string line;
    while (getline(televisionRead, line)) {
        ++numObjects;
    };
    televisionRead.clear();
    televisionRead.seekg(0, ios::beg);
    vector<Television*> productsTel(numObjects);
    for (int i = 0; i < numObjects; ++i) {
        string name;
        string price;
        string description;
        string model;
        string screenSize;
        getline(televisionRead, name, ' ');
        getline(televisionRead, price, ' ');
        getline(televisionRead, description, ' ');
        getline(televisionRead, model, ' ');
        getline(televisionRead, screenSize);

        productsTel[i] = new Television(name, price, description, model, screenSize);
    }

    televisionRead.close();

    /*for (int i = 0; i < numObjects; i++) {
        cout << productsTel[i]->getName() << productsTel[i]->getPrice() << productsTel[i]->getDescription() << "\n";
    };*/

    for (const auto& product : productsTel) {
        cout << "Name: " << product->getName() << endl;
        cout << "Price: " << product->getPrice() << endl;
        cout << "Description: " << product->getDescription() << endl;
        cout << "Model: " << product->getModel() << endl;
        cout << "Screen Size: " << product->getScreenSize() << endl;
    }

    for (int i = 0; i < numObjects; ++i) {
        delete productsTel[i];
    }
   /* store.printProducts();*/
}

