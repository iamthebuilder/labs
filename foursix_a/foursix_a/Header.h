#include <iostream>

using namespace std;


class Vector {
private:
    const int MAXSIZE = 100;
    double* array;
    int size;

public:
    Vector() {
        array = new double[MAXSIZE];
        size = 0;
    }

    Vector(int insize, double* inarray) {
        size = insize;
        array = new double[insize];
        for (int i = 0; i < insize; i++) {
            array[i] = inarray[i];
        }
    }

    Vector(const Vector& anotherVector) {
        size = anotherVector.size;
        array = new double[size];
        for (int i = 0; i < size; i++) {
            array[i] = anotherVector.array[i];
        }
    }

    Vector(Vector&& anotherVector) noexcept {
        array = anotherVector.array;
        anotherVector.array = nullptr;
        size = anotherVector.size;
        anotherVector.size = 0;
    }

    ~Vector() {
        delete[] array;
        cout << "Destructed" << endl;
    }

    void setSize() {
        cout << "Enter the size < " << MAXSIZE << endl;
        cin >> size;
        if (size > MAXSIZE) {
            size = MAXSIZE;
        }
    }

    void fillArrayKeyboard() {
        cout << "Fill the array" << endl;
        for (int i = 0; i < size; i++) {
            cin >> array[i];
        }
    }

    void printArray() {
        cout << endl;
        for (int i = 0; i < size; i++) {
            cout << array[i] << endl;
        }
        cout << endl;
    }

    void printByIndex(int index) {
        if (index < size) {
            cout << "The el of index is " << array[index] << endl;
        }
        else {
            cout << "Borders(" << endl;
        }
    }

    void fillByIndex(int index) {
        if (index < size) {
            cout << "Enter the el";
            cin >> array[index];
        }
        else {
            cout << "Borders(" << endl;
        }
    }

    int getSize() {
        return size;
    }

    void mathActions(int action, double scalar) {
        if (action == 1)
        {
            for (int i = 0; i < size; i++)
            {
                array[i] += scalar;
            }
        }
        if (action == 2)
        {
            for (int i = 0; i < size; i++)
            {
                array[i] -= scalar;
            }
        }
        if (action == 3)
        {
            for (int i = 0; i < size; i++)
            {
                array[i] *= scalar;
            }
        }
        if (action == 4 && scalar != 0)
        {
            for (int i = 0; i < size; i++)
            {
                array[i] /= scalar;
            }
        }
    }

    double length() {
        double sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += array[i] * array[i];
        }
        return pow(sum, 0.5);
    }

    void fillRand() {
        srand(time(nullptr));
        for (int i = 0; i < size; i++)
        {
            array[i] = rand() % 10;
        }
    }
    void merge(const Vector& first, const Vector& second) {
        size = first.size + second.size;
        delete[] array;
        array = new double[size];
        int i = 0, j = 0, k = 0;
        while (i < first.size && j < second.size) {
            if (first.array[i] < second.array[j]) {
                array[k] = first.array[i];
                i++;
            }
            else
            {
                array[k] = second.array[j];
                j++;
            }
            k++;
        }

        while (i < first.size) {
            array[k] = first.array[i];
            i++;
            k++;
        }

        while (j < second.size) {
            array[k] = second.array[j];
            j++;
            k++;
        }
    }
    friend ostream& operator<< (ostream& out, const Vector& object);
    friend istream& operator>> (istream& in, Vector& object);
    /*friend ostream& operator<< (ostream& out, const Vector& object) {
        for (int i = 0; i < object.size; i++) {
            out << object.array[i] << endl;
        }
        return out;
    }
    friend istream& operator>> (istream& in, Vector& object)
    {
        cout << "Fill with operator";
        for (int i = 0; i < object.size; i++)
        {
            in >> object.array[i];
        }
        return in;
    }*/
};
ostream& operator<< (ostream& out, const Vector& object)
{
    
    for (int i = 0; i < object.size; i++)
    {
        out << object.array[i] << endl;
    }

    return out;
}
istream& operator>> (istream& in, Vector& object)
{
    cout << "Fill with operator";
    for (int i = 0; i < object.size; i++)
    {
        in >> object.array[i];
    }
    return in;
}