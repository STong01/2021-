#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution 
{
public:
	/**
	* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	* ����һ���ַ�������ʾԭ�ġ�
	* @param s1 string�ַ���vector N*N��01���󣬱�ʾ����ֽ��0��ʾ͸����1��ʾͿ��
	* @param s2 string�ַ���vector �ַ����󣬱�ʾ����
	* @return string�ַ���
	*/
	vector<string> change(vector<string> s)
	{
		vector<string> sp = s;
		for (int j = 0; j < s[0].length(); j++)
		{
			string s1;
			for (int i = s.size() - 1; i >= 0; i--)
			{
				s1 += s[i][j];
			}
			sp[j] = s1;
		}
		return sp;
	}

	string rotatePassword(vector<string>& s1, vector<string>& s2) 
	{
		string str;
		vector<string> sp1 = s1;
		vector<string> sp2 = change(sp1);
		vector<string> sp3 = change(sp2);
		vector<string> sp4 = change(sp3);

		for (int i = 0; i < sp1.size(); i++)
		{
			for (int j = 0; j < sp1[0].length(); j++)
			{
				if (sp1[i][j] == '0')
				{
					str += s2[i][j];
				}
			}
		}
		for (int i = 0; i < sp2.size(); i++)
		{
			for (int j = 0; j < sp2[0].length(); j++)
			{
				if (sp2[i][j] == '0')
				{
					str += s2[i][j];
				}
			}
		}		
		for (int i = 0; i < sp3.size(); i++)
		{
			for (int j = 0; j < sp3[0].length(); j++)
			{
				if (sp3[i][j] == '0')
				{
					str += s2[i][j];
				}
			}
		}		
		
		for (int i = 0; i < sp4.size(); i++)
		{
			for (int j = 0; j < sp4[0].length(); j++)
			{
				if (sp4[i][j] == '0')
				{
					str += s2[i][j];
				}
			}
		}
		return str;
	}
};

int main()
{

	vector<string> s1 = { "1101", "1010", "1111", "1110" };
	vector<string> s2 = { "ABCD", "EFGH", "IJKL", "MNPQ" };

	Solution m;

	string str = m.rotatePassword(s1, s2);
	cout << str << endl;
	system("pause");
	return 0;
}