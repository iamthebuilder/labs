#pragma once

#include "Product.h"
#include <string>

class Footwear : public Product {
private:
    std::string purpose;
    bool hasHeels;

public:
    Footwear(std::string _name, double _price, int _size, std::string _purpose, bool _hasHeels);
    

    std::string getPurpose() const;
    bool hasHeeels() const;

    void setPurpose(std::string _purpose);
    void setHasHeels(bool _hasHeels);

    void displayProperties() const override;

    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
    std::string getType() const override;
    static Footwear* createFromFile(std::ifstream& file);
};

