// BFS a tree

#include <iostream>
#include <deque>

using namespace std;

struct BinaryTreeNode
{
	int					m_nValue;
	BinaryTreeNode*		m_pLeft;
	BinaryTreeNode*		m_pRight;
	BinaryTreeNode(int m_value, BinaryTreeNode* lf = NULL, BinaryTreeNode* rt = NULL) :
		m_nValue(m_value), m_pLeft(lf), m_pRight(rt) {}
};

void bfs(BinaryTreeNode* root){
	deque<BinaryTreeNode*> de;
	BinaryTreeNode* pr = NULL;
	de.push_back(root);

	while ( de.size() > 0 ) {
		pr = de.front();
		de.pop_front();
		if ( pr->m_pLeft ) {
			de.push_back(pr->m_pLeft);
		}
		if (pr->m_pRight) {
			de.push_back(pr->m_pRight);
		}
		cout << pr->m_nValue << ' ';
	}
}

int main()
{
	BinaryTreeNode* c1 = new BinaryTreeNode(4);
	BinaryTreeNode* c2 = new BinaryTreeNode(3);
	BinaryTreeNode* c3 = new BinaryTreeNode(20);
	BinaryTreeNode* c4 = new BinaryTreeNode(10);
	BinaryTreeNode* b1 = new BinaryTreeNode(5, c1, c2);
	BinaryTreeNode* b2 = new BinaryTreeNode(8, c3, c4);
	BinaryTreeNode* a1 = new BinaryTreeNode(5, b1, b2);
	bfs(a1);
	return 0;
}