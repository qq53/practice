/// \file Accumulate.cpp
/*
  ------------------------------------
  Create date : 2015-02-09 07:14
  Modified date: 2015-02-09 07:24
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include "../libs/myException.cpp"

using namespace std;

typedef int (*fun)(int);
int Terminator(int n);
int Accumulate(int n);

int Terminator(int n){
	return 0;
}

int Accumulate(int n){
	static fun f[2] = {Terminator, Accumulate};
	return n+f[!!n](n-1);	
}

int main(){

	try{
		cout <<	Accumulate(10) << endl;
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
