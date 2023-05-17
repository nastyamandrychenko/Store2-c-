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


void check(string& str);

template<typename T>
vector<T*> readData(const string& filename) {
    ifstream fileRead(filename);
    if (!fileRead.is_open()) {
        cout << "Error opening file!" << endl;
    }
    int numObjects = 0;
    string line;
    while (getline(fileRead, line)) {
        ++numObjects;
    }
    fileRead.clear();
    fileRead.seekg(0, ios::beg);
    vector<T*> productsTel(numObjects);
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

        productsTel[i] = new T(name, price, description, model, additionalAttribute);
    }

    fileRead.close();

    return productsTel;
};

template<typename T>
void modifyAttribute(vector<T*>& products, int index, int attributeIndex, const string& newValue) {
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
            cout << "Invalid attribute index!" << endl;
            break;
        }
    }
    else {
        cout << "Invalid index!" << endl;
    }
}

void deleteProductFromFile(const string& filename, int lineToDelete);

template<typename T>
void writeData(const vector<T*>& products, const string& filename) {
    // Clear the file
    ofstream clearFile(filename, ofstream::out | ofstream::trunc);
    if (!clearFile) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    };
    clearFile.close();

    ofstream fileWrite(filename);
    if (!fileWrite.is_open()) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    for (const T* product : products) {
        product->writeToStream(fileWrite);
    }
    fileWrite.close();
}
#endif