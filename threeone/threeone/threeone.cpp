#include "Header.h"

int main()
{
	
	ofstream outfile_third;
	ifstream infile_first;
	ifstream infile_second;

	outfile_third.open("third_file.txt");
	infile_first.open("f.txt");
	infile_second.open("g.txt");

	merge(outfile_third, infile_first, infile_second);

	infile_first.close();
	infile_second.close();
	outfile_third.close();

	return 0;
}

