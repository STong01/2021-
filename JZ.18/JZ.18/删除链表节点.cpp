#include <iostream>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

//��O(1)ʱ����ɾ������ڵ�
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	if (!pListHead || !pToBeDeleted)
	{
		return;
	}
	//Ҫɾ���Ľڵ㲻��β�ڵ�
	if (pToBeDeleted->m_pNext != nullptr)
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = nullptr;
	}

	//����ֻ��һ���ڵ㣬ɾ��ͷ�ڵ㣨Ҳ��β�ڵ㣩
	else if (*pListHead == pToBeDeleted)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		*pListHead = nullptr;
	}

	//�������ж���ڵ㣬ɾ��β�ڵ�
	else
	{
		ListNode* pNode = *pListHead;
		while (pNode->m_pNext != pToBeDeleted)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = nullptr;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

//ɾ���������ظ��Ľڵ�
void DeleteDuplication(ListNode** pHead)
{
	if (pHead == nullptr || *pHead == nullptr)
	{
		return;
	}

	ListNode* pPreNode = nullptr;
	ListNode* pNode = *pHead;
	while (pNode != nullptr)
	{
		ListNode* pNext = pNode->m_pNext;
		bool needDelete = false;
		if (pNext != nullptr && pNext->m_nValue == pNode->m_nValue)
		{
			needDelete = true;
		}
		if (!needDelete)
		{
			pPreNode = pNode;
			pNode = pNode->m_pNext;
		}
		else
		{
			int value = pNext->m_nValue;
			ListNode* pToBeDel = pNode;
			while (pToBeDel != nullptr && pToBeDel->m_nValue == value)
			{
				pNext = pToBeDel->m_pNext;

				delete pToBeDel;
				pToBeDel = nullptr;

				pToBeDel = pNext;
			}
			if (pToBeDel == nullptr)
			{
				*pHead = pNext;
			}
			else
			{
				pPreNode->m_pNext = pNext;
			}
			pNode = pNext;
		}
	}
}

int main()
{

	system("pause");
	return 0;
}