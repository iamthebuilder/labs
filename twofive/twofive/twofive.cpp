#include <iostream> 
using namespace std;

const int msize = 60;

struct stack_1   //стек_1 
{
	char data_1[msize];
	int size_1;            
};

struct stack_2   //стек_2 
{
	char data_2[msize];
	int size_2;
};

char pop_1(stack_1& list_1) { //Снятие элемента с вершины стека
	if (list_1.size_1 == 0) {
		return 0;
	}
	list_1.size_1--;
	return list_1.data_1[list_1.size_1];
}

char pop_2(stack_2& list_2) { //Снятие элемента с вершины стека
	if (list_2.size_2 == 0) {
		return 0;
	}
	list_2.size_2--;
	return list_2.data_2[list_2.size_2];
}

void push_1(stack_1& list_1, char character) {
	if (list_1.size_1 == msize) {
		return;
	}
	list_1.data_1[list_1.size_1] = character;
	list_1.size_1++;
}

void push_2(stack_2& list_2, char character) {
	if (list_2.size_2 == msize) {
		return;
	}
	list_2.data_2[list_2.size_2] = character;
	list_2.size_2++;
}


void fill_list_1_change_alphabet(stack_1& list_1, int dim,char* alphabet) {
	srand(time(nullptr));
	char temp = '0';
	for (int i = 0; i < dim; i++) {
		temp = "abcdefghijklmnopqrstuvwxyz"[rand() % 26];
		push_1(list_1,temp);
		for (int i = 0; i < 26; i++) {
			if (temp == alphabet[i]) {
				alphabet[i] = '0';
			}
		}
	}
}

void print_stack_1(stack_1 list_1) { //Вывод стека на экран 
	while (list_1.size_1 != 0) {
		cout << pop_1(list_1) << " ";
	}
	cout << endl;
}

void print_stack_2(stack_2 list_2) { //Вывод стека на экран 
	while (list_2.size_2 != 0) {
		cout << pop_2(list_2) << " ";
	}
	cout << endl;
}

int dimension(int dim) {
	cout << "Enter the dimension of the list : ";
	cin >> dim;
	return dim;
}

int main()
{
	int dim = 0;
	dim = dimension(dim);
	char temp = 'a';
	char alphabet[26]{ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	stack_2 list_2;
	list_2.size_2 = 0;
	stack_1 list_1;
	list_1.size_1 = 0;
	fill_list_1_change_alphabet(list_1, dim,alphabet);
	print_stack_1(list_1);
	for (int i = 0; i < 26; i++) {
		cout << alphabet[i];
	}
	cout << endl;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] != '0') {
			push_2(list_2, alphabet[i]);
		}
	}
	print_stack_2(list_2);	
}

