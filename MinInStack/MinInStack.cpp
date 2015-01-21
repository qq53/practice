/// \file MinInStack.cpp
/*
  ------------------------------------
  Create date : 2015-01-21 14:24
  Modified date: 2015-01-21 18:46
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include "../libs/myException.cpp"
#include "MinInStack.h"

using namespace std;

int main(){
	StackWithMin<int> stack;

	try{
		stack.push(3);
		stack.push(5);
		stack.push(4);
		stack.push(1);
		stack.push(2);

		cout << stack.min() << endl;
		stack.pop();
		cout << stack.min() << endl;
		stack.pop();
		cout << stack.min() << endl;
		stack.pop();
		cout << stack.min() << endl;
		stack.pop();
		cout << stack.min() << endl;
		stack.pop();
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
