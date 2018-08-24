#include "stdafx.h"
#include "Windows.h"
#include "iostream"
#include "list.h"
#include "link.h"
#include "iterator.h"
#include "nakl.h"
#include "Mystring.h"
#include "DateTime.h"
#include <fstream>
using namespace std;

list::list()
{
	_end = new link();
	_end->next = _end;
	_end->prev = _end;
}

list::~list()
{
	while (_end->next != _end)
	{
		Iterator i(_end->next);
		_end->next = (i.cur)->next;
		delete i.cur;
	}
}

int list::get_num()
{
	int n = 0;
	for (Iterator i(_end->next); i != Iterator(_end); i.next())
		n++;
	return n;
}

void list::add()
{
	
	nakl* tmp = new nakl();
	tmp->input();
	link* a = new link(tmp, _end, _end->prev);
	(_end->prev)->next = a;
	_end->prev = a;
}

void list::del(int num)
{
	if (num>0 && num <= get_num())
	{
		Iterator i(_end->next);
		for (int j = 1; j != num; j++, i.next())
		{
		}
		(i.cur)->next->prev = (i.cur)->prev;
		(i.cur)->prev->next = (i.cur)->next;
		delete i.cur;
	}
}

void list::change(Iterator num_1, Iterator num_2)
{
	(num_1.cur)->prev->next = num_2.cur;
	(num_2.cur)->next->prev = num_1.cur;
	if ((num_1.cur)->next == (num_2.cur))
	{
		(num_1.cur)->next = (num_2.cur)->next;
		(num_2.cur)->next = num_1.cur;
		(num_2.cur)->prev = (num_1.cur)->prev;
		(num_1.cur)->prev = num_2.cur;
	}
	else if (((num_1.cur)->next)->next == (num_2.cur))
	{
		link *tmp = (num_1.cur)->next;
		(num_1.cur)->next = (num_2.cur)->next;
		(num_2.cur)->next = tmp;
		((num_2.cur)->next)->next = num_1.cur;
		tmp = (num_2.cur)->prev;
		(num_2.cur)->prev = (num_1.cur)->prev;
		(num_1.cur)->prev = tmp;
		((num_2.cur)->next)->prev = num_2.cur;
	}
	else
	{
		link *tmp = (num_2.cur)->next;
		(num_2.cur)->next = (num_1.cur)->next;
		(num_1.cur)->next = tmp;
		tmp = (num_2.cur)->prev;
		(num_2.cur)->prev = (num_1.cur)->prev;
		(num_1.cur)->prev = tmp;
		((num_2.cur)->next)->prev = num_2.cur;
		((num_1.cur)->prev)->next = num_1.cur;
	}
}

void list::change(int a, int b)
{
	Iterator i(_end->next);
	for (int k = 1; k != a; k++, i.next())
		;
	Iterator j(_end->next);
	for (int k = 1; k != b; k++, j.next())
		;
	change(i, j);
}

void list::print()
{
	for (Iterator i(_end->next); i!=Iterator(_end); i.next())
		(i.cur)->print();
}

void list::print(int num)
{
	if (num>0 && num<=get_num())
	{
		Iterator i(_end->next);
		for (int j=1; j!=num; j++, i.next())
			;
		(i.cur)->print();
	}
}

void list::search()
{
	cout << "Выберите критерий поиска\n";
	cout << "1. Название продукта" << endl;
	cout << "2. Цена продукта" << endl;
	cout << "3. По всем полям" << endl;

	int f;
	cin >> f;

	switch (f)
	{
	case 1:{cout << "Введите название продукта" << endl; Mystring tmp; cin >> tmp;
		for (Iterator i(_end->next); i != Iterator(_end); i.next())
			if (  ((i.cur)->inf)->get_name() == tmp)
			{ 
				i.cur->inf->print();
			}
		break; }
	case 2:{cout << "Введите цену" << endl; double tmp; cin >> tmp;
		for (Iterator i(_end->next); i != Iterator(_end); i.next())
			if (  ((i.cur)->inf)->get_price() == tmp)
				i.cur->inf->print(); break; }

	case 3:{nakl tmp; tmp.input();
		for (Iterator i(_end->next); i != Iterator(_end); i.next())
			if (*((i.cur)->inf) == tmp)
				i.cur->inf->print(); break; }
	}
}

void list::zamena()
{
	int f;
	for (Iterator i(_end->next); i != Iterator(_end); i.next())
		i.cur->inf->print();
	cin >> f;
	Iterator i(_end->next);
	for (int j = 1; j < f; j++)
		i.next();
	i.cur->inf->input();
}

void list::out_by_price(double tmp)
{
	for (Iterator i(_end->next); i != Iterator(_end); i.next())
	{
		if ((i.cur)->inf->get_price() > tmp)
			i.cur->inf->print();
	}

}
void list::sort()
{
	cout << "Сортировка по:" << endl;
	cout << "1. Поставщику \n2. Цене" << endl;
	int tmp; cin >> tmp;

	if (tmp == 1)
	{
		for (Iterator i(_end->next); i != Iterator(_end); i.next())
		{
			if (((i.cur)->inf)->get_name_firm() > (((i.cur)->next)->inf)->get_name_firm())
			{
				Iterator i1(i.cur->next); swap(i, i1);
			}
		}
	}
	else if (tmp == 2)
	{
		for (Iterator i(_end->next); i != Iterator(_end); i.next())
		{
			if (((i.cur)->inf)->get_price() > (((i.cur)->next)->inf)->get_price())
			{
				Iterator i1(i.cur->next); swap(i, i1);
			}
		}
	}

}
void list::swap(Iterator &a, Iterator&b)
{
	link* p1 = a.cur->prev;
	link* p2 = b.cur->prev;
	link* n1 = a.cur->next;
	link* n2 = b.cur->next;

	if (a.cur->next == b.cur)
	{
		a.cur->next = n2;
		n2->prev = a.cur;
		b.cur->next = a.cur;
		b.cur->prev = p1;
		p1->next = b.cur;
		a.cur->prev = b.cur;

	}
	else	{
		if (a.cur->prev == b.cur)
		{

			a.cur->prev = p2;
			a.cur->next = b.cur;
			b.cur->next = n1;
			b.cur->prev = a.cur;
			p2->next = a.cur;
			n1->prev = b.cur;
		}
		else
		{
			a.cur->next = n2;
			a.cur->prev = p2;
			b.cur->next = n1;
			b.cur->prev = p1;;
			n2->prev = a.cur;
			p2->next = a.cur;
			n1->prev = b.cur;
			p1->next = b.cur;


		}

	}
}
/*
void list::f_input()
{
	ifstream fin("in.txt");
	char buf[100];
	while (!fin.eof())
	{
		fin >> buf;
		name = buf;
		fin >> price;
		fin >> n_nakl;
		fin >> buf;
		name_firm = buf;
		fin >> buf;
		email_firm = buf;
		fin >> buf;
		name_kladovshik = buf;
		fin >> data;
	}
	fin.close();
}*/


