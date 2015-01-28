/// \file MoreThanHalfNumber.cpp
/*
  ------------------------------------
  Create date : 2015-01-29 01:24
  Modified date: 2015-01-29 01:33
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include "../libs/myException.cpp"

using namespace std;

void MoreThanHalfNumber(int array[], int len){
	if(array == NULL || len <= 0)
		throw myException("param error");

	int result = array[0];
	int times = 1;
	for(int i = 1; i < len; ++i){
		if(result != array[i])
			--times;
		else
			++times;
		if(times == 0){
			result = array[i];
			times = 1;
		}
	}

	times = 0;
	for(int i = 0; i < len; ++i)
		if(array[i] == result)
			++times;
	if(times * 2 <= len)
		cout << "no more than half number";
	else
		cout << result;
	cout << endl;
}

int main(){
	int array[] = {1,2,3,2,2,2,5,4,2};
	int len = sizeof(array)/sizeof(array[0]);

	try{
		MoreThanHalfNumber(array, len);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
