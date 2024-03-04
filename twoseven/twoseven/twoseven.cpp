#include <iostream>  // for cin cout
using namespace std;

struct TREE
{
	int  d;           // число
	TREE* left;       //указатель на левое поддерево
	TREE* right;      //указатель на правое поддерево
};

TREE* search(TREE*, int);
void    add(TREE*&, int);
void    print_tree(TREE*);
void    print_tree_level(TREE*, int);
void    del_tree(TREE*& top);
int dimension(int dim);
void fill_tree(int* save, int dim);
TREE* delete_node(TREE* top, int max);
TREE* min_node(TREE* node);
int find_max(TREE* top);

int main()
{
	int dim = 0;
	dim = dimension(dim);
	int* save = new int[dim];
	fill_tree(save, dim);
	TREE* top = NULL;

	for (int i = 0; i < dim; i++)
		add(top, save[i]);  // добавление узлов дерева
	cout << " Tree " << endl;
	print_tree(top);     // вывод элементов дерева на экран
	cout << endl << endl;
	print_tree_level(top, 0);
	cout << " New tree ";
	int for_del = find_max(top);
	cout << " Max el is " << for_del <<endl;
	top = delete_node(top, for_del);
	print_tree(top);     // вывод элементов дерева на экран
	cout << endl << endl;
	print_tree_level(top, 0);
	// вывод элементов дерева на экран по уровням
	del_tree(top);        // удаление дерева
	cout << " Is new tree empty? ";
	print_tree(top);     // проверка того, что дерево пусто
	cout << endl;
}
// поиск места для нового узла
// возвращаем адрес узла, после которого нужно добавить
// новый элемент
TREE* search(TREE* top, int num)
{
	TREE* pv = top, * ppv = top;
	while (pv)
	{
		ppv = pv;
		if (num < pv->d)
			pv = pv->left;
		else
			pv = pv->right;
	}
	return ppv;
}
TREE* delete_node(TREE* top, int max) {
	if (top == nullptr) {               //если пустое дерево
		return nullptr;
	}
	if (max < top->d) {
		top->left = delete_node(top->left, max);
	}
	else if (max > top->d) {
		top->right = delete_node(top->right, max);
	}
	else {
		if (top->left == NULL) {
			TREE* temp = top->right;
			delete top;
			return temp;
		}
		else if (top->right == NULL) {
			TREE* temp = top->left;
			delete top;
			return temp;
		}
		else {
			TREE* temp = min_node(top->right);
			top->d = temp->d;
			top->right = delete_node(top->right, temp->d);//удаляем тот самый минимальный элемент из правого поддерева
			return top;
		}
	}
	return top;
}


TREE* min_node(TREE* node) {
	TREE* current = node;

	while (current->left != NULL) //самый левый в правом поддереве будет минимальный
		current = current->left;

	return current;
}



// включение нового узла в дерево
void add(TREE*& top, int num)
{
	TREE* pnew = new TREE;  // создаем новый узел
	pnew->d = num;
	pnew->left = NULL;
	pnew->right = NULL;
	if (!top)//  формирование первого узла дерева 
		top = pnew;
	else
	{
		TREE* ppv;
		ppv = search(top,num); // поиск места для нового узла
		if (num < ppv->d)
			ppv->left = pnew;
		//присоединение к левому поддереву предка
		else
			ppv->right = pnew;
		//присоединение к правому поддереву предка
	}
}
	int find_max(TREE * top)
	{
		while (top->right != NULL) //самый левый в правом поддереве будет минимальный
			top = top->right;

		return top->d;
	}


// обход дерева и вывод значений в отсортированном порядке
void print_tree(TREE* top)
{
	if (top)
	{
		print_tree(top->left); //обход левого поддерева
		cout << top->d << "  ";
		print_tree(top->right);//обход правого поддерева
	}
}

// обход дерева и вывод значений  по уровням	
void print_tree_level(TREE* top, int level)
{
	if (top)
	{
		print_tree_level(top->right, level + 1);
		//обход правого поддерева
		for (int i = 0; i < level; i++)
			cout << "    ";
		cout << top->d << endl;
		print_tree_level(top->left, level + 1);
		//обход левого поддерева
	}
}

// удаление дерева 
void del_tree(TREE*& top)
{
	if (top)
	{
		del_tree(top->left); //обход левого поддерева
		del_tree(top->right);//обход правого поддерева
		delete top;            // освобождение памяти 
		top = NULL;
	}
}

int dimension(int dim)
{
	cout << "Enter the num of elements in the tree ";
	cin >> dim;
	return dim;
}

void fill_tree(int* save, int dim)
{
	cout << "Enter the unique nums ";
	for (int i = 0; i < dim; i++)
	{  
		cin >> save[i];
	}
}