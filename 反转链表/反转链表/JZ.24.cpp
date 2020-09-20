#include <iostream>
using namespace std;

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

//为防止链表断开，我们需定义3个指针，分别指向当前遍历到的节点，它的前一个节点和后一个节点
//在写链表相关问题的代码的时候，我们需注意以下三个特殊测试用例：
//1、输入的链表头指针是nullptr
//2、输入的链表只有一个节点
//3、输入的链表有多个节点
ListNode* ReverseList(ListNode* pHead)
{
	ListNode* pReversedHead = nullptr;
	ListNode* pNode = pHead;
	ListNode* pPrev = nullptr;

	while (pNode != nullptr)
	{
		ListNode* pNext = pNode->m_pNext;
		if (pNext == nullptr)
		{
			pReversedHead = pNode;
		}

		pNext->m_pNext = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReversedHead;
}

int main()
{

	system("pause");
	return 0;
}