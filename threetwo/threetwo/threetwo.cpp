#include "Header.h"

int main()
{
	ofstream outfile_third_bin;
	ifstream infile_first;
	ifstream infile_second;

	outfile_third_bin.open("third_file.bin", ios::binary);
	infile_first.open("f",ios::binary);
	infile_second.open("g",ios::binary);

	merge_bin(outfile_third_bin,infile_first, infile_second);

	infile_first.close();
	infile_second.close();
	outfile_third_bin.close();

	return 0;
}
