#include <iostream>
using namespace std;

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

int main()
{

	system("pause");
	return 0;
}