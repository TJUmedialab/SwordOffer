// the last k-th node in a list

#include <iostream>
#include <assert.h>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* theLastKthNode(ListNode* head, int k){
	if ( head == NULL ) {
		return NULL;
	}

	ListNode* p = head;
	ListNode* pre = NULL;
	k--;
	while (k--) {
		p = p->m_pNext;
		if ( p == NULL ) {
			return NULL;
		}
	}
	pre = head;
	while ( p->m_pNext != NULL ) {
		p = p->m_pNext;
		pre = pre->m_pNext;
	}
	return pre;
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

	cout << theLastKthNode(*m_pHead, 9)->m_nValue << endl;
	return 0;
}
