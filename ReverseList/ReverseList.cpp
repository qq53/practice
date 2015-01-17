/// \file ReverseList.cpp
/*
  ------------------------------------
  Create date : 2015-01-18 05:04
  Modified date: 2015-01-18 05:32
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include "../libs/myException.cpp"
#include "../libs/ListNode.cpp"

using namespace std;

void ReverseList(cListNode *c_pList){
	if(c_pList == NULL)
		throw myException("null pointer");

	ListNode *pNewHead = NULL;
	ListNode *pNode = c_pList->next(c_pList->getHead());
	ListNode *pPrev = NULL;

	if(pNode == NULL)
		throw myException("null list");
	while(pNode != NULL){
		ListNode *pNext = c_pList->next(pNode);

		if(pNext == NULL)
			pNewHead = pNode;

		c_pList->setNext(pNode, pPrev);
		pPrev = pNode;
		pNode = pNext;
	}
	c_pList->setNext(c_pList->getHead(), pNewHead);
}

int main(){
	cListNode *c_pList = new cListNode;
	int array[] = {1,2,3,4,5,6};
	int len = sizeof(array)/sizeof(array[0]);

	try{
		c_pList->create(array, len);
		ReverseList(c_pList);
		c_pList->print();
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
