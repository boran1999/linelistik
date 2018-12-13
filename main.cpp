#include <iostream>
#include <locale.h>
#include "List.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	LineList<int> list;
	cout << "Начало: " << list << endl;
	list.insertFirst(10);
	LineListElem<int>* ptr = list.getStart();
	list.insertAfter(ptr, 15);
	list.insertAfter(ptr->getNext(), 12);
	list.insertFirst(7);
	cout << "Шаг 1: " << list << endl;
	cout << "Шаг 2: " << list.getptr(2) << endl;
	cout << "Шаг 3: " << list.findptr(12) << endl;
	system("pause");
	return 0;
}
