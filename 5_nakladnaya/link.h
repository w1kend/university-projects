#pragma once

#include "stdafx.h"
#include "Windows.h"
#include "iostream"
#include "Mystring.h"
#include "nakl.h"
using namespace std;

class link
{
	
public:
	nakl* inf;
	link* next;
	link* prev;
	link();
	link(link* next1, link* prev);
	link(nakl* inf1, link* next1, link* prev1);
	~link();

	//===
	void print();
};