/// \file BinaryTree.cpp
/*
  ------------------------------------
  Create date : 2014-11-26 09:23
  Modified date: 2014-11-27 23:43
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>

#include "BinaryTree.h"

void PrintBinaryRoot(BT_PRINT m, pBinaryTreeNode root){
	if( m == PREORDER)
		std::cout << root->nValue << " ";

	if(root->pLeft != NULL)
		PrintBinaryRoot(m, root->pLeft);

	if( m == INORDER)
		std::cout << root->nValue << " ";

	if(root->pRight != NULL)
		PrintBinaryRoot(m, root->pRight);

	if( m == POSTORDER)
		std::cout << root->nValue << " ";
}

void PrintBinaryTree(BT_PRINT m, pBinaryTreeNode root){
	switch(m){
	case PREORDER:
		std::cout << "PreOrder: ";
		break;
	case INORDER:
		std::cout << "InOrder: ";
		break;
	case POSTORDER:
		std::cout << "PostOrder: ";
		break;
	default:
		break;
	}
	PrintBinaryRoot(m, root);
	std::cout << std::endl;
}
