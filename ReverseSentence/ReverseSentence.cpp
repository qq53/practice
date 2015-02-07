/// \file ReverseSentence.cpp
/*
  ------------------------------------
  Create date : 2015-02-07 17:37
  Modified date: 2015-02-07 18:03
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

void ReverseSentence(char *str){
	if(str == NULL)
		throw myException("empty string");

	char *pBegin = str;
	char *pEnd = str;
	char *pTail = strlen(str)+str;

	Reverse(pBegin, pTail-1);
	while(*pBegin != '\0'){
		if(*pBegin == ' '){
			++pBegin;
			++pEnd;
		}else if(*pEnd == ' ' || *pEnd == '\0'){
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}else
			++pEnd;
	}

	cout << str << endl;
}

int main(){
	char str[] = "hello world!";

	try{
		ReverseSentence(str);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
