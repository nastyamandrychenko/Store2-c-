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
    while (str.find_first_not_of("0123456789") != string::npos) {
        cout << "Not integer!";
        cin >> str;
    };
   
};

vector<Television*> readTelevisionData() {
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

    return productsTel;
};

void deleteProductFromFile(const string& filename, int lineToDelete) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    vector<string> lines; // is used to store the lines of the file that are not to be deleted
    string line;
    int lineNumber = 1;
    while (getline(file, line)) {
        if (lineNumber != lineToDelete) {
            lines.push_back(line);
        };
        lineNumber++;
    };
    file.close();

    // Clear the file
    ofstream clearFile(filename, ofstream::out | ofstream::trunc);
    if (!clearFile) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    };
    clearFile.close();
    // Write the modified content back to the file
    ofstream backToFile(filename, ios_base::app);
    if (!backToFile) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    for (const string& modifiedLine : lines) {
        backToFile << modifiedLine << std::endl;
    }
    backToFile.close();
};



//std::vector<Television*> readTelevisionData(const std::string& filename) {
//    std::ifstream televisionRead(filename);
//    if (!televisionRead.is_open()) {
//        std::cout << "Error opening file!" << std::endl;
//        return {};
//    }
//
//    std::vector<Television*> productsTel;
//
//    std::string name;
//    std::string price;
//    std::string description;
//    std::string model;
//    std::string screenSize;
//
//    while (televisionRead >> name >> price >> description >> model >> screenSize) {
//        bool exists = false;
//        for ( Television* tv : productsTel) {
//            if (tv->getName() == name && tv->getPrice() == price && tv->getDescription() == description &&
//                tv->getModel() == model && tv->getScreenSize() == screenSize) {
//                exists = true;
//                break;
//            }
//        }
//
//        if (!exists) {
//            Television* tv = new Television(name, price, description, model, screenSize);
//            productsTel.push_back(tv);
//        }
//    }
//
//    televisionRead.close();
//
//    return productsTel;
//}

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
            
          
        }
        PhonesFile.close();
   }

    ofstream TelevisionFile("television.txt", ios_base::app);
    for (int i = 0; i < 1; i++) {
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

    }
    TelevisionFile.close();

    deleteProductFromFile("television.txt", 1);

    vector<Television*> television = readTelevisionData();

    for (const auto& product : television) {
        cout << "Name: " << product->getName() << endl;
        cout << "Price: " << product->getPrice() << endl;
        cout << "Description: " << product->getDescription() << endl;
        cout << "Model: " << product->getModel() << endl;
        cout << "Screen Size: " << product->getScreenSize() << endl;
    }

    for (Television* tv : television) {
        delete tv;
    }
   /* store.printProducts();*/
}

