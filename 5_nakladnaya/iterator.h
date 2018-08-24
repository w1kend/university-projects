#pragma once
#include "stdafx.h"
#include "link.h"

class Iterator
{
public:
	link* cur;
	friend class list;
	Iterator();
	Iterator(link* _cur);
	Iterator(Iterator& obj);

	void next();
	void prev();
	void print();

	friend bool operator!=(Iterator& obj_1, Iterator& obj_2);
};