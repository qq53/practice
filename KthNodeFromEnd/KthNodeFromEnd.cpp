/// \file KthNodeFromEnd.cpp
/*
  ------------------------------------
  Create date : 2015-01-18 03:51
  Modified date: 2015-01-18 05:10
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include "../libs/myException.cpp"
#include "../libs/ListNode.cpp"

using namespace std;

//采用2个指针 快慢指针来解决,两个指针间隔n,当快指针到尾时,慢指针就是倒数n结点的指针
void FindKthToTail(cListNode *c_pHead, int n){
	if(c_pHead == NULL || n <= 0)
		throw myException("FindKthToTail fail");

	ListNode *pAhead = c_pHead->getHead();
	ListNode *pBehind = pAhead;

	for(int i = 0; i < n - 1; ++i){
		pAhead = c_pHead->next(pAhead);
		if(pAhead == NULL){
			cout << "list too short" << endl;
			return;
		}
	}

	while(c_pHead->next(pAhead) != NULL){
		pAhead = c_pHead->next(pAhead);
		pBehind = c_pHead->next(pBehind);
	}

	cout << "Find this ListNode value: " << c_pHead->getValue(pBehind) << endl;
}

int main(){
	cListNode *c_pListNode = new cListNode;
	int array[] = {1,2,3,4,5,6};
	int len = sizeof(array)/sizeof(array[0]);

	try{
		c_pListNode->create(array, len);
		FindKthToTail(c_pListNode, 3);
	}catch(myException &e){
		cout << e.what() << endl;
	}
	return 0;
}
