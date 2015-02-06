/// \file TwoNumbersAppearOnce.cpp
/*
  ------------------------------------
  Create date : 2015-02-06 23:42
  Modified date: 2015-02-07 05:04
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include "../libs/myException.cpp"

using namespace std;

//可以利用异或运算性质找出
void TwoNumbersAppearOnce(int *data, int len){
	if(data == NULL || len <= 0)
		throw myException("params error");

	int split = 0;
	for(int i = 0; i < len; ++i)
		split ^= data[i];

	int num1 = 0, num2 = 0;
	for(int i = 0; i < len; ++i){
		if( (data[i]&split) == 0 )
			num1 ^= data[i];	
		else
			num2 ^= data[i];
	}

	cout << num1 << endl;
	cout << num2 << endl;
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
