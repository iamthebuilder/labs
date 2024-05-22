#pragma once

#include <string>
#include <fstream>

class Product {
protected:
    std::string name;
    double price;
    int size;

public:
    Product(std::string _name, double _price, int _size);

    std::string getName() const;
    double getPrice() const;
    int getSize() const;

    void setName(std::string _name);
    void setPrice(double _price);
    void setSize(int _size);

    virtual void displayProperties() const;

    virtual void save(std::ofstream& out) const = 0;
    virtual void load(std::ifstream& in) = 0;
    virtual std::string getType() const = 0;
};

