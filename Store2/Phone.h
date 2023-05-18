#ifndef PHONE_H
#define PHONE_H
#include "Product.h"

#include <string>
#include <stdio.h>
using namespace std;

class Phone : public Product {
private:
    string cameraQuality;
public:
    Phone(string name, string price, string description, string model, string cameraQuality);
    Phone();
    void writeToStream(ostream& out) const override;
    string getcameraQuality();
    void setcameraQuality(string cameraQ);
    string getAdditionalAttribute() const override;
    void setAdditionalAttribute(const string& attributeValue) override;
    string getNameOfAttr() const override;
};
#endif
