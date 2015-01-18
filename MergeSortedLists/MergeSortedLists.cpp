/// \file MergeSortedLists.cpp
/*
  ------------------------------------
  Create date : 2015-01-19 02:15
  Modified date: 2015-01-19 02:42
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include "../libs/myException.cpp"
#include "../libs/ListNode.cpp"

using namespace std;

cListNode *MergeSortedLists(cListNode *c_p1, cListNode *c_p2){
	ListNode *p1 = c_p1->next(c_p1->getHead());
	ListNode *p2 = c_p1->next(c_p2->getHead());

	if( p1 == NULL || p2 == NULL)
		throw myException("empty list");

	cListNode *c_p3 = new cListNode;
	ListNode *p3 = new ListNode;
	c_p3->setHead(p3);

	while(p1 != NULL && p2 != NULL){
		if(c_p1->getValue(p1) < c_p2->getValue(p2)){
			c_p3->setNext(p3, p1);
			p1 = c_p1->next(p1);
		}else{
			c_p3->setNext(p3, p2);
			p2 = c_p2->next(p2);
		}
		p3 = c_p3->next(p3);
	}
	if(p1 != NULL){
		c_p3->setNext(p3, p1);
	}else if( p2 != NULL){
		c_p3->setNext(p3, p2);
	}

	return c_p3;
}

int main(){
	cListNode *c1 = new cListNode;
	cListNode *c2 = new cListNode;
	int array1[] = {1,3,5};
	int len1 = sizeof(array1)/sizeof(array1[0]);
	int array2[] = {2,4,6};
	int len2 = sizeof(array2)/sizeof(array2[0]);
	
	try{
		c1->create(array1, len1);
		c2->create(array2, len2);
		cListNode *c3 = MergeSortedLists(c1, c2);
		c3->print();
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
