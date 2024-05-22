#pragma once

#include "Product.h"
#include <string>

class Outerwear : public Product {
private:
    std::string season;
    bool hasHood;

public:
    Outerwear(std::string _name, double _price, int _size, std::string _season, bool _hasHood);
    

    std::string getSeason() const;
    bool hasHooded() const;

    void setSeason(std::string _season);
    void setHasHood(bool _hasHood);

    void displayProperties() const override;

    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
    std::string getType() const override;
    static Outerwear* createFromFile(std::ifstream& file);
};

