/// \file ComplexListCopy.cpp
/*
  ------------------------------------
  Create date : 2015-01-25 22:32
  Modified date: 2015-01-26 03:08
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include "../libs/myException.cpp"

using namespace std;

struct complexList{
	int m_nValue;
	complexList *m_pNext;
	complexList *m_pSibling;
};

complexList *CreateComplexNode(int value){
	complexList *pNode = new complexList();

	pNode->m_nValue = value;
	pNode->m_pNext = pNode->m_pSibling = NULL;

	return pNode;
}

void BuildComplexNode(complexList *pNode, complexList *pNext, complexList *pSibling){
	if(pNode == NULL)
		throw myException("empty pNode");
	pNode->m_pNext = pNext;
	pNode->m_pSibling = pSibling;
}

void PrintComplexList(complexList *pHead){
	complexList *pNode = pHead;
	while(pNode != NULL){
		cout << pNode->m_nValue;
		cout << " next: ";
		if(pNode->m_pNext)
			cout << pNode->m_pNext->m_nValue;
		cout << " sibling: ";
		if(pNode->m_pSibling)
			cout << pNode->m_pSibling->m_nValue;
		cout << endl;
		pNode = pNode->m_pNext;
	}
}

complexList *CloneComplexList(complexList *pHead){
	complexList *pNode = pHead;

	while(pNode != NULL){//复制结点
		complexList *pTemp = CreateComplexNode(pNode->m_nValue);
		BuildComplexNode(pTemp, pNode->m_pNext, NULL);
		pNode->m_pNext = pTemp;
		
		pNode = pTemp->m_pNext;
	}

	pNode = pHead;//设置第二个指针
	while(pNode != NULL){
		if(pNode->m_pSibling)
			pNode->m_pNext->m_pSibling = pNode->m_pSibling->m_pNext;
		pNode = pNode->m_pNext->m_pNext;
	}

	pNode = pHead;	//拆分两个链表
	complexList *pNewHead = NULL;
	if(pHead)
		pNewHead = pHead->m_pNext;
	complexList *pNode1 = pNewHead;

	while(pNode != NULL){
		pNode->m_pNext = pNode1->m_pNext;
		pNode1->m_pNext = NULL;
		if(pNode->m_pNext)
			pNode1->m_pNext = pNode->m_pNext->m_pNext;

		pNode = pNode->m_pNext;
		pNode1 = pNode1->m_pNext;
	}

	return pNewHead;
}

int main(){
	try{
		complexList *pNode1 = CreateComplexNode(1);
		complexList *pNode2 = CreateComplexNode(2);
		complexList *pNode3 = CreateComplexNode(3);
		complexList *pNode4 = CreateComplexNode(4);
		complexList *pNode5 = CreateComplexNode(5);

		BuildComplexNode(pNode1, pNode2, pNode5);
		BuildComplexNode(pNode2, pNode3, pNode5);
		BuildComplexNode(pNode3, pNode4, pNode3);
		BuildComplexNode(pNode4, pNode5, pNode2);

		complexList* pCloneNode = CloneComplexList(pNode1);
		PrintComplexList(pCloneNode);
	}catch(myException &e){
		cout << e.what() << endl;
	}
}
