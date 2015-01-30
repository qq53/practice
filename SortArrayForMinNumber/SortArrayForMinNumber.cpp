/// \file SortArrayForMinNumber.cpp
/*
  ------------------------------------
  Create date : 2015-01-30 18:21
  Modified date: 2015-01-30 21:53
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libs/myException.cpp"

using namespace std;

char *pStrCombine1;
char *pStrCombine2;

/* 13 31
 * 刚好符合strcmp*/
int Compare(const void* strNumber1, const void* strNumber2){
	strcpy(pStrCombine1, *(const char **)strNumber1);
	strcat(pStrCombine1, *(const char **)strNumber2);

	strcpy(pStrCombine2, *(const char **)strNumber2);
	strcat(pStrCombine2, *(const char **)strNumber1);

	return strcmp(pStrCombine1, pStrCombine2);
}

void SortArrayForMinNumber(int *array, int len){
	if(array == NULL || len <= 0)
		throw myException("params error");
	
	pStrCombine1 = new char[len*2+1];
	pStrCombine2 = new char[len*2+1];

	char **strNumbers = (char**)(new int[len]);
	for(int i = 0; i < len; ++i){
		strNumbers[i] = new char[len+1];
		sprintf(strNumbers[i], "%d", array[i]);
	}

	qsort(strNumbers, len, sizeof(char*), Compare);	//排序即可

	for(int i = 0; i < len; ++i)
		cout << strNumbers[i];
	cout << endl;

	for(int i = 0; i < len; ++i)
		delete [] strNumbers[i];
	delete [] strNumbers;
}

int main(){
	int array[] = {3,32,321};
	int len = sizeof(array)/sizeof(array[0]);

	try{
		SortArrayForMinNumber(array, len);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
