//#include <iostream>
//using namespace std;
//
//struct Interval 
//{
//	int start;
//	int end;
//};
//
//class Solution 
//{
//public:
//	/**
//	* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//	* ����Interval�࣬start�����������������˶��ٵ��⣬end����������������˶��ٵ��⡣
//	* @param n int���� ѡ��������
//	* @param k int���� �������Ե�����
//	* @param str1 string�ַ��� ����Ϊnֻ����ABCD���ַ��������е�i���������е�i��������ѡ��
//	* @param str2 string�ַ��� ����Ϊnֻ����ABCD���ַ��������е�i���������ѵ�i��������ѡ��
//	* @return Interval��
//	*/
//	Interval solve(int n, int k, string str1, string str2) 
//	{
//		Interval str;
//		int sum = 0;
//
//		for (int i = 0; i < n; i++)
//		{
//			if (str1[i] == str2[i])
//			{
//				sum++;
//			}
//		}
//
//		if (sum > k)
//		{
//			str.end = (n - sum) + k;
//			if ((n - sum) > k)
//			{
//				str.start = 0;
//			}
//			else
//			{
//				str.start = k - (n - sum);
//			}
//		}
//		else
//		{
//			str.end = sum + ((n - sum) - (k - sum));
//			if ((n - sum) >= k)
//			{
//				str.start = 0;
//			}
//			else
//			{
//				str.start = k - (n - sum);
//			}
//		}
//		return str;
//	}
//};