#include <iostream>
#include <cstdlib>
#include "Set.h"
#include <algorithm>
//#define max(a,b) (((a > b) ? (a) : (b));

using namespace std;

Set::Set(int el) : set_size(el), set(el) {};

Set::Set(const Set& mn) : set_size(mn.set_size), set(mn.set) {};

Set::Set(Bit& bp) : set_size(bp.get_size()), set(bp) {};

Set::operator Bit()
{
	Bit tmp(this->set);
	return tmp;
}

void Set::add(const int el)
{
	set.set_bit(el);
}


void Set::del(const int el)
{
	set.clr_bit(el);
}

void Set::clr_set()
{
	for (int i = 0; i < set_size; ++i)
		set.clr_bit(i);
}

Set Set::unionn(const Set& mn)
{
	Set resalt(max(set_size, mn.set_size));
	resalt.set = set | mn.set;
	return resalt;
}


Set Set::intersectionl(const Set& mn)
{
	Set resalt(max(set_size, mn.set_size));
	resalt.set = set & mn.set;
	return resalt;
}


Set Set::complement()
{
	Set resalt(set_size);
	resalt.set = ~set;
	return resalt;
}

bool Set::compare(const Set& mn)
{
	bool fl = 0;
	if (set_size == mn.set_size && set == mn.set) fl = 1;
	return fl;
}

bool Set::belong(const int el)
{
	bool resalt = false;
	(set.get_bit(el) == 0) ? resalt = 0 : resalt = 1;
	return resalt;
}

istream& operator >>(istream& is, Set& op2)
{
	int numb = 0;

	for (int i = 0; i < op2.set_size; i++)
	{
		is >> numb;
		if ((numb >= 0) && (numb < op2.set_size))
			op2.add(numb); else break;
	}
	return is;
}

ostream& operator<<(ostream& os, Set& op2)
{
	Set help(op2.set);
	int count = 0, set_size = op2.set_size, flag = 0;
	os << "{";

	for (int i = 0; i < set_size; ++i)
	{
		if (op2.set.get_bit(i) != 0)
		{
			if (flag == 1)
			{
				os << ", ";
				--flag;
			}
			os << i;
			++flag;
			++count;
		}
	}
	if (count == 0) os << '-';
	os << "}";

	return os;
}













