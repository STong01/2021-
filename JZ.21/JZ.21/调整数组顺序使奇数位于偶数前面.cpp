#include <iostream>
using namespace std;

void ReorderOddEven1(int *pData, unsigned int length)
{
	if (pData == nullptr || length == 0)
	{
		return;
	}

	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while (pBegin < pEnd)
	{
		//向后移动pBegin，直到它指向偶数
		while (pBegin < pEnd && (*pBegin & 0x1) != 0)
		{
			pBegin++;
		}

		//向前移动pEnd，直到它指向奇数
		while (pBegin < pEnd && (*pEnd & 0x1) == 0)
		{
			pEnd--;
		}

		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

void Reorder(int *pData, unsigned int length, bool(*func)(int))
{
	if (pData == nullptr || length == 0)
	{
		return;
	}

	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && !func(*pBegin))
		{
			pBegin++;
		}

		while (pBegin < pEnd && func(*pEnd))
		{
			pEnd--;
		}

		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

bool isEven(int n)
{
	return (n & 1) == 0;
}

void ReorderOddEven2(int *pData, unsigned int length)
{
	Reorder(pData, length, isEven);
}

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	ReorderOddEven1(arr, 5);

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	int btt[5] = { 5, 4, 3, 2, 1 };
	ReorderOddEven2(btt, 5);

	for (int i = 0; i < 5; i++)
	{
		cout << btt[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}