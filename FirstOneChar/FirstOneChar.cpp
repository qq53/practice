/// \file FirstOneChar.cpp
/*
  ------------------------------------
  Create date : 2015-02-01 23:26
  Modified date: 2015-02-01 23:38
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include <string.h>
#include "../libs/myException.cpp"

using namespace std;

//找到第一个出现一次的字符
void FirstOneChar(char *pStr){
	if(pStr == NULL)
		throw myException("empty string");

	int tableSize = 256;
	unsigned int hashTable[tableSize];
	memset(hashTable, 0, sizeof(hashTable));

	for(char *p = pStr; *p != '\0'; ++p)
		++hashTable[*p];

	int i;
	for(i = 0; i < tableSize; ++i)
		if(hashTable[i] == 1)
			break;
	
	if(i < tableSize)
		cout << (char)i << endl;
	else
		cout << "no one char" << endl;
}

int main(){
	char str[] = "aabbdcd";

	try{
		FirstOneChar(str);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
