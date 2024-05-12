#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
public:
    Product(string name, int size, double price)
        : name(name), size(size), price(price) {}

    virtual void print() const {
        cout << "Name: " << name << endl
            << "Size: " << size << endl
            << "Price: " << price << endl;
    }

private:
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
        cout << "season: " << season << endl
            << "hood: " << (hasHood ? "yes" : "no") << endl;
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
        cout << "sport: " << sport << endl;
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
        cout << "material: " << material << endl;
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
        cout << "purpose: " << purpose << endl
            << "heel: " << (hasHeel ? "yes" : "no") << endl;
    }

private:
    string purpose;
    bool hasHeel;
};

class ProductArray {
public:
    ProductArray() : array() {}

    void addProduct(Product* product) {
        array.push_back(product);
    }

    void removeProduct(Product* product) {
        for (auto it = array.begin(); it != array.end(); ++it) {
            if (*it == product) {
                delete* it;
                array.erase(it);
                break;
            }
        }
    }

    void printProducts() const {
        for (const auto& product : array) {
            product->print();
            cout << endl;

        }
    }

    ~ProductArray() {
        for (auto& product : array) {
            delete product;
        }
    }

private:
    vector<Product*> array;
};


    int main() {
        setlocale(LC_ALL, "RUS");

        Product* coat = new Outerwear("Jacket", 48, 15000.0, "Winter", true);
        Product* tracksuit = new Sportswear("Costume", 50, 5000.0, "Football");
        Product* underwear = new Underwear("Pants", 44, 1000.0, "Cotton");
        Product* shoes = new Footwear("Sneakers", 42, 7000.0, "Running", false);

        ProductArray productArray;

        productArray.addProduct(coat);
        productArray.addProduct(tracksuit);
        productArray.addProduct(underwear);
        productArray.addProduct(shoes);

        cout << "products" << endl;
        productArray.printProducts();

        productArray.removeProduct(coat);

        cout << "after remove" << endl;
        productArray.printProducts();

        return 0;
    }

