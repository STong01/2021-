#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main1()
{
	int n;
	cin >> n;
	string str;
	vector<vector<string>> mp;
	for (int i = 0; i < n; i++)
	{
		while (getline(cin , str))
		{
			mp[i].push_back(str);
		}
	}

	system("pause");
	return 0;
}