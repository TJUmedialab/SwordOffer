// judge whether A is a subtree of B
#include <iostream>
#include <assert.h>
#include <fstream>
using namespace std;

struct BinaryTreeNode
{
	int					m_nValue;
	BinaryTreeNode*		m_pLeft;
	BinaryTreeNode*		m_pRight;
	BinaryTreeNode(int m_value, BinaryTreeNode* lf = NULL, BinaryTreeNode* rt = NULL) :
		m_nValue(m_value), m_pLeft(lf), m_pRight(rt) {}
};

bool sameTreeCore(BinaryTreeNode* root1, BinaryTreeNode* root2) {
	if ( root1 == NULL && root2 == NULL ) {
		return true;
	} else if ( root1 != NULL && root2 != NULL ) {
		if ( root1->m_nValue == root2->m_nValue ) {
			return sameTreeCore(root1->m_pLeft, root2->m_pLeft) 
				&& sameTreeCore(root1->m_pRight, root2->m_pRight);
		}
	}
	else
	{
		return false;
	}
}

bool sameTree(BinaryTreeNode* root1, BinaryTreeNode* root2) {
	if (root1 == NULL || root2 == NULL) {
		return false;
	}
	bool res = false;
	if ( root1->m_nValue == root2->m_nValue ) {
		res = sameTreeCore(root1, root2);
	}
	if ( res == true ) {
		return true;
	}
	else {
		return sameTree(root1->m_pLeft, root2) 
			|| sameTree(root1->m_pRight, root2);
	}
}

int main(int argc, char* argv[])
{
	BinaryTreeNode* c1 = new BinaryTreeNode(4);
	BinaryTreeNode* c2 = new BinaryTreeNode(5);
	BinaryTreeNode* b1 = new BinaryTreeNode(5, c1, c2);
	BinaryTreeNode* b2 = new BinaryTreeNode(8);
	BinaryTreeNode* a1 = new BinaryTreeNode(5, b1, b2);

	if ( sameTree(a1, b1) ) {
		cout << "we found that subtree!\n";
	}
	return 0;
}