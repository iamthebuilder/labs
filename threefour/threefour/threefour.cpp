#include <iostream>
#include <fstream>


using namespace std;

struct man {
	char name[40];
	unsigned int age;
	char sex[10];
	unsigned int course;
	double mark;

	void get_data() {
		cout << "FIO: ";
		cin >> name;
		cout << "age: ";
		cin >> age;
		cout << "sex: ";
		cin >> sex;
		cout << "course: ";
		cin >> course;
		cout << "mark: ";
		cin >> mark;
	}

};

int main() {
	man student;
	cout << "Enter the amount of students";
	int amount = 0;
	cin >> amount;
	man* group = new man[amount];

	ofstream outfile_first("first_file.txt");
	if (!outfile_first.is_open())
	{
		cout << "Error of the opening" << endl;
		return 1;
	}

	for (int i = 0; i < amount; i++) {
		student.get_data();
		outfile_first << student.name << "	" << student.age << "	" << student.sex << "	" << student.course << "	" << student.mark << endl;
	}
	outfile_first.close();

	unsigned low_age = 0;
	cout << "Enter the low limit of age: ";
	cin >> low_age;

	ifstream infile_first("first_file.txt");
	ofstream outfile_result("result_file.txt");
	if (!infile_first.is_open() || !outfile_result.is_open())
	{
		cout << "Error of the opening" << endl;
		return 1;
	}

	
	for (int i = 0; i < amount; i++) {
		infile_first >> group[i].name >> group[i].age >> group[i].sex >> group[i].course >> group[i].mark;
	}

	for (int i = 0; i < amount; i++) {
		if (group[i].age > low_age)
			outfile_result << group[i].name << "	" << group[i].age << "	" << group[i].sex << "	" << group[i].course << "	" << group[i].mark << endl;
	}

	infile_first.close();
	outfile_result.close();

	return 0;
}
