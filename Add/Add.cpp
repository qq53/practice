/// \file Add.cpp
/*
  ------------------------------------
  Create date : 2015-02-09 07:28
  Modified date: 2015-02-09 07:49
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include "../libs/myException.cpp"

using namespace std;

long Add(int a, int b){
	int sum, carry;
	do{
		sum = a ^ b;
		carry = (a & b) << 1;

		a = sum;
		b = carry;
	}while(b != 0);
	
	return sum;
}

int main(){

	try{
		cout << Add(5,-18) << endl;
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
