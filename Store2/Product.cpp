#include "Product.h"
#include <iostream>
#include <string>

Product::Product(string name, double price, string description, string model) {
    this->name = name;
    this->price = price;
    this->description = description;
    this->model = model;
}
Product::Product() {};

void Product::writeToStream(ostream& out) const {
    out << name << " " << price << " " << description << " " << model << endl;
};
string Product::getName() { return name; };

string Product::getDescription() { return description; };

string Product:: getModel() { return model; };

double Product:: getPrice() { return price; };

void Product::setPrice(double price) {
    this->price = price;
};

void Product::setName(string name) {
    this->name = name;
};
void Product::setDescription(string description) {
    this->description = description;
};
void Product::setModel(string model) {
    this->model = model;
};