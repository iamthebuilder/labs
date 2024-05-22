#pragma once

#include "Product.h"
#include <string>

class Underwear : public Product {
private:
    std::string material;

public:
    Underwear(std::string _name, double _price, int _size, std::string _material);

    std::string getMaterial() const;

    void setMaterial(std::string _material);

    void displayProperties() const override;

    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
    std::string getType() const override;
    static Underwear* createFromFile(std::ifstream& file);
};

