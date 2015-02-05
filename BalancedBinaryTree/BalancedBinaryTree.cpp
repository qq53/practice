/// \file BalancedBinaryTree.cpp
/*
  ------------------------------------
  Create date : 2015-02-05 23:06
  Modified date: 2015-02-05 23:21
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include <stdlib.h>
#include "../libs/myException.cpp"
#include "../libs/BinaryTree.cpp"

using namespace std;

bool IsBalanced(BinaryTreeNode *root, int &depth){
	if(root == NULL){
		depth = 0;
		return true;
	}

	int left, right;
	if(IsBalanced(root->pLeft, left) &&
		IsBalanced(root->pRight, right)){

		depth = left > right ? left : right;
		++depth;

		int diff = abs(left - right);
		if(diff <= 1)
			return true;
	}
	return false;
}

void IsBalanced(BinaryTreeNode *root){
	if(root == NULL)
		throw myException("empty tree");

	int depth = 0;
	if(IsBalanced(root ,depth))
		cout << "is balanced" << endl;
	else
		cout << "not balanced" << endl;
}

int main(){
	char preOrder[] = "12###";

	try{
		BinaryTreeNode *root = CreateBinaryTree(preOrder);
		IsBalanced(root);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
