#include "Header.h"

void merge_bin(ofstream& result, ifstream& first_file, ifstream& second_file) {
    double num_1 = 0;
    double num_2 = 0;
    first_file.read(reinterpret_cast<char*>(&num_1), sizeof(num_1));
    second_file.read(reinterpret_cast<char*>(&num_2), sizeof(num_2));
    while (!first_file.eof() && !second_file.eof()) {
        if (num_1 >= num_2) {
            result.write(reinterpret_cast<char*>(&num_1), sizeof(num_1));
            if (!first_file.eof()) {
                first_file.read(reinterpret_cast<char*>(&num_1), sizeof(num_1));
            }
            else {
                result.write(reinterpret_cast<char*>(&num_2), sizeof(num_2));
                break;
            }
        }
        else
        {
            result.write(reinterpret_cast<char*>(&num_2), sizeof(num_2));
            if (!first_file.eof()) {
                first_file.read(reinterpret_cast<char*>(&num_2), sizeof(num_2));
            }
            else {
                result.write(reinterpret_cast<char*>(&num_1), sizeof(num_1));
                break;
            }
        }
    }
    while (first_file.read(reinterpret_cast<char*>(&num_1), sizeof(num_1))) {
        result.write(reinterpret_cast<char*>(&num_1), sizeof(num_1));
        
    }
    while (first_file.read(reinterpret_cast<char*>(&num_2), sizeof(num_2))) {
        result.write(reinterpret_cast<char*>(&num_2), sizeof(num_2));
        
    }
}

