/// \file KthNodeFromEnd.cpp
/*
  ------------------------------------
  Create date : 2015-01-18 03:51
  Modified date: 2015-02-04 01:09
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include "../libs/myException.cpp"
#include "../libs/ListNode.cpp"

using namespace std;

//采用2个指针 快慢指针来解决,两个指针间隔n,当快指针到尾时,慢指针就是倒数n结点的指针
void FindKthToTail(ListNode *pHead, int n){
	if(pHead == NULL || n <= 0)
		throw myException("FindKthToTail fail");

	ListNode *pAhead = pHead;
	ListNode *pBehind = pAhead;

	for(int i = 0; i < n - 1; ++i){
		pAhead = pAhead->m_pNext;
		if(pAhead == NULL){
			cout << "list too short" << endl;
			return;
		}
	}

	while(pAhead->m_pNext != NULL){
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}

	cout << "Find this ListNode value: " << pBehind->m_nValue << endl;
}

int main(){
	int array[] = {1,2,3,4,5,6};
	int len = sizeof(array)/sizeof(array[0]);

	try{
		ListNode *pHead = CreateLists(array, len);
		FindKthToTail(pHead, 3);
	}catch(myException &e){
		cout << e.what() << endl;
	}
	return 0;
}
