#include <iostream>
using namespace std;

void merge(int A[], int m, int B[], int n)
{
	int i = m - 1;
	int j = n - 1;
	int cur = m + n - 1;

	while (i >= 0 || j >= 0)
	{
		if ((i >= 0 && A[i] >= B[j]) || j < 0)
		{
			A[cur--] = A[i--];
		}
		else
		{
			A[cur--] = B[j--];
		}
	}
}

int main()
{
	int A[10] = { 1, 3, 5, 7, 9 };
	int B[] = { 2, 4, 6, 8, 10 };
	merge(A, 5, B, 5);

	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << endl;
	}

	system("pause");
	return 0;
}