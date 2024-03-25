#include <iostream>
#include "Windows.h"
#include "Bit.h"
#include "Set.h"
#include <locale>
#include <algorithm>

using namespace std;

int main()
{
	setlocale(0, "");
	int n1, n2;

	cout << "Введите максимальный элемент первого множества\n";
	cin >> n1;
	n1++;
	cout << "Введите элементы первого множества\n";
	Set s1(n1);
	cin >> s1;
	cout << "Введите максимальный элемент втрого множества\n";
	cin >> n2;
	n2++;
	cout << "Введите элементы второго множества\n";
	Set  s2(n2);
	cin >> s2;

	Set s3(max(n1, n2));

	system("cls");
	cout << s1 << "\n";
	cout << s2 << "\n";
	cout << "Дополнение множества 1\n";
	s3 = s1.complement();
	cout << s3 << "\n";
	cout << "Дополнение множества 2\n";
	s3 = s2.complement();
	cout << s3 << "\n";
	cout << "Объединение множеств 1 и 2\n";
	s3 = s1.unionn(s2);
	cout << s3 << "\n";
	cout << "Пересечение множеств 1 и 2\n";
	s3 = s1.intersectionl(s2);
	cout << s3 << "\n";
	s3 = s1;

	int help = 0, elem_del, elem_add, elem_find;
	cout << "Введите элемент который хотите удалить из 1-ого множества\n";
	cin >> elem_del;
	cout << "Введите элемент который хотите добавить к 1-ому множеству\n";
	cin >> elem_add;
	cout << "Введите элемент который хотите найти в 1-ом множестве\n";
	cin >> elem_find;

	system("cls");
	cout << s1 << "\n";
	s1.del(elem_del);
	s1.add(elem_add);
	cout << s1 << "\n";

	if ((0 <= elem_del <= n1) && s3.belong(elem_del) == true) cout << "Удаленный элемент " << elem_del << "\n";
	if (elem_del > n1 || elem_del < 0 )cout << "Элемент который необходимо удалить выходит за рамки множества\n";
	if (s3.belong(elem_del) == false && (0 <= elem_del <= n1)) cout << "Удаляемого элемента нет внутри множества\n";

	if (0 <= elem_add <= n1)cout << "Добавленный элемент " << elem_add << "\n";
	else cout << "Элемент который необходимо добавить" << elem_add << " выходит за рамки множества\n";

	if (s1.belong(elem_find) == true) cout << "Элемент " << elem_find << " найден \n";
	else cout << "Элемент " << elem_find << " не найден \n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
}
