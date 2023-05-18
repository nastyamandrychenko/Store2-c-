#ifndef FUNC_H    
#define FUNC_H
#include "Authorization.h"
#include "Product.h"
#include "Television.h"
#include "Phone.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include  <sstream>
using namespace std;


template<typename T>
vector<T*> readData(const string& filename) {
    vector<T*> productsTel;
    ifstream fileRead(filename);

    try {
        if (!fileRead) {
            throw runtime_error("Error opening file!");
        }

        int numObjects = 0;
        string line;
        while (getline(fileRead, line)) {
            ++numObjects;
        }

        fileRead.clear();
        //This is done to reset the stream state flags (the end of file flag).
        fileRead.seekg(0, ios::beg);
        //move the file position indicator back to the beginning of the file
        productsTel.reserve(numObjects);
        //preallocate memory for the productsTel vector

        for (int i = 0; i < numObjects; ++i) {
            string name;
            string price;
            string description;
            string model;
            string additionalAttribute;

            getline(fileRead, name, ',');
            getline(fileRead, price, ',');
            getline(fileRead, description, ',');
            getline(fileRead, model, ',');
            getline(fileRead, additionalAttribute);

            productsTel.push_back(new T(name, price, description, model, additionalAttribute));
        }
    }
    catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
        // Clean up the allocated memory
        for (T* product : productsTel) {
            delete product;
        }
        productsTel.clear();
    }

    fileRead.close();

    return productsTel;
}

template<typename T>
void modifyAttribute(vector<T*>& products, int index, int attributeIndex, const string& newValue) {
    try {
    if (index >= 0 && index < products.size()) {
        T* product = products[index];
        switch (attributeIndex) {
        case 0:
            product->setName(newValue);
            break;
        case 1:
            product->setPrice(newValue);
            break;
        case 2:
            product->setDescription(newValue);
            break;
        case 3:
            product->setModel(newValue);
            break;
        case 4:
            product->setAdditionalAttribute(newValue);
            break;
        default:
            throw runtime_error("Invalid attribute index!");
            break;
        }
    }
    else {
        throw runtime_error("Invalid index!");
    }
    }
    catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
}

void deleteProductFromFile(const string& filename, int lineToDelete);

template<typename T>
void writeData(const vector<T*>& products, const string& filename) {
    // Clear the file
    try {
    ofstream clearFile(filename, ofstream::out | ofstream::trunc);
    if (!clearFile) {
        throw runtime_error("Error opening file: " + filename);
    };
    clearFile.close();

    ofstream fileWrite(filename);
    if (!fileWrite.is_open()) {
        throw runtime_error("Error opening file for writing!");
    }
    for (const T* product : products) {
        product->writeToStream(fileWrite);
    }
    fileWrite.close();
    }
    catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
}
void displayProducts();
    
template <typename T>
void displayProducts(const vector<T*>& products) {
    for (int i = 0; i < products.size(); ++i) {
        const auto& product = products[i];
        cout << "--------------------------" << endl;
        cout << i + 1 << ". "
            << "Name: " << product->getName() << endl
            << "Price: " << product->getPrice() << endl
            << "Description: " << product->getDescription() << endl
            << "Model: " << product->getModel() << endl
        << product->getNameOfAttr() << product->getAdditionalAttribute() << endl;
        
    }
    cout << endl;
}
void modifyProduct();
int getValidNumberInput(const std::string& prompt);
void deleteProduct();
void addProduct();
bool isInteger(const string& s);
#endif