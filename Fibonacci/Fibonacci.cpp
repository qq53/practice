/// \file Fibonacci.cpp
/*
  ------------------------------------
  Create date : 2014-12-06 16:32
  Modified date: 2014-12-06 16:36
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>

#include "../libs/myException.cpp"

using namespace std;

long long Fibonacci(int);

int main(){
	cout << Fibonacci(5) << endl;

	return 0;
}

long long Fibonacci(int n){
	if(n < 0)
		throw myException("invalid params");

	if(n < 2)
		return n == 0 ? 0 : 1;
	
	long long fibOne = 1;
	long long fibTwo = 0;
	long long fibN   = 0;
	for(unsigned int i = 2; i <=n; ++i){
		fibN = fibOne + fibTwo;
		fibTwo = fibOne;
		fibOne = fibN;
	}

	return fibN;
}
