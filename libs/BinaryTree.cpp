/// \file BinaryTree.cpp
/*
  ------------------------------------
  Create date : 2014-11-26 09:23
  Modified date: 2015-01-20 05:14
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>

#include "BinaryTree.h"

void PrintBinaryRoot(BT_PRINT m, BinaryTreeNode* root){
	if( m == PREORDER)
		std::cout << root->cValue << " ";

	if(root->pLeft != NULL)
		PrintBinaryRoot(m, root->pLeft);

	if( m == INORDER)
		std::cout << root->cValue << " ";

	if(root->pRight != NULL)
		PrintBinaryRoot(m, root->pRight);

	if( m == POSTORDER)
		std::cout << root->cValue << " ";
}

void PrintBinaryTree(BT_PRINT m, BinaryTreeNode* root){
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

char *array = NULL;

BinaryTreeNode *CreateTree(){
	if(array == NULL)
		throw myException("create binarytree fail");
	if(*array == '#')
		return NULL;

	BinaryTreeNode *root = new BinaryTreeNode;
	root->cValue = *array;
	root->pLeft = CreateBinaryTree(++array);
	root->pRight = CreateBinaryTree(++array);
	return root;
}

BinaryTreeNode *CreateBinaryTree(char *arr){
	array = arr;
	return CreateTree();
}
