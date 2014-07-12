// delete a node in a list in an O(1) time
#include <iostream>
#include <assert.h>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

void deleteListNode(ListNode** m_root, ListNode* m_target){
	if ( m_root == NULL && (*m_root) == NULL ){
		cerr << "the list is empty, cannot delete any more\n";
		return;
	}
	if ( m_target == NULL ){
		cerr << "the delete target is empty, cannot delete it\n";
		return;
	}

	// the target node is the head
	if ( (*m_root) == m_target ){
		*m_root = m_target->m_pNext;
		delete m_target;
		cout << "delete the head\n";
		return;
	}

	// copy the value of next node to the target, delete the next node
	ListNode* pro = m_target->m_pNext;
	if (pro != NULL){
		m_target->m_nValue = pro->m_nValue;
		m_target->m_pNext = pro->m_pNext;
		delete pro;
		cout << "delete the target\n";
		return;
	}
	// the target node is the end of the link list
	ListNode* iters = *m_root;
	bool deleteSucess = false;
	while (iters != NULL ) {
		if (iters->m_pNext == m_target){
			deleteSucess = true;
			break;
		}
		iters = iters->m_pNext;
	}
	if ( deleteSucess ){
		iters->m_pNext = iters->m_pNext->m_pNext;
		cout << "the target is in the end of the link list\n";
	}
	else {
		cerr << "dear, the target is not in this list\n";
		return;
	}
	
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
		if ( i == 9 ){
			deleteTarget = p->m_pNext;
		}
		p->m_pNext->m_pNext = NULL;
		p = p->m_pNext;
	}

	deleteListNode(m_pHead, deleteTarget);
}