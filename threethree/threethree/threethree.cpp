#include <iostream>
#include <fstream>

using namespace std;

struct students {
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
	students student;
	students group[2]{};
	cout << "Enter the amount of students";
	int amount = 0;
	cin >> amount;

	ofstream outfile_first("first_file.bin", ios::binary);
	if (!outfile_first.is_open())
	{
		cout << "Error of the opening" << endl;
		return 1;
	}

	for (int i = 0; i < amount; i++) {
		student.get_data();
		outfile_first.write(reinterpret_cast<char*>(&student), sizeof(student));
	}
	outfile_first.close();

	unsigned low_age = 0;
	cout << "Enter the low limit of age: ";
	cin >> low_age;

	ifstream infile_first("first_file.bin", ios::binary);
	ofstream outfile_result("result_file.bin", ios::binary);
	if (!infile_first.is_open() || !outfile_result.is_open())
	{
		cout << "Error of the opening" << endl;
		return 1;
	}

	
	for (int i = 0; i < amount; i++) {
		infile_first.read(reinterpret_cast<char*>(&group[i]), sizeof(students));
	}

	for (int i = 0; i < amount; i++) {
		if (group[i].age > low_age)
			outfile_result.write(reinterpret_cast<char*>(&group[i]),sizeof(students));
	}

	infile_first.close();
	outfile_result.close();

	return 0;
}

