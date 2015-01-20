/// \file MirrorOfBinaryTree.cpp
/*
  ------------------------------------
  Create date : 2015-01-20 21:11
  Modified date: 2015-01-20 21:31
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include "../libs/myException.cpp"
#include "../libs/BinaryTree.cpp"

using namespace std;

void MirrorOfBinaryTree(BinaryTreeNode *root){
	if(root == NULL)
		return;
	if(root->pLeft == root->pRight && root->pLeft == NULL)
		return;

	BinaryTreeNode *temp = root->pLeft;
	root->pLeft = root->pRight;
	root->pRight = temp;

	if(root->pLeft)
		MirrorOfBinaryTree(root->pLeft);
	if(root->pRight)
		MirrorOfBinaryTree(root->pRight);
}

int main(){
	char array[] = "123##4##56##7##";
/*
 *				1
 *		2				5
 *	3		4		6		7
 */
	try{
		BinaryTreeNode *root = CreateBinaryTree(array);
		MirrorOfBinaryTree(root);
		PrintBinaryTree(PREORDER, root);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
