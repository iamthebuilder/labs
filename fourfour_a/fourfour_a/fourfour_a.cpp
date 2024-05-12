#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Header.h"
using namespace std;

int main() {
    Vector<double> vector_1;
    vector_1.setSize();
    vector_1.fillArrayKeyboard();
    cout << "Filled by keyboard" << endl;
    vector_1.printArray();
    cout << "Size is: " << vector_1.getSize() << endl;
    cout << "Length is: " << vector_1.length() <<endl;
    cout << "By index: ";
    vector_1.printByIndex(3);
    vector_1.fillByIndex(3);
    cout << "Edited with index" << endl;
    vector_1.printArray();


    Vector<double> vector1;
    vector1.setSize();
    vector1.fillArrayKeyboard();

    Vector<double> vector2;
    vector2.setSize();
    vector2.fillArrayKeyboard();

    vector1.elementWiseAddition(vector2);
    vector1.printArray();

    Vector<double> vector_3;
    vector_3.setSize();
    vector_3.fillArrayKeyboard();

    Vector<double> vector_2;
    vector_2.setSize();
    vector_2.fillArrayKeyboard();

    Vector<double> result;
    result.merge(vector_3, vector_2);
    cout << "Merged Vector: ";
    result.printArray();

    vector_1.fillRand();
    cout << "Filled by rand" << endl;
    vector_1.printArray();

    return 0;
}