#include <iostream>
using namespace std;

int partion(int* arr, int m, int n)
{
	int key = arr[m];
	while (m < n)
	{
		while (m < n && arr[n] > key)
		{
			--n;
		}
		arr[m] = arr[n];
		while (m < n && arr[m] < key)
		{
			++m;
		}
		arr[n] = arr[m];
	}
	arr[m] = key;
	return m;
}

void QSORT(int* arr, int m, int n)
{
	if (m < n)
	{
		int mid = partion(arr, m, n);
		QSORT(arr, m, mid - 1);
		QSORT(arr, mid + 1, n);
	}
}

void qsort1(int* arr, int len)
{
	QSORT(arr, 0, len - 1);
}


void test()
{
	int arr[] = { 34, 5, 623, 4, 614, 41, 56, 778 };
	int len = sizeof(arr) / sizeof(arr[0]);
	qsort1(arr, len);
	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl; 
}

int main()
{
	test();
	system("pause");
	return 0;
}

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

//������������ķ���
//���Ƚ��������һ�ߣ�ÿ����һ���ڵ㣬������ +1
//֮���ٽ��������һ���ҳ���n - k + 1���ڵ������������Ҫ�Ľڵ�

//����һ������ķ���
//�����õ�һ��ָ����ǰ��k-1�����ڶ���ָ�뱣�ֲ�����Ȼ������ָ��һ��ʼ����������ָ�뱣��k-1�ľ��룻
//���Ǹ�����һ��ָ�뵽��βָ���ʱ�򣬵ڶ���ָ������ָ������k���ڵ�

ListNode* FindKthToTail1(ListNode* pListHead, unsigned int k)
{
	ListNode* pAhead = pListHead;
	ListNode* pBehead = nullptr;

	for (unsigned int i = 0; i < k - 1; ++i)
	{
		pAhead = pAhead->m_pNext;
	}

	pBehead = pListHead;

	while (pAhead->m_pNext != nullptr)
	{
		pAhead = pAhead->m_pNext;
		pBehead = pBehead->m_pNext;
	}

	return pBehead;
}

//³���Դ���
ListNode* FindKthToTail2(ListNode* pListHead, unsigned int k)
{
	if (pListHead == nullptr || k == 0)
	{
		return nullptr;
	}

	ListNode* pAhead = pListHead;
	ListNode* pBehead = nullptr;

	for (unsigned int i = 0; i < k - 1; i++)
	{
		if (pAhead->m_pNext != nullptr)
		{
			pAhead = pAhead->m_pNext;
		}
		else
		{
			return nullptr;
		}
	}

	pBehead = pListHead;
	while (pAhead->m_pNext != nullptr)
	{
		pAhead = pAhead->m_pNext;
		pBehead = pBehead->m_pNext;
	}
	return pBehead;
}

