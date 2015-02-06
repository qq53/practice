/// \file SerialSquenceWithSum.cpp
/*
  ------------------------------------
  Create date : 2015-02-07 05:20
  Modified date: 2015-02-07 05:32
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include "../libs/myException.cpp"

using namespace std;

void SerialSequenceWithSum(int sum){
	if(sum <= 1)
		throw myException("can't less than 1");

	int begin = 1;
	int end = 2;
	int middle = sum/2;

	long curSum = begin + end;
	while(begin <= middle){
		if(curSum == sum){
			cout << begin << "~" << end << endl;
			++end;
			curSum += end;
		}else if(curSum < sum){
			++end;
			curSum += end;
		}else{
			curSum -= begin;
			++begin;
		}
	}
}

int main(){

	try{
		SerialSequenceWithSum(15);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
