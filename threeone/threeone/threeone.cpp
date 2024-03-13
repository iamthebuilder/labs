#include "Header.h"

int main()
{
	/*srand((time(nullptr)));*/
	/*int fir_dimension = rand() % 10 + 5;
	int sec_dimension = rand() % 9 + 6;*/

	//ofstream outfile_first;
	//ofstream outfile_second;
	ofstream outfile_third;
	ifstream infile_first;
	ifstream infile_second;

	/*outfile_first.open("first_file.txt");
	outfile_second.open("second_file.txt");*/
	

	/*create_stream(outfile_first,fir_dimension);
	create_stream(outfile_second,sec_dimension);*/

	//outfile_first.close();
	//outfile_second.close();

	outfile_third.open("third_file.txt");
	infile_first.open("f.txt");
	infile_second.open("g.txt");

	merge(outfile_third, infile_first, infile_second);

	infile_first.close();
	infile_second.close();
	outfile_third.close();

	return 0;
}

