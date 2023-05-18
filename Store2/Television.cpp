#include "Television.h"
#include <iostream>
#include <string>
Television ::Television(string name, string price, string description, string model, string screenSize) : Product(name, price, description, model) {
    this->screenSize = screenSize;
}
Television::Television() {};
string Television::getScreenSize() { return screenSize; };

void Television::writeToStream(ostream& out) const {

    out << name << "," << price << "," << description << "," << model << "," << screenSize << endl;
};
void Television::setScreenSize(string screenS) { screenSize = screenS; };

string Television::getAdditionalAttribute() const {
    return screenSize;
};
void Television::setAdditionalAttribute(const string& attributeValue) {
    screenSize = attributeValue;
};
string Television::getNameOfAttr() const  {
    return "Screen Size: ";
}