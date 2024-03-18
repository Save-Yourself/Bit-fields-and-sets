#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include "Bit.h"

using namespace std;

Bit::Bit()
{
	size = 0;
	arr = NULL;
	n_lamp = 0;
}

Bit::Bit(int n)
{
	n_lamp = n;
	size = (n_lamp + 31) >> 5;
	arr = new int[size + 1];
	if (arr != NULL)
		for (int i = 0; i < size; i++)
			arr[i] = 0;
}

//if (n_lamp % 32 == 0) size = n_lamp / 32; else size = n_lamp / 32 + 1;

Bit::Bit(const Bit& b2)
{
	n_lamp = b2.n_lamp;
	size = b2.size;
	arr = new int[size + 1];
	if (arr != NULL)
		for (int i = 0; i < size; i++)
			arr[i] = b2.arr[i];
}

Bit :: ~Bit()
{
	delete[]arr;
	size = 0;
	n_lamp = 0;
}

int Bit::get_size()
{
	return size;
}

/*int Bit::get_index(const int n)
{
	return n >> 5;
}*/

/*int Bit::get_bit_mask(const int n)
{
	return 1 << (n & 31);
}
*/

void Bit::set_bit(const int n)
{
	if (n > -1 && n < n_lamp) arr[get_index(n)] |= get_bit_mask(n);
}

void Bit::clr_bit(const int n)
{
	if (n > -1 && n < n_lamp) arr[get_index(n)] &= ~get_bit_mask(n);
}

int Bit::get_bit(const int n)
{
	if ((n > -1) && (n < n_lamp)) return arr[get_index(n)] & get_bit_mask(n);
	return 0;
}

bool Bit::operator == (const Bit& b2)
{
	bool res = 0, fl = 1;
	if (n_lamp == b2.n_lamp)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] != b2.arr[i]) fl = 0;
		}
		res = fl;
	}
	return res;
}

void Bit ::operator= (const Bit& b2)
{
	if (arr != NULL)
	{
		arr = NULL;
		size = 0;
	}
	n_lamp = b2.n_lamp;
	size = b2.size;
	arr = new int[size + 1];
	if (arr != NULL)
		for (int i = 0; i < size; i++)
			arr[i] = b2.arr[i];
}

Bit Bit :: operator &(const Bit& b2)
{
	int min_size, min_n_lamp;
	//(size > b2.size) ? (min_size = b2.size) : (min_size = size);
	//(n_lamp > b2.n_lamp) ? (min_n_lamp = b2.n_lamp) : (min_n_lamp = n_lamp) size?;
	min_size = min(b2.size, size);
	min_n_lamp = min(b2.n_lamp, n_lamp);
	Bit resalt(min_n_lamp);

	for (int i = 0; i < min_size; ++i)
	{
		resalt.arr[i] += arr[i] & b2.arr[i];
	}
	return resalt;
}

Bit Bit :: operator |(const Bit& b2)
{
	int max_size, min_size, max_n_lamp;
	min_size = min(b2.size, size);
	max_n_lamp = max(b2.n_lamp, n_lamp);

	Bit resalt(max_n_lamp);

	int i = 0;

	for (i; i < min_size; ++i)
	{
		resalt.arr[i] += arr[i] | b2.arr[i];
	}

	if (size > b2.size)
	{
		max_size = size;
		for (i; i < max_size; ++i)
		{
			resalt.arr[i] += arr[i];
		}
	}
	else
	{
		max_size = b2.size;
		for (i; i < max_size; i++)
		{
			resalt.arr[i] = b2.arr[i];
		}
	}
	return resalt;
}

Bit Bit::operator~()
{
	Bit res(n_lamp);

	for (int i = 0; i < size; ++i)
		res.arr[i] = ~arr[i];

	return res;
}

istream& operator >> (istream& ifstr, Bit& b2)
{
	ifstr >> b2.n_lamp;
	return ifstr;
}

ostream& operator << (ostream& ofstr, const Bit& b2)
{
	int count = 0;
	int hh = sizeof(int) * 8 * b2.size - b2.n_lamp;
	for (int j = b2.size - 1; j >= 0; j--)
	{
		for (int i = sizeof(int) * 8; i > -1; --i)
		{
			if (hh <= 0) ofstr << ((b2.arr[j] >> i) & 1);
			hh--;
			//count++;
			//if (count == arr_.n_lamp) return ofstr;
		}
	}
	return ofstr;
}
