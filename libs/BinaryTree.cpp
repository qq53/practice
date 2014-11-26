/// \file BinaryTree.cpp
/*
  ------------------------------------
  Create date : 2014-11-26 09:23
  Modified date: 2014-11-26 09:33
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>

#include "BinaryTree.h"

void PrintBinaryRoot(pBinaryTreeNode root){
	if(root->pLeft != NULL)
		PrintBinaryRoot(root->pLeft);
	if(root->pRight != NULL)
		PrintBinaryRoot(root->pRight);
	std::cout << root->nValue << " ";
}

void PrintBinaryTree(pBinaryTreeNode root){
	std::cout << "AfterOrder: ";
	PrintBinaryRoot(root);
	std::cout << std::endl;
}
