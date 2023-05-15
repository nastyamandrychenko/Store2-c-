#include "Phone.h"
#include <iostream>
#include <string>

Phone::Phone(string name, string price, string description, string model, string cameraQuality) : Product(name, price, description, model) {
    this->cameraQuality = cameraQuality;
}
Phone::Phone() {};
string Phone::getcameraQuality(){ return cameraQuality; };

void Phone::writeToStream(ostream& out) const {
    out << name << "," << price << "," << description << "," << model << "," << cameraQuality << endl;
};
void Phone::setcameraQuality(string cameraQ) {
    cameraQuality = cameraQ;
};
string Phone::getAdditionalAttribute() const {
    return cameraQuality;
}

void Phone::setAdditionalAttribute(const string& attributeValue) {
    cameraQuality = attributeValue;
}