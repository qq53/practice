/// \file TwoNumbersAppearOnce.cpp
/*
  ------------------------------------
  Create date : 2015-02-06 23:42
  Modified date: 2015-02-06 23:44
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include "../libs/myException.cpp"

using namespace std;

void TwoNumbersAppearOnce(int *data, int len){
	if(data == NULL || len <= 0)
		throw myException("params error");
}

int main(){
	int array[] = {2,4,3,6,3,2,5,5};
	int len = sizeof(array)/sizeof(array[0]);

	try{
		TwoNumbersAppearOnce(array, len);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
