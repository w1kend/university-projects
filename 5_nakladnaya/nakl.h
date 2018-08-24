#pragma once
#include "stdafx.h"
#include <Windows.h>
#include "iostream"
#include "Mystring.h"
#include "DateTime.h"
using namespace std;

class nakl
{
	Mystring name;
	double price;
	int n_nakl;
	Mystring name_firm;
	Mystring email_firm;
	Mystring name_kladovshik;
	DateTime data;
public:
	nakl();
	nakl(Mystring _name, double _price, int _n_nakl, Mystring _name_firm, Mystring _email_firm, Mystring _name_kladovshik, DateTime _data);
	nakl(nakl& a);
	~nakl();
	Mystring get_name();
	double get_price();
	int get_n();
	Mystring get_name_firm();
	Mystring get_email_firm();
	Mystring get_name_kladovshik();
	DateTime get_data();

	void set_name();
	void set_n();
	void set_price();
	void set_name_firm();
	void set_email_firm();
	void set_name_kladovshik();
	void set_data();
	void f_print();
	void f_input();
	void print();
	void input();
	friend bool operator==(nakl& b,nakl& a);
};
