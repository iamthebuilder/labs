#include "Underwear.h"
#include <iostream>

Underwear::Underwear(std::string _name, double _price, int _size, std::string _material)
    : Product(_name, _price, _size), material(_material) {}

std::string Underwear::getMaterial() const { return material; }

void Underwear::setMaterial(std::string _material) { material = _material; }

void Underwear::displayProperties() const {
    Product::displayProperties();
    std::cout << "материал: " << material << std::endl;
}

void Underwear::save(std::ofstream& out) const {
    out << getType() << " " << name << " " << price << " " << size << " " << material << std::endl;
}

void Underwear::load(std::ifstream& in) {
    in >> name >> price >> size >> material;
}

std::string Underwear::getType() const {
    return "Underwear";
}
Underwear* Underwear::createFromFile(std::ifstream& file) {
    std::string name;
    int size;
    double price;
    std::string material;
    file >> name >> size >> price >> material;
    return new Underwear(name, size, price, material);
}
