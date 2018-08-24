// 5_nakladnaya.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "iterator.h"
#include "list.h"
#include "Mystring.h"
#include <Windows.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	//SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "Russian");
	list q;
	char c;
	do
	{
		cout << "Выберите действоие" << endl;
		cout << "1. Добавить товар" << endl;
		cout << "2. Удалить товар" << endl;
		cout << "3. Вывести все товары" << endl;
		cout << "4. Поиск товаров по определенным критериям" << endl;
		cout << "5. Вывести все товары, цена которых выше заданной" << endl;
		cout << "6. Вывести в файл" << endl;
		cout << "7. Ввести из файла" << endl;
		cout << "8. Cортировка" << endl;
		int x;
		cin >> x;
		switch (x)
		{
		case 1:{q.add(); break; }
		case 2:{int w; cout << "Какой удалить?" << endl; cin >> w; q.del(w); break;}
		case 3:{q.print(); break;}
		case 4:{q.search(); break;}
		case 5:{cout << "Введите цену" << endl; double tmp; cin >> tmp; q.out_by_price(tmp); break; }
		case 6:{break; }
		case 7:{break; }
		case 8:{q.sort(); break; }
		default:{cout << "Error" << endl; break; }
		}
		cout << "у для повтора" << endl;
		getchar();
		cin >> c;
	} while (c == 'y');
	return 0;
}

