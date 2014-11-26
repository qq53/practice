/// \file PrintListReversingly.cpp
/*
  ------------------------------------
  Create date : 2014-11-24 13:40
  Modified date: 2014-11-26 09:39
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include <stack>

using namespace std;

typedef struct ListNode{
	int key;
	ListNode *pnext;
}ListNode;

/*
 * 很简单的题目，倒着打印单链表
 * 利用栈的特性即可
*/
void PrintListReversingly(ListNode *);

int main(void){
	ListNode *head = new ListNode;
	ListNode *p1 = head;
	for(int i = 0; i < 5; ++i){
		ListNode *p2 = new ListNode;
		p2->key = i;
		p1->pnext = p2;
		p1 = p2;
	}
	PrintListReversingly(head);

	return 0;
}

void PrintListReversingly(ListNode *head){
	stack<ListNode *> nodes;

	ListNode *p = head->pnext;
	while(p){
		nodes.push(p);
		p = p->pnext;
	}

	while(!nodes.empty()){
		cout << nodes.top()->key << " ";
		nodes.pop();
	}
	cout << endl;
}
