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

//遍历两遍链表的方法
//首先将链表遍历一边，每经过一个节点，计数器 +1
//之后再将链表遍历一边找出第n - k + 1个节点就是我们所需要的节点

//遍历一遍链表的方法
//首先用第一个指针向前走k-1步，第二个指针保持不动，然后两个指针一起开始遍历，两个指针保持k-1的距离；
//到那个当第一个指针到达尾指针的时候，第二个指针正好指向倒数第k个节点

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

//鲁棒性代码
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

