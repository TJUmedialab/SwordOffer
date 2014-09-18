// generate a mirrored binary tree

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

void mirrorTree(BinaryTreeNode* root){
	if ( root != NULL ) {
		BinaryTreeNode* p = root->m_pLeft;
		root->m_pLeft = root->m_pRight;
		root->m_pRight = p;
		mirrorTree(root->m_pLeft);
		mirrorTree(root->m_pRight);
	}
}

int main(int argc, char* argv[])
{
	BinaryTreeNode* c1 = new BinaryTreeNode(4);
	BinaryTreeNode* c2 = new BinaryTreeNode(3);
	BinaryTreeNode* b1 = new BinaryTreeNode(5, c1, c2);
	BinaryTreeNode* b2 = new BinaryTreeNode(8);
	BinaryTreeNode* a1 = new BinaryTreeNode(5, b1, b2);

	mirrorTree(a1);
	return 0;
}