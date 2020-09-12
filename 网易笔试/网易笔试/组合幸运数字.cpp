#include <iostream>
#include <vector>
using namespace std;

double test3(vector<int> nums)
{
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
	}



	return 0;
}

int main()
{
	int n;
	vector<int> nums;
	while (cin >> n)
	{
		nums.push_back(n);
	}

	int leg = nums.size();

	for (int i = 0; i < leg; i++)
	{
		cout << nums[i];
	}

	system("pause");
	return 0;
}