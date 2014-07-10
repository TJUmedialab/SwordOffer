#include <iostream>
#include <assert.h>
#include <fstream>
using namespace std;

struct BinaryTreeNode
{
	int					m_nValue;
	BinaryTreeNode*		m_pLeft;
	BinaryTreeNode*		m_pRight;
	BinaryTreeNode(int m_value, BinaryTreeNode* lf = NULL, BinaryTreeNode* rt= NULL):
		m_nValue(m_value), m_pLeft(lf), m_pRight(rt) {}
};

BinaryTreeNode* getBackwardTree(int* forwardSeq, int* middleSeq, int length){
	if (length == 0){
		return NULL;
	}
	if ( length == 1 ){
		BinaryTreeNode* cur = new BinaryTreeNode(forwardSeq[0]);
		return cur;
	}
	int forwardFirst = forwardSeq[0];
	int pos = 0;
	for (int i = 0; i < length; i ++) {
		if ( middleSeq[i] == forwardFirst ){
			pos = i;
			break;
		}
	}
	if (middleSeq[pos] != forwardFirst){
		cerr << "The input arrays cannot build a binary treeeeeeeeeeeeeee\n";
		exit(0);
	}
	BinaryTreeNode* leftsub = NULL;
	BinaryTreeNode* rightsub = NULL;
	if ( pos == 0 ){
		rightsub = getBackwardTree(forwardSeq + 1, middleSeq + 1, length - 1);
	}else if ( pos == length - 1 ){
		leftsub = getBackwardTree(forwardSeq + 1, middleSeq, length - 1);
	} else{
		leftsub = getBackwardTree(forwardSeq + 1, middleSeq, pos);
		rightsub = getBackwardTree(forwardSeq + 1 + pos, middleSeq + 1 + pos, length - 1 - pos);
	}

	BinaryTreeNode* cur = new BinaryTreeNode(forwardFirst, leftsub, rightsub);
	return cur;
}
static int cc = 0;
void outputBackwardSeq(BinaryTreeNode* root){
	cc++;
	if ( root != NULL ){
		outputBackwardSeq(root->m_pLeft);
		outputBackwardSeq(root->m_pRight);
		cout << root->m_nValue << endl;
	}
	return;
}

int main()
{
	int count;
	int *forwardSeq = NULL;
	int *middleSeq = NULL;
	int *backwardSeq = NULL;
	ifstream dataFile("data.txt");
	while (dataFile >> count && count != 0){
		forwardSeq = new int[count];
		middleSeq = new int[count];
		for (int i = 0; i < count; i ++) {
			dataFile >> forwardSeq[i];
		}
		for (int i = 0; i < count; i++) {
			dataFile >> middleSeq[i];
		}
		BinaryTreeNode* root = getBackwardTree(forwardSeq, middleSeq, count);
		outputBackwardSeq(root);
	}
	return 0;
}