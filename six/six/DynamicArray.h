#pragma once

#include "Product.h"
#include <vector>
#include <string>

class DynamicArray {
private:
    std::vector<Product*> products;

public:
    ~DynamicArray();

    void addObject(Product* product);
    void removeObject(int index);
    void displayArray() const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

