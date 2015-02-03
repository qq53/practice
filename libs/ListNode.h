/// \file ListNode.h
/*
  ------------------------------------
  Create date : 2015-01-18 03:53
  Modified date: 2015-02-04 00:56
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
struct ListNode{
	int m_nValue;
	ListNode *m_pNext;
};

ListNode *CreateLists(int *array, int n);
void PrintLists(ListNode* pHead);
