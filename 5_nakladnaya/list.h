#pragma once

#include "stdafx.h"
#include "link.h"
#include "iterator.h"
#include "Mystring.h"
#include "nakl.h"
#include <fstream>

class list
{
	friend class Iterator;
	
public:	
	link* _end;
	
	list();
	~list();

	void add();
	void del(int);
	int get_num();
	void change(int,int);
	void change(Iterator, Iterator);
	void print();
	void print(int);
	void search();
	void zamena();
	void out_by_price(double);
	void f_input();
	void list::swap(Iterator &a, Iterator&b);
	void sort();
};