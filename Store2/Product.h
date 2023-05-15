#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <stdio.h>
using namespace std;

class Product {
protected:
    string name;
    string price;
    string description;
    string model;
public:
    Product();
    Product(string name, string price, string description, string model);
    virtual void writeToStream(ostream& out) const;
    string getName();
    string getDescription();
    string getModel();
    string getPrice();
    void setPrice(string price);
    void setName(string name);
    void setDescription(string description);
    void setModel(string model);

    virtual string getAdditionalAttribute() const = 0;
    virtual void setAdditionalAttribute(const string& attributeValue) = 0;
};

#endif
