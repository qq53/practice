/// \file TwoNumbersWithSum.cpp
/*
  ------------------------------------
  Create date : 2015-02-07 05:06
  Modified date: 2015-02-07 05:17
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include "../libs/myException.cpp"

using namespace std;

//找到两个和是SUM的数，behind必须从尾巴开始
void TwoNumbersWithSum(int *data, int len, int sum){
	if(data == NULL || len <= 0)
		throw myException("params error");

	int behind = 0, ahead = len - 1;
	while(behind < ahead){
		long curSum = data[behind] + data[ahead];
		if(curSum == sum){
			cout << data[behind] << " " << data[ahead] << endl;
			--ahead;
			++behind;
		}else if(curSum > sum)
			--ahead;
		else
			++behind;
	}
}

int main(){
	int array[] = {1,2,4,7,11,13,15};
	int len = sizeof(array)/sizeof(array[0]);
	int sum = 15;

	try{
		TwoNumbersWithSum(array, len, sum);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
