#include "Sportswear.h"
#include <iostream>

Sportswear::Sportswear(std::string _name, double _price, int _size, std::string _sportType)
    : Product(_name, _price, _size), sportType(_sportType) {}

std::string Sportswear::getSportType() const { return sportType; }

void Sportswear::setSportType(std::string _sportType) { sportType = _sportType; }

void Sportswear::displayProperties() const {
    Product::displayProperties();
    std::cout << "вид спорта: " << sportType << std::endl;
}

void Sportswear::save(std::ofstream& out) const {
    out << getType() << " " << name << " " << price << " " << size << " " << sportType << std::endl;
}

void Sportswear::load(std::ifstream& in) {
    in >> name >> price >> size >> sportType;
}

std::string Sportswear::getType() const {
    return "Sportswear";
}

Sportswear* Sportswear::createFromFile(std::ifstream& file) {
    std::string name;
    int size;
    double price;
    std::string sportType;
    file >> name >> size >> price >> sportType;
    return new Sportswear(name, size, price, sportType);
}

