/// \file ReorderArray.cpp
/*
  ------------------------------------
  Create date : 2015-01-16 01:32
  Modified date: 2015-01-16 01:45
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>

#include "../libs/myException.cpp"

using namespace std;

void Reorder(int *pData, unsigned int length, bool (*func)(int)){
	if(pData == NULL || length <= 0)
		throw myException("int array error");

	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while(pBegin < pEnd){
		while(pBegin < pEnd && !func(*pBegin))
			++pBegin;
		while(pBegin < pEnd && func(*pEnd))
			--pEnd;

		if(pBegin < pEnd){
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

bool isEven(int n){
	return (n & 1) == 0;
}

void ReorderOddEven(int *pData, unsigned int length){
	Reorder(pData, length, isEven);	
}

int main(){
	int arr[] = {1,3,6,2,4,5};
	int len = sizeof(arr)/sizeof(arr[0]);

	try{
		ReorderOddEven(arr, len);

		for(int i = 0; i < len; ++i)
			cout << arr[i];
		cout << endl;
	}catch(myException &e){
		cout << e.what() << endl;
	}
	return 0;
}
