#include <iostream>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_nNext;
};

//判断一个链表中是否存在环
//pSlow每次移动一步，pFast每次移动两步，若链表存在环，则pFast总会与pSlow相遇
ListNode* MeetingNode(ListNode* pHead)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}

	ListNode* pSlow = pHead->m_nNext;
	if (pSlow == nullptr)
	{
		return nullptr;
	}

	ListNode* pFast = pSlow->m_nNext;
	while (pFast != nullptr && pSlow != nullptr)
	{
		if (pFast == pSlow)
		{
			return pFast;
		}

		pSlow = pSlow->m_nNext;
		pFast = pFast->m_nNext;

		if (pFast != nullptr)
		{
			pFast = pFast->m_nNext;
		}
	}
	return nullptr;
}

//当得到链表中存在环的时候，寻找环的入口节点
//用一个指针首先移动环节点的步数，之后两个指针一起移动，当他们第一次相遇的时候，即为环的入口节点
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	ListNode* meetingNode = MeetingNode(pHead);
	if (meetingNode == nullptr)
	{
		return nullptr;
	}

	//得到环中节点的数目
	int nodesInLoop = 1;
	ListNode* pNode1 = meetingNode;
	while (pNode1->m_nNext != meetingNode)
	{
		pNode1 = pNode1->m_nNext;
		nodesInLoop += 1;
	}

	//先移动pNode1，次数为环中节点的数目
	pNode1 = pHead;
	for (int i = 0; i < nodesInLoop; i++)
	{
		pNode1 = pNode1->m_nNext;
	}

	//再移动pNode1和pNode2
	ListNode* pNode2 = pHead;
	while (pNode1 != pNode2)
	{
		pNode1 = pNode1->m_nNext;
		pNode2 = pNode2->m_nNext;
	}
	return pNode1;

}

int main()
{

	system("pause");
	return 0;
}