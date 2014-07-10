#include <iostream>
#include <assert.h>
using namespace std;

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

void reverseList(ListNode** pHead){
	assert(pHead != NULL&&*pHead != NULL);
	ListNode *pre = NULL;
	ListNode *ptr = *pHead;
	ListNode *pro = (*pHead)->m_pNext;

	while ( ptr != NULL ) {
		ptr->m_pNext = pre;
		pre = ptr;
		ptr = pro;
		if (pro!=NULL){
			pro = pro->m_pNext;
		}
	}

	*pHead = pre;
}

void Output(ListNode** pHead){
	assert(pHead != NULL&&*pHead != NULL);
	ListNode *ptr = *pHead;
	while ( ptr != NULL ) {
		cout << ptr->m_nKey << endl;
		ptr = ptr->m_pNext;
	}
}

void reOutput(ListNode** pHead){
	assert(pHead != NULL&&*pHead != NULL);
	reverseList(pHead);
	Output(pHead);
	reverseList(pHead);
}

int main()
{
	ListNode** m_pHead=new ListNode *;
	ListNode *p = new ListNode;
	p->m_nKey = 1;
	p->m_pNext = NULL;
	*m_pHead = p;
	//cout << (*m_pHead)->m_nKey;
	for (int i = 2; i < 10; i ++) {
		p->m_pNext = new ListNode;
		p->m_pNext->m_nKey = i;
		p->m_pNext->m_pNext = NULL;
		p = p->m_pNext;
	}
	reOutput(m_pHead);
	return 0;
}