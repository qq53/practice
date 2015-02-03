/// \file MergeSortedLists.cpp
/*
  ------------------------------------
  Create date : 2015-01-19 02:15
  Modified date: 2015-02-04 01:03
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include "../libs/myException.cpp"
#include "../libs/ListNode.cpp"

using namespace std;

ListNode *MergeSortedLists(ListNode *pHead1, ListNode *pHead2){
	ListNode *p1 = pHead1->m_pNext;
	ListNode *p2 = pHead2->m_pNext;

	if( p1 == NULL || p2 == NULL )
		throw myException("empty list");

	ListNode *pHead3 = new ListNode;
	ListNode *p3 = pHead3;

	while(p1 != NULL && p2 != NULL){
		if(p1->m_nValue < p2->m_nValue){
			p3->m_pNext = p1;
			p1 = p1->m_pNext;
		}else{
			p3->m_pNext = p2;
			p2 = p2->m_pNext;
		}
		p3 = p3->m_pNext;
	}
	if(p1 != NULL){
		p3->m_pNext = p1;
	}else if( p2 != NULL){
		p3->m_pNext = p2;
	}

	return pHead3;
}

int main(){
	int array1[] = {1,3,5};
	int len1 = sizeof(array1)/sizeof(array1[0]);
	int array2[] = {2,4,6};
	int len2 = sizeof(array2)/sizeof(array2[0]);
	
	try{
		ListNode *pHead1 = CreateLists(array1, len1);
		ListNode *pHead2 = CreateLists(array2, len2);
		ListNode *pHead3 = MergeSortedLists(pHead1, pHead2);
		PrintLists(pHead3);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
