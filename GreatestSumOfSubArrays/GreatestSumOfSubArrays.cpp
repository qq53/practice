/// \file GreatestSumOfSubArrays.cpp
/*
  ------------------------------------
  Create date : 2015-01-29 19:35
  Modified date: 2015-01-29 20:56
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include "../libs/myException.cpp"

using namespace std;

int GreatestSumOfSubArrays(const int *array, int n){
	if(n == 0)
		return array[n];
	
	int temp = GreatestSumOfSubArrays(array, n-1);
	
	if(temp > array[n]+temp)
		end = n; //如果加了array[n]会变小那子数组就到n-1为止

	if(temp > 0)
		return array[n]+temp;
	else{
		start = n; //之前小于0 则子数组可能从n开始
		return array[n];
	}
}

int start, end;

void GreatestSumOfSubArrays(int *array, int len){
	if(array == NULL || len <= 0)
		throw myException("params error");
	
	end = len;

	GreatestSumOfSubArrays((const int*)array, len-1);

	int sums = 0;
	cout << "{";
	for(int i = start; i < end-1; ++i){
		cout << array[i] << ",";
		sums += array[i];
	}
	cout << array[end-1] << "} sums: " << sums << endl;
}

int main(){
	//找出数组中和最大的子数组 朴素和动态规划都可以
	int array[] = {1,-2,3,10,-4,7,2,-5};
	int len = sizeof(array)/sizeof(array[0]);

	try{
		GreatestSumOfSubArrays(array, len);
	}catch(myException &e){
		cout << e.what() << endl;
	}


	return 0;
}
