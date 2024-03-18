#pragma once
#include <iostream>
#include "Bit.h"

using namespace std;

class Set
{
private:
	int set_size;
	Bit set;

public:
	Set(int el);
	Set(const Set& mn);
	Set(Bit& bp);
	operator Bit();

	void add(const int el);
	void del(const int el);
	void clr_set();

	Set unionn(const Set& mn);
	Set intersectionl(const Set& mn);
	Set complement();
	bool compare(const Set& mn);
	bool belong(const int el);

	friend istream& operator >>(istream& is, Set& op2);
	friend ostream& operator <<(ostream& of, Set& op2);
};







