#include <iostream>
#include <string>

using namespace std;

class Product {
public:
    Product(string name, int size, double price)
        : name(name), size(size), price(price) {}

    virtual void print() const {
        cout << "Name: " << name << endl
            << "Size: " << size << endl
            << "Price : " << price << endl;
    }

private :
    string name;
    int size;
    double price;
};

class Outerwear : public Product {
public:
    Outerwear(string name, int size, double price, string season, bool hasHood)
        : Product(name, size, price), season(season), hasHood(hasHood) {}

    void print() const override {
        Product::print();
        cout << "Season: " << season << endl
            << " hood: " << (hasHood ? "yes" : "no") << endl;
    }

private:
    string season;
    bool hasHood;
};

class Sportswear : public Product {
public:
    Sportswear(string name, int size, double price, string sport)
        : Product(name, size, price), sport(sport) {}

    void print() const override {
        Product::print();
        cout << "Sport: " << sport << endl;
    }

private:
    string sport;
};

class Underwear : public Product {
public:
    Underwear(string name, int size, double price, string material)
        : Product(name, size, price), material(material) {}

    void print() const override {
        Product::print();
        cout << "MAterial: " << material << endl;
    }

private:
    string material;
};

class Footwear : public Product {
public:
    Footwear(string name, int size, double price, string purpose, bool hasHeel)
        : Product(name, size, price), purpose(purpose), hasHeel(hasHeel) {}

    void print() const override {
        Product::print();
        cout << "ppurpose: " << purpose << "\n"
            << "heel: " << (hasHeel ? "yes" : "no") << endl;
    }

private:
    string purpose;
    bool hasHeel;
};

int main() {
    setlocale(LC_ALL, "RUS");
    Outerwear coat("JAcket", 48, 15000.0, "Winter", true);
    Sportswear tracksuit("Costume", 50, 5000.0, "Footbal");
    Underwear underwear("Pants", 44, 1000.0, "Some");
    Footwear shoes("Sneakers", 42, 7000.0, "Male", false);

    cout << "Up";
    coat.print();
    cout << endl;

    cout << "Sport:";
    tracksuit.print();
    cout << endl;

    cout << "Down";
    underwear.print();
    cout << endl;

    cout << "Sjoes:";
    shoes.print();
    cout << endl;

    return 0;
}
