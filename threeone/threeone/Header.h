#pragma once
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

void create_stream(ofstream& outfile, int n);

void merge(ofstream& result, ifstream& first_file, ifstream& second_file, int fir_num,int sec_num);

