/// \file ReverseList.cpp
/*
  ------------------------------------
  Create date : 2015-01-18 05:04
  Modified date: 2015-02-04 01:14
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include "../libs/myException.cpp"
#include "../libs/ListNode.cpp"

using namespace std;

ListNode* ReverseList(ListNode *pHead){
	if(pHead == NULL)
		throw myException("null pointer");

	ListNode *pNewHead = NULL;
	ListNode *pNode = pHead->m_pNext;
	ListNode *pPrev = NULL;

	if(pNode == NULL)
		throw myException("empty lists");
	while(pNode != NULL){
		ListNode *pNext = pNode->m_pNext;

		if(pNext == NULL)
			pNewHead = pNode;

		pNode->m_pNext = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}

	return pNewHead;
}

int main(){
	int array[] = {1,2,3,4,5,6};
	int len = sizeof(array)/sizeof(array[0]);

	try{
		ListNode* pHead = CreateLists(array, len);
		pHead = ReverseList(pHead);
		PrintLists(pHead);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
