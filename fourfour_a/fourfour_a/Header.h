#include <iostream>

using namespace std;

template <typename T>
class Vector {
private:
    const int MAXSIZE = 100;
    T* array;
    int size;

public:
    Vector() {
        array = new T[MAXSIZE];
        size = 0;
    }


    Vector(int insize, T* inarray) {
        size = insize;
        array = new T[insize];
        for (int i = 0; i < insize; i++) {
            array[i] = inarray[i];
        }
    }

    Vector(const Vector& anotherVector) {
        size = anotherVector.size;
        array = new T[size];
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

    void mathActions(int action, T scalar) {
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
        T sum = 0;
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
    void merge(const Vector<T>& first, const Vector<T>& second) {
        size = first.size + second.size;
        delete[] array;
        array = new T[size];
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
    void elementWiseAddition(const Vector<T>& anotherVector) {
        if (size != anotherVector.size) {
            cout << "size(" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            array[i] += anotherVector.array[i];
        }
    }

    void elementWiseSubtraction(const Vector<T>& anotherVector) {
        if (size != anotherVector.size) {
            cout << "size(" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            array[i] -= anotherVector.array[i];
        }
    }

    void elementWiseMultiplication(const Vector<T>& anotherVector) {
        if (size != anotherVector.size) {
            cout << "size(" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            array[i] *= anotherVector.array[i];
        }
    }

    void elementWiseDivision(const Vector<T>& anotherVector) {
        if (size != anotherVector.size) {
            cout << "size(" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            if (anotherVector.array[i] != 0) {
                array[i] /= anotherVector.array[i];
            }
            else {
                cout << "Division by 0" << endl;
                return;
            }
        }
    }
};
        
       
    

