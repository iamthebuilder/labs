#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Product {
public:
    Product(string name, int size, double price)
        : name(name), size(size), price(price) {}

    Product(ifstream& file) {
        file >> name >> size >> price;
    }

    virtual void print() const {
        cout << "Name: " << name << endl
            << "Size: " << size << endl
            << "Price: " << price << endl;
    }

    virtual void saveToFile(ofstream& file) const {
        file << name << " " << size << " " << price << " ";
    }

    virtual ~Product() {}

protected:
    string name;
    int size;
    double price;
};

class Outerwear : public Product {
public:
    Outerwear(string name, int size, double price, string season, bool hasHood)
        : Product(name, size, price), season(season), hasHood(hasHood) {}

    Outerwear(ifstream& file)
        : Product(file) {
        file >> season >> hasHood;
    }

    void print() const override {
        Product::print();
        cout << "season: " << season << endl
            << "hood: " << (hasHood ? "yes" : "no") << endl;
    }

    void saveToFile(ofstream& file) const override {
        file << "Outerwear ";
        Product::saveToFile(file);
        file << season << " " << hasHood << endl;
    }
    static Outerwear* createFromFile(ifstream& file) {
        string name;
        int size;
        double price;
        string season;
        bool hasHood;
        file >> name >> size >> price >> season >> hasHood;
        return new Outerwear(name, size, price, season, hasHood);
    }

private:
    string season;
    bool hasHood;
};

class Sportswear : public Product {
public:
    Sportswear(string name, int size, double price, string sport)
        : Product(name, size, price), sport(sport) {}

    Sportswear(ifstream& file)
        : Product(file) {
        file >> sport;
    }

    void print() const override {
        Product::print();
        cout << "Sport: " << sport << endl;
    }

    void saveToFile(ofstream& file) const override {
        file << "Sportswear ";
        Product::saveToFile(file);
        file << sport << endl;
    }
    static Sportswear* createFromFile(ifstream& file) {
        string name;
        int size;
        double price;
        string sport;
        file >> name >> size >> price >> sport;
        return new Sportswear(name, size, price, sport);
    }

private:
    string sport;
};

class Underwear : public Product {
public:
    Underwear(string name, int size, double price, string material)
        : Product(name, size, price), material(material) {}

    Underwear(ifstream& file)
        : Product(file) {
        file >> material;
    }

    void print() const override {
        Product::print();
        cout << "Material: " << material << endl;
    }

    void saveToFile(ofstream& file) const override {
        file << "Underwear ";
        Product::saveToFile(file);
        file << material << endl;
    }
    static Underwear* createFromFile(ifstream& file) {
        string name;
        int size;
        double price;
        string material;
        file >> name >> size >> price >> material;
        return new Underwear(name, size, price, material);
    }

private:
    string material;
};

class Footwear : public Product {
public:
    Footwear(string name, int size, double price, string purpose, bool hasHeel)
        : Product(name, size, price), purpose(purpose), hasHeel(hasHeel) {}

    Footwear(ifstream& file)
        : Product(file) {
        file >> purpose >> hasHeel;
    }

    void print() const override {
        Product::print();
        cout << "Purpose: " << purpose << endl
            << "Has heel: " << (hasHeel ? "yes" : "no") << endl;
    }

    void saveToFile(ofstream& file) const override {
        file << "Footwear ";
        Product::saveToFile(file);
        file << purpose << " " << hasHeel << endl;
    }
    static Footwear* createFromFile(ifstream& file) {
        string name;
        int size;
        double price;
        string purpose;
        bool hasHeel;
        file >> name >> size >> price >> purpose >> hasHeel;
        return new Footwear(name, size, price, purpose, hasHeel);
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

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (!file) {
            cerr << "Не удалось открыть файл для записи." << endl;
            return;
        }

        file << array.size() << endl;
        for (const auto& product : array) {
            product->saveToFile(file);
        }
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Не удалось открыть файл для чтения." << endl;
            return;
        }

        int size;
        file >> size;

        for (int i = 0; i < size; ++i) {
            string type;
            file >> type;

            if (type == "Outerwear") {
                array.push_back(Outerwear::createFromFile(file));
            }
            else if (type == "Sportswear") {
                array.push_back(Sportswear::createFromFile(file));
            }
            else if (type == "Underwear") {
                array.push_back(Underwear::createFromFile(file));
            }
            else if (type == "Footwear") {
                array.push_back(Footwear::createFromFile(file));
            }
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
    productArray.removeProduct(shoes);
    productArray.removeProduct(tracksuit);

    cout << "after remove" << endl;
    productArray.printProducts();

    productArray.saveToFile("products.txt");

    ProductArray loadedProductArray;
    loadedProductArray.loadFromFile("products.txt");

    cout << "loaded products" << endl;
    loadedProductArray.printProducts();

    return 0;
}
