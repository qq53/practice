/// \file SequenceOfBinaryTree.cpp
/*
  ------------------------------------
  Create date : 2015-01-23 02:07
  Modified date: 2015-01-23 02:17
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include <queue>
#include "../libs/myException.cpp"
#include "../libs/BinaryTree.cpp"

using namespace std;

void SequenceOfBinaryTree(BinaryTreeNode *root){
	queue<BinaryTreeNode*> queue;
	queue.push(root);

	while(!queue.empty()){
		BinaryTreeNode *pNode = queue.front();
		queue.pop();
		cout << pNode->cValue << " ";
		if(pNode->pLeft)
			queue.push(pNode->pLeft);
		if(pNode->pRight)
			queue.push(pNode->pRight);
	}
}

int main(){
	char preorder[] = "124##5##36##7##";
	
	try{
		BinaryTreeNode *root = CreateBinaryTree(preorder);
		SequenceOfBinaryTree(root);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
