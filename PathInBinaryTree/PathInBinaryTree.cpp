/// \file PathInBinaryTree.cpp
/*
  ------------------------------------
  Create date : 2015-01-24 00:56
  Modified date: 2015-01-24 01:40
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include <vector>
#include "../libs/myException.cpp"
#include "../libs/BinaryTree.cpp"

using namespace std;

void FindPath(BinaryTreeNode *root, int expectedSum, vector<char> &path, int &sums){
	sums += root->cValue - '0';
	path.push_back(root->cValue);

	if(sums == expectedSum && root->pLeft == NULL && root->pRight == NULL){
		cout << "path: ";
		vector<char>::iterator iter = path.begin();
		for(; iter != path.end(); ++iter)
			cout << *iter << " ";
		cout << endl;
	}

	if(root->pLeft)
		FindPath(root->pLeft, expectedSum, path, sums);
	if(root->pRight)
		FindPath(root->pRight, expectedSum, path, sums);

	sums -= root->cValue - '0';
	path.pop_back();
}

void FindPath(BinaryTreeNode *root, int expectedSum){
	if(root == NULL)
		throw myException("wrong BinaryTree");

	vector<char> path;
	int sums = 0;
	FindPath(root, expectedSum, path, sums);
}

int main(){
	char preorder[] = "124##5##6##";

	try{
		BinaryTreeNode *root = CreateBinaryTree(preorder);
		FindPath(root, 7);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
