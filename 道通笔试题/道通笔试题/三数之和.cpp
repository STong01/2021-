//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	vector<int> mat;
//	int n;
//	int m = 0;
//
//	do{
//		cin >> n;
//		mat.push_back(n);
//		m++;
//	} while (getchar() != '\n');
//
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < n - i - 1; j++)
//		{
//			if (mat[j] > mat[j + 1])
//			{
//				int tmp = mat[j];
//				mat[j] = mat[j + 1];
//				mat[j + 1] = tmp;
//			}
//		}
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = i + 1; j < m; j++)
//		{
//			for (int k = j + 1; k < m; k++)
//			{
//				if ((mat[i] + mat[j] + mat[k]) == 0 && i != j && j != k && i != k)
//				{
//					cout << mat[i] << " " << mat[j] << " " << mat[k] << endl;
//				}
//			}
//		}
//	}
//
//	system("pause");
//	return 0;
//}