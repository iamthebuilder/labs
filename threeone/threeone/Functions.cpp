#include "Header.h"


void merge(ofstream& result, ifstream& first_file, ifstream& second_file) {
    double num_1 = 0;
    double num_2 = 0;

    first_file >> num_1;
    second_file >> num_2;

    while (!first_file.eof() || !second_file.eof()) {
        if (num_1 >= num_2) {
            result << num_1 << endl; 
            if (!first_file.eof()) {
                first_file >> num_1;
            }
            else {
                result << num_2 << endl;
                break;
            }
        }
        else {
            result << num_2 << endl;
            if (!second_file.eof()) {
                second_file >> num_2;
            }
            else {
                result << num_1 << endl;
                break;
            }
        }
    }
    while (first_file >> num_1) {
        result << num_1 << endl;
    }
    while (second_file >> num_2) {
        result << num_2 << endl;
    }
}






