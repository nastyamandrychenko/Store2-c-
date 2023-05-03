#include "Phone.h"
#include <iostream>
#include <string>

Phone::Phone(string name, double price, string description, string model, int cameraQuality) : Product(name, price, description, model) {
    this->cameraQuality = cameraQuality;
}
Phone::Phone() {};
int Phone::getcameraQuality(){ return cameraQuality; };

void Phone::writeToStream(ostream& out) const {
    out << name << " " << price << " " << description << " " << model << " " << cameraQuality << endl;
};
void Phone::setcameraQuality(int cameraQ) {
    cameraQuality = cameraQ;
};