/// \file ConvertBinarySearchTreeToDoubleList.cpp
/*
  ------------------------------------
  Create date : 2015-01-27 20:34
  Modified date: 2015-01-28 01:49
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include "../libs/myException.cpp"
#include "../libs/BinaryTree.cpp"

using namespace std;


/*  下面是一棵搜索二叉书
 *    4
 *  2   6
 *1  3 5  7
 *  你需要转换成双向有序链表 1<->2<->3....<->7
 */

BinaryTreeNode *pPre = NULL;

void TreeToListAdjust(BinaryTreeNode *pNode){
	if(pNode){
		TreeToListAdjust(pNode->pLeft);
		pNode->pLeft = pPre;
		if(pPre)
			pPre->pRight = pNode;
		pPre = pNode;
		TreeToListAdjust(pNode->pRight);
	}
}

BinaryTreeNode *TreeToList(BinaryTreeNode *pNode){
	if(!pNode)
		throw myException("empty tree");

	TreeToListAdjust(pNode);
	while(pNode->pLeft)
		pNode = pNode->pLeft;
	return pNode;
}

void PrintTreeList(BinaryTreeNode *pNode){
	while(pNode){
		cout << pNode->cValue << " pre: ";
		if(pNode->pLeft)
			cout << pNode->pLeft->cValue;
		cout << " behind: ";
		if(pNode->pRight)
			cout << pNode->pRight->cValue;
		cout << endl;
		pNode = pNode->pRight;
	}
}

int main(){
	char preorder[] = "421##3##65##7##";
	
	try{
		BinaryTreeNode *root = CreateBinaryTree(preorder);
		BinaryTreeNode *list = TreeToList(root);
		PrintTreeList(list);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
