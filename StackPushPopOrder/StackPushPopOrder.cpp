/// \file StackPushPopOrder.cpp
/*
  ------------------------------------
  Create date : 2015-01-22 02:07
  Modified date: 2015-01-22 02:38
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include <stack>
#include "../libs/myException.cpp"

using namespace std;

bool IsPopOrder(const int *pPush, const int *pPop, int len){
	if(pPush == NULL || pPop == NULL || len <= 0)
		throw myException("params error");

	const int *pNextPush = pPush;
	const int *pNextPop  = pPop;
	
	stack<int> stack;

	while(pNextPop < pPop + len){
		while(stack.empty() || stack.top() != *pNextPop){
			if(pNextPush == pPush + len)
				break;
			stack.push(*pNextPush);
			++pNextPush;
		}
		if(stack.top() != *pNextPop)
			break;
		stack.pop();
		++pNextPop;
	}
	if(stack.empty() && pNextPop == pPop+len)
		return true;
	return false;
}

int main(){
	int pPush[] = {1,2,3,4,5};
	int pPop1[] = {4,5,3,2,1};
	int pPop2[] = {4,3,5,1,2};
	int len = sizeof(pPush)/sizeof(pPush[0]);

	try{
		cout << IsPopOrder(pPush, pPop1, len) << endl;
		cout << IsPopOrder(pPush, pPop2, len) << endl;
	}catch(myException &e){
		cout << e.what() << endl;
	}
}
