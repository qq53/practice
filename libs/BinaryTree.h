/// \file BinaryTree.h
/*
  ------------------------------------
  Create date : 2014-11-26 01:05
  Modified date: 2015-01-23 02:14
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/


//Print method
enum BT_PRINT{PREORDER, INORDER, POSTORDER};

typedef struct BinaryTree{
	char cValue;
	BinaryTree *pLeft;
	BinaryTree *pRight;
}BinaryTreeNode;

void PrintBinaryTree(BT_PRINT, BinaryTreeNode *root);

BinaryTreeNode *CreateBinaryTree(char *array);
