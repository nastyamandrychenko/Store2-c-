#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <stdio.h>
using namespace std;

class Product {
protected:
    string name;
    double price;
    string description;
    string model;
public:
    Product();
    Product(string name, double price, string description, string model);
    virtual void writeToStream(ostream& out) const;
    string getName();
    string getDescription();
    string getModel();
    double getPrice();
    void setPrice(double price);
    void setName(string name);
    void setDescription(string description);
    void setModel(string model);
};

#endif
