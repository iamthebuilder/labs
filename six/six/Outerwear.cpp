#include "Outerwear.h"
#include <iostream>

Outerwear::Outerwear(std::string _name, double _price, int _size, std::string _season, bool _hasHood)
    : Product(_name, _price, _size), season(_season), hasHood(_hasHood) {}

std::string Outerwear::getSeason() const { return season; }
bool Outerwear::hasHooded() const { return hasHood; }

void Outerwear::setSeason(std::string _season) { season = _season; }
void Outerwear::setHasHood(bool _hasHood) { hasHood = _hasHood; }

void Outerwear::displayProperties() const {
    Product::displayProperties();
    std::cout << "сезон: " << season << std::endl;
    std::cout << "наличие капюшона: " << (hasHood ? "да" : "нет") << std::endl;
}

void Outerwear::save(std::ofstream& out) const {
    out << getType() << " " << name << " " << price << " " << size << " " << season << " " << hasHood << std::endl;
}

void Outerwear::load(std::ifstream& in) {
    in >> name >> price >> size >> season >> hasHood;
}

std::string Outerwear::getType() const {
    return "Outerwear";
}

Outerwear* Outerwear::createFromFile(std::ifstream& file) {
    std::string name;
    int size;
    double price;
    std::string season;
    bool hasHood;
    file >> name >> size >> price >> season >> hasHood;
    return new Outerwear(name, size, price, season, hasHood);
}
