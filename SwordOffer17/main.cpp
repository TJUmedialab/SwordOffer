// merge two sorted list into a big sorted list

#include <iostream>
#include <assert.h>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* mergeSortedList(ListNode* head1, ListNode* head2){
	ListNode *p1 = head1;
	ListNode *p2 = head2;
	ListNode *newhead = NULL;
	ListNode *p = NULL;

	while ( p1 != NULL && p2 != NULL ) {
		if ( p1->m_nValue < p2->m_nValue ) {
			if (newhead == NULL) {
				newhead = p1;
				p = newhead;
			}
			else {
				p->m_pNext = p1;
			}	
			p1 = p1->m_pNext;
		}
		else {
			if (newhead == NULL) {
				newhead = p2;
				p = newhead;
			}
			else {
				p->m_pNext = p2;
			}
			p2 = p2->m_pNext;
		}
		
	}

	if ( p1 != NULL ) {
		p->m_pNext = p1;
	}

	if ( p2 != NULL ) {
		p->m_pNext = p2;
	}
	return newhead;
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

	ListNode *a = new ListNode;
	a->m_nValue = 10;
	a->m_pNext = NULL;
	cout << mergeSortedList(*m_pHead, a)->m_nValue << endl;
	return 0;
}