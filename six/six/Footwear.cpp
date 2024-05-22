#include "Footwear.h"
#include <iostream>

Footwear::Footwear(std::string _name, double _price, int _size, std::string _purpose, bool _hasHeels)
    : Product(_name, _price, _size), purpose(_purpose), hasHeels(_hasHeels) {}

std::string Footwear::getPurpose() const { return purpose; }
bool Footwear::hasHeeels() const { return hasHeels; }

void Footwear::setPurpose(std::string _purpose) { purpose = _purpose; }
void Footwear::setHasHeels(bool _hasHeels) { hasHeels = _hasHeels; }

void Footwear::displayProperties() const {
    Product::displayProperties();
    std::cout << "назначение: " << purpose << std::endl;
    std::cout << "наличие каблука: " << (hasHeels ? "да" : "нет") << std::endl;
}

void Footwear::save(std::ofstream& out) const {
    out << getType() << " " << name << " " << price << " " << size << " " << purpose << " " << hasHeels << std::endl;
}

void Footwear::load(std::ifstream& in) {
    in >> name >> price >> size >> purpose >> hasHeels;
}

std::string Footwear::getType() const {
    return "Footwear";
}

Footwear* Footwear::createFromFile(std::ifstream& file) {
    std::string name;
    int size;
    double price;
    std::string purpose;
    bool hasHeel;
    file >> name >> size >> price >> purpose >> hasHeel;
    return new Footwear(name, size, price, purpose, hasHeel);
}

