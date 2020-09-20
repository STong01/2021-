#include <iostream>
using namespace std;

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

//Ϊ��ֹ����Ͽ��������趨��3��ָ�룬�ֱ�ָ��ǰ�������Ľڵ㣬����ǰһ���ڵ�ͺ�һ���ڵ�
//��д�����������Ĵ����ʱ��������ע�����������������������
//1�����������ͷָ����nullptr
//2�����������ֻ��һ���ڵ�
//3������������ж���ڵ�
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