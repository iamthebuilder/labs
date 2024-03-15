#include <iostream>
#include <fstream>

using namespace std;

struct person {
    char name[40];
    unsigned int age;
    char sex[10];
    unsigned int course; //инициализация структуры
    double mark;
};

void set_data(person& student) {
    cout << "FIO: ";
    cin.ignore();
    cin.getline(student.name, 40);
    cout << "age: ";
    cin >> student.age;
    cout << "sex: ";                //заполнение динамического массива структур данными
    cin >> student.sex;
    cout << "course: ";
    cin >> student.course;
    cout << "mark: ";
    cin >> student.mark;
}

void add_student(person*& group, int& amount, person student) {
    group[amount] = student;
    amount++;
}

void delete_student(person*& group, int& amount, int index) {
    if (index < 0 || index >= amount) {
        cout << "Array out of bonds" << endl;
        return;
    }
    for (int i = index; i < amount - 1; i++) {
        group[i] = group[i + 1];
    }
    --amount;
}

void print_students(person* group, int amount) {
    for (int i = 0; i < amount; i++) {
        cout << group[i].name << " " << group[i].age << " " << group[i].sex << " " << group[i].course << " " << group[i].mark << endl;
    }
}

void save_to_file(person* group, int amount, const char* file_name) {
    ofstream file(file_name, ios::binary);
    for (int i = 0; i < amount; i++) {
        file.write(reinterpret_cast<char*>(&group[i]), sizeof(person));
    }
    file.close();
}

void save_older_students(person* group, int amount, unsigned int course, unsigned int age, const char* file_name) {
    ofstream file(file_name, ios::binary);
    for (int i = 0; i < amount; i++) {
        if (group[i].course == course && group[i].age > age) {
            file.write(reinterpret_cast<char*>(&group[i]), sizeof(person));
        }
    }
    file.close();
}

void print_older_students(person* group, int amount, unsigned int course, unsigned int age) {
    for (int i = 0; i < amount; i++) {
        if (group[i].course == course && group[i].age > age) {
            cout << group[i].name << " " << group[i].age << " " << group[i].sex << " " << group[i].course << " " << group[i].mark << endl;
        }
    }
}



int main() {
    cout << "Enter the amount of students ";
    int amount = 0;
    cin >> amount;
    person* group = new person[amount];//создание динамического массива структур 
    //ввод данных о студентах с заносом их в этот массив структур
    for (int i = 0; i < amount; i++) {
        set_data(group[i]);
    }
    //сохраняем исходный список студентов в файл
    save_to_file(group, amount, "students.bin");

    print_students(group, amount);//выводим студентов на консоль

    cout << "Enter the course : ";//ввод требуемого курса
    unsigned int course;
    cin >> course;

    cout << "Enter the low limit of age : "; //ввод нижней границы возраста 
    unsigned int age_limit;
    cin >> age_limit;

    //вывод на консоль и сохранение в новый файл нового списка
    print_older_students(group, amount, course, age_limit);
    save_older_students(group, amount, course, age_limit, "older_students.bin");
    //редактируем исходный список 
    cout << "Enter the index of the student to delete: ";
    int index;
    cin >> index;
    delete_student(group, amount, index);//пример удаления студента по индексу из исходного списка
    save_to_file(group, amount, "students.bin");

    print_students(group, amount);

    cout << "Enter the index of the student to edit: ";//пример редактирования студента по введённому индексу
    cin >> index;
    if (index >= 0 && index < amount) {
        set_data(group[index]);
    }

    print_students(group, amount);

    save_to_file(group, amount, "students.bin");

    delete[] group;

    return 0;
}

