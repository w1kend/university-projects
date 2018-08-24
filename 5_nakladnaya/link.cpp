#include "stdafx.h"
#include "Windows.h"
#include "iostream"
#include "Mystring.h"
#include "link.h"
#include "nakl.h"
using namespace std;

link::link():inf(), next(0), prev(0)
	{}
link::link(link* next1=0, link* prev1=0):next(next1), prev(prev1)
	{}
link::link(nakl* inf1, link *next1, link* prev1):inf(inf1), next(next1), prev(prev1)
	{}
link::~link() {delete inf;}
//===
void link::print()
{
	inf->print();
}