#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int val;
	cin >> val;
	int n;
	cin >> n;
	int m = n;
	vector<int> num;
	int k = 0;
	int mp;

	while (m)
	{
		cin >> mp;
		num.push_back(mp);
		m--;
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (num[j] < num[j + 1])
			{
				int tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (num[i] <= val)
		{
			val = val - num[i];
		}
	}
	cout << val << endl;

	system("pause");
	return 0;
}