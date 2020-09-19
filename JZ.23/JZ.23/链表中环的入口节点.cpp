#include <iostream>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_nNext;
};

//�ж�һ���������Ƿ���ڻ�
//pSlowÿ���ƶ�һ����pFastÿ���ƶ���������������ڻ�����pFast�ܻ���pSlow����
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

//���õ������д��ڻ���ʱ��Ѱ�һ�����ڽڵ�
//��һ��ָ�������ƶ����ڵ�Ĳ�����֮������ָ��һ���ƶ��������ǵ�һ��������ʱ�򣬼�Ϊ������ڽڵ�
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	ListNode* meetingNode = MeetingNode(pHead);
	if (meetingNode == nullptr)
	{
		return nullptr;
	}

	//�õ����нڵ����Ŀ
	int nodesInLoop = 1;
	ListNode* pNode1 = meetingNode;
	while (pNode1->m_nNext != meetingNode)
	{
		pNode1 = pNode1->m_nNext;
		nodesInLoop += 1;
	}

	//���ƶ�pNode1������Ϊ���нڵ����Ŀ
	pNode1 = pHead;
	for (int i = 0; i < nodesInLoop; i++)
	{
		pNode1 = pNode1->m_nNext;
	}

	//���ƶ�pNode1��pNode2
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