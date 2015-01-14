/// \file PrintToMaxOfNDigits.cpp
/*
  ------------------------------------
  Create date : 2015-01-15 02:27
  Modified date: 2015-01-15 04:09
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include <string.h>
#include "../libs/myException.cpp"

using namespace std;

bool Increment(char number[]){
	int i = strlen(number) - 1;
	
	++number[i];

	bool isFinished = false;
	while(number[i] > '9'){
		if(i == 0){ //若最高为都要进位表示已经到最大数了
			isFinished = true;
			break;
		}else{	//模拟加法
			number[i] -= 10;
			++number[i - 1];
			--i;
		}
	}
	return isFinished;
}

void PrintNumber(char number[]){ //从第一个非零打印
	int i = 0;
	int len = strlen(number);
	
	while(number[i] == '0' && i < len)
		++i;
	for(; i < len; ++i){
		cout << number[i];
	}
	cout << endl;
}

void PrintToMaxOfNDigits(int n){
	if(n <= 0)
		throw myException("n can't less than 0");

	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while(!Increment(number)){
		PrintNumber(number);
	}

	delete [] number;
}

int main(){
	int n;

	cin >> n;
	try{
		PrintToMaxOfNDigits(n);
	}catch(myException &e){
		cout << e.what() << endl;
	}
	return 0;
}
