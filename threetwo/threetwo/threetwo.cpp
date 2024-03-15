#include "Header.h"

int main()
{
	ofstream outfile_third_bin;
	ofstream outfile_third_txt;
	ifstream infile_first;
	ifstream infile_second;

	outfile_third_txt.open("third_file.txt");
	outfile_third_bin.open("third_file.bin", ios::binary);
	infile_first.open("f.txt");
	infile_second.open("g.txt");

	merge(outfile_third_txt, outfile_third_bin,infile_first,infile_second);

	infile_first.close();
	infile_second.close();
	outfile_third_bin.close();
	outfile_third_txt.close();

	return 0;
}
