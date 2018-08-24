#include "stdafx.h"
#include "link.h"
#include "iterator.h"

Iterator::Iterator()
{
	cur = 0;
}
Iterator::Iterator(link* _cur)
{
	cur = _cur;
}
Iterator::Iterator(Iterator& obj)
{
	cur = obj.cur;
}

void Iterator::next()
{
	cur = cur->next;
}

void Iterator::prev()
{
	cur = cur->prev;
}

void Iterator::print()
{
	cur->print();
}

bool operator!=(Iterator& obj_1, Iterator& obj_2)
{
	return obj_1.cur!=obj_2.cur;
}