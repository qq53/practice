/// \file ListNode.cpp
/*
  ------------------------------------
  Create date : 2015-01-18 04:11
  Modified date: 2015-02-04 01:05
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include "ListNode.h"

ListNode *CreateLists(int *array, int n){
	if(array == NULL || n <= 0)
		throw myException("create listnode fail");

	ListNode *pHead = new ListNode;
	ListNode *pNode = pHead;

	for(int i = 0; i < n; ++i){
		ListNode *pNext = new ListNode;
		pNext->m_nValue = array[i];
		pNext->m_pNext = NULL;
		pNode->m_pNext = pNext;
		pNode = pNext;
	}

	return pHead;
}

void PrintLists(ListNode *pHead){
	if(pHead == NULL)
		throw myException("empty lists");

	ListNode *pNode = pHead->m_pNext;
	while(pNode != NULL){
		std::cout << pNode->m_nValue << " ";
		pNode = pNode->m_pNext;
	}
	std::cout << std::endl;
}
