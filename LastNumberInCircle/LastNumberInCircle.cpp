/// \file LastNumberInCircle.cpp
/*
  ------------------------------------
  Create date : 2015-02-09 06:57
  Modified date: 2015-02-09 07:04
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include "../libs/myException.cpp"

using namespace std;

//0,1,2,...,n-1个数每次删除第m个数，求最后剩下的数
void LastNumberInCircle(int n, int m){
	if(n < 1 || m < 1)
		throw myException("params error");

	int last = 0;
	for(int i = 2; i <= n; ++i)
		last = (last + m) % i;

	cout << "last number: " << last << endl;
}

int main(){

	try{
		LastNumberInCircle(3,2);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
