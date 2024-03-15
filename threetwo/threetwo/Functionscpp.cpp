#include "Header.h"

void merge(ofstream& result_txt, ofstream& result_bin,ifstream& first_file, ifstream& second_file) {

    double num_1 = 0;
    double num_2 = 0;

    first_file >> num_1;
    second_file >> num_2;

    while (!first_file.eof() || !second_file.eof()) {
        if (num_1 >= num_2) {
            result_txt << num_1 << endl;
            result_bin.write(reinterpret_cast<char*>(&num_1), sizeof(num_1));
            if (!first_file.eof()) {
                first_file >> num_1;
            }
            else {
                result_txt << num_2 << endl;
                result_bin.write(reinterpret_cast<char*>(&num_2), sizeof(num_2));
                break;
            }
        }
        else {
            result_txt << num_2 << endl;
            result_bin.write(reinterpret_cast<char*>(&num_2), sizeof(num_2));
            if (!second_file.eof()) {
                second_file >> num_2;
            }
            else {
                result_txt << num_1 << endl;
                result_bin.write(reinterpret_cast<char*>(&num_1), sizeof(num_1));
                break;
            }
        }
    }
    while (first_file >> num_1) {
        result_txt << num_1 << endl;
        result_bin.write(reinterpret_cast<char*>(&num_1), sizeof(num_1));
    }
    while (second_file >> num_2) {
        result_txt << num_2 << endl;
        result_bin.write(reinterpret_cast<char*>(&num_2), sizeof(num_2));
    }
}






