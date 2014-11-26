/// \file BinaryTree.h
/*
  ------------------------------------
  Create date : 2014-11-26 01:05
  Modified date: 2014-11-26 09:29
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
typedef struct BinaryTree{
	int nValue;
	BinaryTree *pLeft;
	BinaryTree *pRight;
}*pBinaryTreeNode,BinaryTreeNode;

void PrintBinaryRoot(pBinaryTreeNode);

void PrintBinaryTree(pBinaryTreeNode);
