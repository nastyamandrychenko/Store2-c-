#ifndef TELEVISION_H
#define TELEVISION_H
#include "Product.h"

#include <string>
#include <stdio.h>
using namespace std;

class Television : public Product {
private:
    string screenSize;
public:
    Television(string name, string price, string description, string model, string screenSize);
    Television();
    void writeToStream(ostream& out) const override;
    string getScreenSize();
    void setScreenSize(string screenS);
    string getAdditionalAttribute() const override;
    void setAdditionalAttribute(const string& attributeValue) override;

   
};
#endif