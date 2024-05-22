#pragma once

#include "Product.h"
#include <string>

class Sportswear : public Product {
private:
    std::string sportType;

public:
    Sportswear(std::string _name, double _price, int _size, std::string _sportType);
    

    std::string getSportType() const;

    void setSportType(std::string _sportType);

    void displayProperties() const override;

    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
    std::string getType() const override;
    static Sportswear* createFromFile(std::ifstream& file);
};

