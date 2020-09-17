#include <iostream>
using namespace std;

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

int main()
{

	system("pause");
	return 0;
}