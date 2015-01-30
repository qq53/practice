/// \file NumberOf1.cpp
/*
  ------------------------------------
  Create date : 2015-01-29 23:37
  Modified date: 2015-01-30 18:19
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../libs/myException.cpp"

using namespace std;

long NumberOf1(char *num){
	int n = *num - '0';
	int len = strlen(num);

	if(*num == '\0')
		return 0;
	if(len == 1){
		if(n > 0)
			return 1;
		else
			return 0;
	}

	int oneInFirst = 0; //最高为是1的个数
	if(n > 1)
		oneInFirst = pow10(len-1);
	else if(n == 1)
		oneInFirst = atoi(num+1) + 1;
	
	int oneInOther = n * pow10(len-2) * (len-1); //除最高位出现1的个数,排列得出

	return oneInFirst + oneInOther + NumberOf1(num+1); //递归解决
}

int main(){

	try{
		long num;
		cout << "input num: ";
		cin >> num;
		char cnum[50];
		sprintf(cnum, "%ld", num);
		cout <<	NumberOf1(cnum) << endl;
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
