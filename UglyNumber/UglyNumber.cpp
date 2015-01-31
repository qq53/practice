/// \file UglyNumber.cpp
/*
  ------------------------------------
  Create date : 2015-01-31 21:39
  Modified date: 2015-01-31 21:41
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include "../libs/myException.cpp"

using namespace std;

void UglyNumber(int n){
	if(n <= 0)
		throw myException("n can't less than 1");
}

//只包含银子2、3、5的数成为丑数，求第1500个丑数，习惯上吧1当作第一个丑数
int main(){

	try{
		UglyNumber(1500);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
