/// \file LeftRotateString.cpp
/*
  ------------------------------------
  Create date : 2015-02-08 05:36
  Modified date: 2015-02-08 05:40
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include <string.h>
#include "../libs/myException.cpp"

using namespace std;

void Reverse(char *pBegin, char *pEnd){
	char temp;
	while(pBegin < pEnd){
		temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;

		++pBegin;
		--pEnd;
	}
}

void LeftRotateString(char *str, int n){
	if(str == NULL || n < 0)
		throw myException("params error");

	int len = strlen(str);
	Reverse(str, str+n-1);
	Reverse(str+n, str+len-1);
	Reverse(str, str+len-1);

	cout << str << endl;
}

int main(){
	char str[] = "abcdefg";

	try{
		LeftRotateString(str, 2);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
