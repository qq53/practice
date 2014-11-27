/// \file ConstructBinaryTree.cpp
/*
  ------------------------------------
  Create date : 2014-11-26 00:59
  Modified date: 2014-11-27 23:42
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>

#include "../libs/BinaryTree.cpp"

#include "../libs/myException.cpp"

using namespace std;

void Test(int *, int *, int);

int main(){
	const int length = 8;
	int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
	int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

	Test(preorder, inorder, length);	

	return 0;
}

pBinaryTreeNode ConstructRoot(int *startPreorder, int *endPreorder,
		int *startInorder, int *endInorder){

	pBinaryTreeNode root = new BinaryTreeNode();
	root->nValue = startPreorder[0];
	root->pLeft = root->pRight = NULL;

	if(startPreorder == endPreorder){
		if(startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
			throw myException("Invalid Input");
	}

	int *p;
	for(p = startInorder; p <= endInorder; ++p){
		if(*p == root->nValue)
			break;
	}
	if(p > endInorder)
		throw myException("Invalid Input");
	
	int preLen = p - startInorder;
	if(preLen > 0){
		root->pLeft = ConstructRoot(startPreorder + 1, startPreorder + preLen,
				startInorder, p - 1);
	}
	if(p < endInorder){
		root->pRight = ConstructRoot(startPreorder + preLen + 1, endPreorder,
				p + 1, endInorder);
	}

	return root;
}

pBinaryTreeNode Construct(int *preorder, int *inorder, int length){
	if(preorder == NULL || inorder == NULL || length <= 0)
		return NULL;

	return ConstructRoot(preorder, preorder + length - 1,
			inorder, inorder + length - 1);
}

void Test(int *preorder, int *inorder, int length){
	cout << "The preorder is: ";
	for(int i = 0; i < length; ++i)
		cout << preorder[i] << " ";
	cout << endl;

	cout << "The inorder is: ";
	for(int i = 0; i < length; ++i)
		cout << inorder[i] << " ";
	cout << endl;

	try{
		pBinaryTreeNode root = Construct(preorder, inorder, length);
		PrintBinaryTree(POSTORDER, root);
	}catch(myException &e){
		cout << e.what() << endl;
	}
}
