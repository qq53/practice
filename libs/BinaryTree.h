/// \file BinaryTree.h
/*
  ------------------------------------
  Create date : 2014-11-26 01:05
  Modified date: 2014-11-27 18:11
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/


//Print method
enum BT_PRINT{PREORDER, INORDER, POSTORDER};

typedef struct BinaryTree{
	int nValue;
	BinaryTree *pLeft;
	BinaryTree *pRight;
}*pBinaryTreeNode,BinaryTreeNode;

void PrintBinaryRoot(BT_PRINT, pBinaryTreeNode);

void PrintBinaryTree(BT_PRINT, pBinaryTreeNode);
