/// \file ListNode.cpp
/*
  ------------------------------------
  Create date : 2015-01-18 04:11
  Modified date: 2015-01-19 02:21
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include "ListNode.h"

ListNode *cListNode::create(int *array, int n){
	if(array == NULL || n <= 0)
		throw myException("create listnode fail");

	ListNode *pHead = new ListNode;
	this->pHead = pHead;

	for(int i = 0; i < n; ++i){
		ListNode *pNode = new ListNode;
		pNode->m_nValue = array[i];
		pNode->m_pNext = NULL;
		pHead->m_pNext = pNode;
		pHead = pNode;
	}

	return this->pHead;
}

int cListNode::getValue(ListNode *pNode){
	if(pNode == NULL)
		throw myException("getValue fail");
	return pNode->m_nValue;
}

ListNode *cListNode::getHead(){
	return this->pHead;
}

ListNode *cListNode::next(ListNode *pNode){
	if(pNode == NULL)
		throw myException("get next fail");
	return pNode->m_pNext;
}

void cListNode::setNext(ListNode *pNode, ListNode *pNext){
	if(pNode == NULL)
		throw myException("setNext fail");
	pNode->m_pNext = pNext;
}

void cListNode::print(){
	ListNode *pNode = next(this->pHead);
	if(pNode == NULL)
		throw myException("print fail");
	while(pNode != NULL){
		std::cout << getValue(pNode) << " ";
		pNode = next(pNode);
	}
	std::cout << std::endl;
}

void cListNode::setHead(ListNode *pNode){
	this->pHead = pNode;
}
