/// \file UglyNumber.cpp
/*
  ------------------------------------
  Create date : 2015-01-31 21:39
  Modified date: 2015-02-01 04:09
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include "../libs/myException.cpp"

#define MIN(a,b) (a)<(b)?(a):(b)

using namespace std;

//只包含银子2、3、5的数成为丑数，求第1500个丑数，习惯上吧1当作第一个丑数
int UglyNumber(int n){
	if(n <= 0)
		throw myException("n can't less than 1");

	int *pUglyNumber = new int[n];
	pUglyNumber[0] = 1;
	int nextUglyIndex = 1;

	int *pUgly2 = pUglyNumber;
	int *pUgly3 = pUglyNumber;
	int *pUgly5 = pUglyNumber;
	int min;

	while(nextUglyIndex < n){
		min = MIN(MIN(*pUgly2*2, *pUgly3*3), *pUgly5*5);
		pUglyNumber[nextUglyIndex] = min;
		++nextUglyIndex;

		while(*pUgly2*2 <= min)
			++pUgly2;
		while(*pUgly3*3 <= min)
			++pUgly3;
		while(*pUgly5*5 <= min)
			++pUgly5;
	}

	delete [] pUglyNumber;

	return min;
}

int main(){

	try{
		cout << UglyNumber(1500) << endl;
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
