/// \file ListNode.h
/*
  ------------------------------------
  Create date : 2015-01-18 03:53
  Modified date: 2015-01-18 04:28
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
struct ListNode{
	int m_nValue;
	ListNode *m_pNext;
};

class cListNode{
private:
	ListNode *pHead;
public:
	ListNode *create(int *array, int n);
	int getValue(ListNode *pNode);
	ListNode *getHead();
	ListNode *next(ListNode *pNode);
};
