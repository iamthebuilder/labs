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


void merge(ofstream& result, ifstream& first_file, ifstream& second_file, int fir_num, int sec_num) {
    int index_1 = 0;
    int index_2 = 0;
    double num_1 = 0;
    double num_2 = 0;
    first_file >> num_1;
    second_file >> num_2;
    while (index_1 < fir_num && index_2 < sec_num) {
        if (num_1 >= num_2) {
            result << num_1 << endl;
            index_1++;
            first_file >> num_1;
        }
        else
        {
            result << num_2 << endl;
            index_2++;
            second_file >> num_2;
        }
    }
    while (index_1 < fir_num) {
        result << num_1 << endl;
        index_1++;
        first_file >> num_1;
    }
    while (index_2 < sec_num) {
        result << num_2 << endl;
        index_2++;
        second_file >> num_2;
    }
}

