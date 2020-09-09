#include <iostream>
using namespace std;

bool matchCore(char* str, char* pattern)
{
	if (*str == '\0' && *pattern == '\0')
	{
		return true;
	}

	if (*str != '\0' && *pattern == '\0')
	{
		return false;
	}

	if (*(pattern + 1) == '*')
	{
		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
		{
			//move on the next state,//stay on the current state,//ignore a '*'
			return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
		}
		else
		{
			//ignore a '*'
			return matchCore(str, pattern + 2);
		}
	}

	if (*str == *pattern || (*pattern == '.' && *str != '\0'))
	{
		return matchCore(str + 1, pattern + 1);
	}

	return false;
}

bool match(char* str, char* pattern)
{
	if (str == nullptr || pattern == nullptr)
	{
		return false;
	}

	return matchCore(str, pattern);
}

int main()
{
	char* str = "abc";
	char* pattern1 = "a.c";
	char* pattern2 = "ab*bc*c";
	char* pattern3 = "ab.c";
	char* pattern4 = "abax*c";

	cout << "pattern1:" << match(str, pattern1) << endl;
	cout << "pattern1:" << match(str, pattern2) << endl;
	cout << "pattern1:" << match(str, pattern3) << endl;
	cout << "pattern1:" << match(str, pattern4) << endl;

	system("pause");
	return 0;
}