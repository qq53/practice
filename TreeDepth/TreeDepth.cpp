/// \file TreeDepth.cpp
/*
  ------------------------------------
  Create date : 2015-02-05 22:59
  Modified date: 2015-02-05 23:05
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include "../libs/myException.cpp"
#include "../libs/BinaryTree.cpp"

using namespace std;

int TreeDepth(BinaryTreeNode *root){
	if(root == NULL)
		return 0;

	int left = TreeDepth(root->pLeft);
	int right = TreeDepth(root->pRight);

	int depth = left > right ? left : right;

	return depth + 1;
}

int main(){
	char preOrder[] = "123####4##";

	try{
		BinaryTreeNode *root = CreateBinaryTree(preOrder);
		cout << TreeDepth(root) << endl;
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
