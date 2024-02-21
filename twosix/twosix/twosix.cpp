#include <iostream>      // for cin cout
using namespace std;

struct Node
{
	double d;
	Node* next;  // указатель на следующий элемент списка
	Node* pred; // указатель на предыдущий элемент списка
};
void   add_to_list(Node*&, Node*&, double element);
void   print_list(Node*top);
int dimension(int dim);
double sum(Node* top,int dim);

int main()
{
	int dim = 0;
	dim = dimension(dim);
	Node* top = NULL, * end = NULL;
	double temp = 0;
	for (int i = 0; i < dim; i++) {
		cout << "Enter the num :";
		cin >> temp;
		add_to_list(top, end,temp);
	}
	print_list(end);
	int result = 0;
	result = sum(end, dim);
	cout << result;
	return 0;
}
int dimension(int dim) {
	cout << "Enter the dimension of ur list ";
	cin >> dim;
	return dim;
}
void print_list(Node* end)
{
	while (end)
	{
		cout << end->d << ' ';
		end = end->pred;
	}
	cout << "\n";
}
void add_to_list(Node*& top, Node*& end, double element)
{
	Node* pv = NULL, * ppv = NULL;

	Node* nv = new Node;
	nv->d = element; // образуем новый элемент списка
	nv->next = NULL;
	nv->pred = NULL;
	if (top == nullptr) {
		top = nv;
		end = nv;
	}
	else {
	nv->next = top;
	top->pred = nv;
	top = nv;
    }
}
double sum(Node* end ,int dim) {
	int index = 1;
	int sum = 0;
	while (end != nullptr)
	{
		if (index == 1) {
			sum += end->d;
	    }
		else if (index == dim) {
			sum += 3*(end->d);
		}
		else {
			sum += 4 * (end->d);
		}
		index++;
		end = end->pred;
	}
	return sum;
}

