#include "Header.h"


void create_stream(ofstream& outfile, int n)
{
	double v = (rand() % 10)*0.01;
	outfile << v << endl;
	for (int i = 1; i < n; i++)
	{
		v = v - rand() % 10;
		outfile << v << endl;
	}
}


void merge(ofstream& result, ifstream& first_file, ifstream& second_file) {
    double num_1 = 0;
    double num_2 = 0;
    first_file >> num_1;
    second_file >> num_2;
    while (!first_file.eof() && !second_file.eof()) {
        if (num_1 >= num_2) {
            result << num_1 << endl;
            first_file >> num_1;
        }
        else
        {
            result << num_2 << endl;
            second_file >> num_2;
        }
    }
    while (!first_file.eof()) {
        result << num_1 << endl;
        first_file >> num_1;
    }
    while (!second_file.eof()) {
        result << num_2 << endl;
        second_file >> num_2;
    }
}

