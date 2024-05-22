#include "Product.h"
#include <iostream>
#include <stdexcept>

Product::Product(std::string _name, double _price, int _size) : name(_name) {
    if (_price < 0) {
        throw std::invalid_argument("Цена <0");
    }
    price = _price;

    if (_size <= 0) {
        throw std::invalid_argument("Размер <0");
    }
    size = _size;
}

std::string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
int Product::getSize() const { return size; }

void Product::setName(std::string _name) { name = _name; }
void Product::setPrice(double _price) {
    if (_price < 0) {
        throw std::invalid_argument("Цена <0");
    }
    price = _price;
}
void Product::setSize(int _size) {
    if (_size <= 0) {
        throw std::invalid_argument("Размер <0");
    }
    size = _size;
}

void Product::displayProperties() const {
    std::cout << "товар: " << name << std::endl;
    std::cout << "цена: " << price << std::endl;
    std::cout << "размер: " << size << std::endl;
}
