#ifndef PHONE_H
#define PHONE_H
#include "Product.h"

#include <string>
#include <stdio.h>
using namespace std;

class Phone : public Product {
private:
    int cameraQuality;
public:
    Phone(string name, double price, string description, string model, int cameraQuality);
    Phone();
    void writeToStream(ostream& out) const override;
    int getcameraQuality();
    void setcameraQuality(int cameraQ);
};
#endif
