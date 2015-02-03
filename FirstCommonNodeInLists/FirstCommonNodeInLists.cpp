/// \file FirstCommonNodeInLists.cpp
/*
  ------------------------------------
  Create date : 2015-02-04 00:47
  Modified date: 2015-02-04 01:42
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include "../libs/myException.cpp"
#include "../libs/ListNode.cpp"

using namespace std;

//先统计出2个链表的长度，采用快慢指针即可找到
void FirstCommonNodeInLists(ListNode *pHead1, ListNode *pHead2){
	if(pHead1 == NULL  || pHead2 == NULL)
		throw myException("params error");

	ListNode *pNode = pHead1->m_pNext;
	int count = 0;
	while(pNode != NULL){
		++count;
		pNode = pNode->m_pNext;
	}
	pNode = pHead2->m_pNext;
	while(pNode != NULL){
		--count;
		pNode = pNode->m_pNext;
	}

	pNode = pHead1->m_pNext;
	ListNode *pNode2 = pHead2->m_pNext;
	while(count != 0){
		if(count > 0){
			pNode = pNode->m_pNext;
			--count;
		}else{
			pNode2 = pNode2->m_pNext;
			++count;
		}
	}
	while(pNode != NULL && pNode2 != pNode){
		pNode = pNode->m_pNext;
		pNode2 = pNode2->m_pNext;
	}
	if(pNode == NULL)
		cout << "no common listnode" << endl;
	else
		cout << "find first common listnode: " << pNode->m_nValue << endl;
}

//找到两个链表第一个共同结点
int main(){
	//1 -> 2 -> 3 -> 4 -> 5 -> 6
	//          2 -> 4 -> 5 -> 6(4是公共结点)
	int array1[] = {1,2,3};
	int len1 = sizeof(array1)/sizeof(array1[0]);
	int array2[] = {2};
	int len2 = sizeof(array2)/sizeof(array2[0]);
	int arrayCommon[] = {4,5,6};
	int lenCommon = sizeof(arrayCommon)/sizeof(arrayCommon[0]);

	try{
		ListNode* pHead1 = CreateLists(array1, len1);
		ListNode* pHead2 = CreateLists(array2, len2);
		ListNode* pHeadCommon = CreateLists(arrayCommon, lenCommon);

		ListNode *pNode = pHead1;
		while(pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;
		pNode->m_pNext = pHeadCommon->m_pNext;

		pNode = pHead2;
		while(pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;
		pNode->m_pNext = pHeadCommon->m_pNext;

		FirstCommonNodeInLists(pHead1, pHead2);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
