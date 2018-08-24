#include "stdafx.h"
#include "nakl.h"
#include "iostream"
#include "Mystring.h"
#include "DateTime.h"
#include <Windows.h>
#include <fstream>
using namespace std;


nakl::nakl() : price(0), n_nakl(0)
{}
nakl::nakl(Mystring _name, double _price, int _n_nakl, Mystring _name_firm, Mystring _email_firm, Mystring _name_kladovshik, DateTime _data)
{
	name = _name;
	price = _price;
	n_nakl = _n_nakl;
	name_firm = _name_firm;
	name_kladovshik = _name_kladovshik;
	email_firm = _email_firm;
	data = _data;
}
nakl::nakl(nakl& a)
{
	name = a.name;
	price = a.price;
	n_nakl = a.n_nakl;
	name_firm = a.name_firm;
	name_kladovshik = a.name_kladovshik;
	email_firm = a.email_firm;
	data = a.data;

}
nakl::~nakl()
{
}

Mystring nakl::get_name()
{
	return name;
}
double nakl::get_price()
{
	return price;
}
int nakl::get_n()
{
	return n_nakl;
}
Mystring nakl::get_name_firm()
{
	return name_firm;
}
Mystring nakl::get_email_firm()
{
	return email_firm;
}
Mystring nakl::get_name_kladovshik()
{
	return name_kladovshik;
}
DateTime nakl::get_data()
{
	return data;
}

void nakl::set_name()
{	
	cout << "Введите название товара" << endl; getchar();
	cin >> name;
	
}
void nakl::set_n()
{
	cout << "Введите количество товара" << endl;
	cin >> n_nakl;
}
void nakl::set_price()
{
	cout << "Введите цену товара" << endl;
	cin >> price;
}
void nakl::set_name_firm()
{
	cout << "Введите название фирмы поставщика" << endl; getchar();
	cin >> name_firm;
}
void nakl::set_email_firm()
{
	cout << "Введите email фирмы поставщика" << endl; 
	cin >> email_firm;
}
void nakl::set_name_kladovshik()
{
	cout << "Введите имя кладовщика " << endl;
	cin >> name_kladovshik;
}
void nakl::set_data()
{
	cout << "Дата поступления на склад: " << endl;
	cin >> data;
}

void nakl::print()
{
	cout << "=========================================" << endl;
	cout << "Название товара \t\t\t" << name << endl;
	cout << "Дата поступления на склад\t" << data << endl;
	cout << "Цена товара \t\t\t\t" << price << endl;
	cout << "Количество товара\t\t\t" << n_nakl << endl;
	cout << "Фирма поставщика \t\t\t" << name_firm << endl;
	cout << "Email поставщика \t\t\t" << email_firm << endl;
	cout << "Имя кладовщика \t\t\t" << name_kladovshik << endl;
	cout << "=========================================" << endl;

}
void nakl::f_print()
{
	ofstream fout("out.txt");
	fout << "=========================================" << endl;
	fout << "Название товара \t\t\t" << name << endl;
	fout << "Дата поступления на склад\t" << data << endl;
	fout << "Цена товара \t\t\t\t" << price << endl;
	fout << "Количество товара\t\t\t" << n_nakl << endl;
	fout << "Фирма поставщика \t\t\t" << name_firm << endl;
	fout << "Email поставщика \t\t\t" << email_firm << endl;
	fout << "Имя кладовщика \t\t\t" << name_kladovshik << endl;
	fout << "=========================================" << endl;
	fout.close();

}
void nakl::input()
{
	set_name();
	set_price();
	set_n();
	set_name_firm();
	set_email_firm();
	set_name_kladovshik();
	set_data();

}


void nakl::f_input()
{
	ifstream fin("in.txt");
	char buf[100];
	while (!fin.eof())
	{
		double _price;
		int _n_nakl;
		DateTime _data;
		fin >> buf;
		Mystring _name = buf;
		fin >> _price;
		fin >> _n_nakl;
		fin >> buf;
		Mystring _name_firm = buf;
		fin >> buf;
		Mystring _email_firm = buf;
		fin >> buf;
		Mystring _name_kladovshik = buf;
		fin >> _data;

	}
	fin.close();
}

bool operator==(nakl& b,nakl& a)
{
	if (b.name == a.name && b.price == a.price &&
		b.n_nakl == a.n_nakl && b.name_firm == a.name_firm &&
		b.email_firm == a.email_firm &&
		b.name_kladovshik == a.name_kladovshik && b.data == a.data)
		return true;
	return false;
}