#include <iostream>
#include <vector>
using namespace std;

//√∞≈›≈≈–Ú
vector<int> bubbleSort(vector<int> arr)
{
	int len = arr.size();
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return arr;
}

//—°‘Ò≈≈–Ú
vector<int> selsectionSort(vector<int> arr)
{
	int len = arr.size();
	int minIndex, tmp;
	for (int i = 0; i < len - 1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		tmp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = tmp;
	}
	return arr;
}

int main()
{

	vector<int> arr = { 1, 3, 4, 6, 7, 8, 9, 9, 10, 23, 45, 78 };
	vector<int> btt = { 3, 4, 5, 6, 7, 8, 19, 23, 45, 123, 141, 21, 24, 56, 21 };

	arr = bubbleSort(arr);
	btt = selsectionSort(btt);
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < btt.size(); i++)
	{
		cout << btt[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}