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
//	* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//	* 返回Interval类，start代表汪仔最少做对了多少道题，end代表汪仔最多做对了多少道题。
//	* @param n int整型 选择题总数
//	* @param k int整型 朋友做对的题数
//	* @param str1 string字符串 长度为n只包含ABCD的字符串，其中第i个代表汪仔第i题做出的选择
//	* @param str2 string字符串 长度为n只包含ABCD的字符串，其中第i个代表朋友第i题做出的选择
//	* @return Interval类
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