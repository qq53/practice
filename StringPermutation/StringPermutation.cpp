/// \file StringPermutation.cpp
/*
  ------------------------------------
  Create date : 2015-01-29 00:27
  Modified date: 2015-01-29 00:36
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include "../libs/myException.cpp"

using namespace std;

void StringPermutation(const char *str, char *pBegin){
	if(*pBegin == '\0')
		cout << str << endl;

	for(char *pCh = pBegin; *pCh != '\0'; ++pCh){
		char temp = *pCh;
		*pCh = *pBegin;
		*pBegin = temp;

		StringPermutation(str, pBegin+1);

		temp = *pCh;
		*pCh = *pBegin;
		*pBegin = temp;
	}
}

void StringPermutation(const char *str){
	if(!str)
		throw myException("empty string");

	StringPermutation(str, (char*)str);
}

int main(){
	char str[] = "abc";
	
	try{
		StringPermutation((const char*)str);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
