#include "Header.h"

int main()
{
	srand((time(nullptr)));
	int fir_num = 0;
	int sec_num = 0;
	cout << "Enter the num of numbers of the first file";
	cout << endl;
	cin >> fir_num;   
	cout << "Enter the num of numbers of the second file";
	cout << endl;
	cin >> sec_num;

	ofstream outfile_first;
	ofstream outfile_second;
	ofstream outfile_third;
	ifstream outfile_firstt;
	ifstream outfile_secondd;
	ifstream outfile_thirdd;
	outfile_first.open("first_file.txt");
	if (!outfile_first.is_open())
	{
		cout << "Error of the opening" << endl;
		return 1;
	}
	outfile_second.open("second_file.txt");
	if (!outfile_second.is_open())
	{
		cout << "Error of the opening" << endl;
		return 1;
	}
	outfile_third.open("third_file.txt");
	if (!outfile_third.is_open())
	{
		cout << "Error of the opening" << endl;
		return 1;
	}
	outfile_firstt.open("first_file.txt");
	if (!outfile_firstt.is_open())
	{
		cout << "Error of the opening" << endl;
		return 1;
	}
	outfile_secondd.open("second_file.txt");
	if (!outfile_secondd.is_open())
	{
		cout << "Error of the opening" << endl;
		return 1;
	}
	outfile_thirdd.open("third_file.txt");
	if (!outfile_thirdd.is_open())
	{
		cout << "Error of the opening" << endl;
		return 1;
	}

	create_stream(outfile_first,fir_num);
	create_stream(outfile_second,sec_num);
	merge(outfile_third, outfile_firstt, outfile_secondd, fir_num,sec_num);

	outfile_firstt.close();
	outfile_secondd.close();
	outfile_third.close();

	return 0;
}

