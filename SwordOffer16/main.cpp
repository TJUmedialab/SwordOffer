// the last k-th node in a list

#include <iostream>
#include <assert.h>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* reverseList(ListNode* head) {
	if ( head == NULL ) {
		return NULL;
	}

	ListNode *p = head;
	ListNode *pre = NULL;
	ListNode *curp = NULL;

	while ( p != NULL ) {
		curp = p;
		p = p->m_pNext;
		curp->m_pNext = pre;
	}

	return curp;
}

int main(int argc, char* argv[])
{
	ListNode** m_pHead = new ListNode *;
	ListNode *p = new ListNode;
	p->m_nValue = 1;
	p->m_pNext = NULL;
	*m_pHead = p;
	ListNode* deleteTarget = p;
	//cout << (*m_pHead)->m_nKey;
	for (int i = 2; i < 10; i++) {
		p->m_pNext = new ListNode;
		p->m_pNext->m_nValue = i;
		p->m_pNext->m_pNext = NULL;
		p = p->m_pNext;
	}

	cout << reverseList(*m_pHead)->m_nValue << endl;
	return 0;
}