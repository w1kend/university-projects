// 5_nakladnaya.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	//SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	//SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
	setlocale(LC_ALL, "Russian");
	list q;
	char c;
	do
	{
		cout << "�������� ���������" << endl;
		cout << "1. �������� �����" << endl;
		cout << "2. ������� �����" << endl;
		cout << "3. ������� ��� ������" << endl;
		cout << "4. ����� ������� �� ������������ ���������" << endl;
		cout << "5. ������� ��� ������, ���� ������� ���� ��������" << endl;
		cout << "6. ������� � ����" << endl;
		cout << "7. ������ �� �����" << endl;
		cout << "8. C���������" << endl;
		int x;
		cin >> x;
		switch (x)
		{
		case 1:{q.add(); break; }
		case 2:{int w; cout << "����� �������?" << endl; cin >> w; q.del(w); break;}
		case 3:{q.print(); break;}
		case 4:{q.search(); break;}
		case 5:{cout << "������� ����" << endl; double tmp; cin >> tmp; q.out_by_price(tmp); break; }
		case 6:{break; }
		case 7:{break; }
		case 8:{q.sort(); break; }
		default:{cout << "Error" << endl; break; }
		}
		cout << "� ��� �������" << endl;
		getchar();
		cin >> c;
	} while (c == 'y');
	return 0;
}

