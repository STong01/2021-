#include <iostream>
using namespace std;

int main1()
{
	int a[] = { 1, 2, 6, 4, 5 };
	int *p = a + 1;
	int s = ++(*p);
	s = s + (*++p);

	int m = 0;
	int n = 1;
	int k = 2;

	int m1 = m++;
	int n1 = n--;
	int k1 = k++;

	int m2 = ++m;
	int n2 = --n;
	int k2 = ++k;

	int tmp = m1 || n1 && k1;
	int cur = m2 || n2 && k2;

	cout << tmp << endl;
	cout << cur << endl;
	system("pause");
	return 0;
}