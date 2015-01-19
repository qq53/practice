/// \file SubstructureInTree.cpp
/*
  ------------------------------------
  Create date : 2015-01-20 04:27
  Modified date: 2015-01-20 05:17
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include "../libs/myException.cpp"
#include "../libs/BinaryTree.cpp"

using namespace std;

bool SameTree(BinaryTreeNode *root1, BinaryTreeNode *root2){
	if(root2 == NULL)
		return true;
	if(root1 == NULL)
		return false;
	if(root1->cValue != root2->cValue)
		return false;
	else
		return SameTree(root1->pLeft, root2->pLeft) && SameTree(root1->pRight, root2->pRight);
}

bool HasSubtree(BinaryTreeNode *root1, BinaryTreeNode *root2){
	if(root1 == NULL || root2 == NULL){
		return false;
	}else{
		bool result;
		if(root1->cValue == root2->cValue)
			result = SameTree(root1, root2);
		if(!result)
			HasSubtree(root1->pLeft, root2);
		if(!result)
			HasSubtree(root1->pRight, root2);
		return result;
	}
}

int main(){
	char array1[] = "12##3##";
	char array2[] = "1#2##";

	try{
		BinaryTreeNode *root1 = CreateBinaryTree(array1);
		BinaryTreeNode *root2 = CreateBinaryTree(array2);

		if( HasSubtree(root1, root2) == true )
			cout << "find subtree" << endl;
		else
			cout << "not find subtree" << endl;
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
