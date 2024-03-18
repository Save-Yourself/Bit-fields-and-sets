#pragma once
#include <iostream>

using namespace std;

class Bit
{
private:
	int* arr;
	int size;
	int n_lamp;

	int get_index(const int n) const
	{
		return n >> 5;
	}
	int get_bit_mask(const int n) const
	{
		return 1 << (n & 31);
	}

public:
	Bit();
	Bit(const int n);
	Bit(const Bit& b2);
	~Bit();

	int get_size();

	void set_bit(const int n);
	void clr_bit(const int n);
	int get_bit(const int n);

	bool operator ==(const Bit& b2);
	void operator =(const Bit& b2);
	Bit operator &(const Bit& b2);
	Bit operator |(const Bit& b2);
	Bit operator~();

	friend ostream& operator<<(ostream& ofstr, const Bit& b2);
	friend istream& operator>>(istream& ifstr, Bit& b2);

	//int get_value(int low, int up);
};
