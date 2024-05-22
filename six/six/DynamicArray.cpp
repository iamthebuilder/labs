#include "DynamicArray.h"
#include "Outerwear.h"
#include "Sportswear.h"
#include "Underwear.h"
#include "Footwear.h"
#include <iostream>
#include <fstream>

DynamicArray::~DynamicArray() {
    for (Product* product : products) {
        delete product;
    }
}

void DynamicArray::addObject(Product* product) {
    products.push_back(product);
}

void DynamicArray::removeObject(int index) {
    if (index >= 0 && index < products.size()) {
        delete products[index];
        products.erase(products.begin() + index);
    }
}

void DynamicArray::displayArray() const {
    for (const Product* product : products) {
        product->displayProperties();
        std::cout << std::endl;
    }
}

void DynamicArray::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (out.is_open()) {
        out << products.size() << std::endl;
        for (const Product* product : products) {
            product->save(out);
        }
        out.close();
    }
}

void DynamicArray::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "не открылся" << std::endl;
        return;
    }

    int size;
    file >> size;

    for (int i = 0; i < size; ++i) {
        std::string type;
        file >> type;

        if (type == "Outerwear") {
            products.push_back(Outerwear::createFromFile(file));
        }
        else if (type == "Sportswear") {
            products.push_back(Sportswear::createFromFile(file));
        }
        else if (type == "Underwear") {
            products.push_back(Underwear::createFromFile(file));
        }
        else if (type == "Footwear") {
            products.push_back(Footwear::createFromFile(file));
        }
    }
}


