/// \file InversePairs.cpp
/*
  ------------------------------------
  Create date : 2015-02-02 23:35
  Modified date: 2015-02-03 04:14
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include "../libs/myException.cpp"

using namespace std;

int InversePairsCore(int *data, int *copy, int start, int end){
	if(start == end){
		copy[start] = data[start];
		return 0;
	}

	int len = (end-start)/2;
	int left = InversePairsCore(copy, data, start, start+len);
	int right = InversePairsCore(copy, data, start+len+1, end);

	int i = start+len;
	int j = end;
	int count = 0;
	int copyIndex = end;
	while(i >= start && j >= start+len+1){
		if(data[i] > data[j]){
			copy[copyIndex--] = data[i--];
			count += j - start - len;
		}else{
			copy[copyIndex--] = data[j--];
		}
	}

	for(; i >= start; --i)
		copy[copyIndex--] = data[i];
	for(; j >= start+len+1; --j)
		copy[copyIndex--] = data[j];

	return left + right + count;
}

//求数组中逆序对（前面的数比后面数大的对）的个数 比如7,5,6,4这个数组有5个逆序对
void InversePairs(int *data, int len){
	if(data == NULL || len <= 0)
		throw myException("params error");

	int *copy = new int[len];
	for(int i = 0; i < len; ++i)
		copy[i] = data[i];

	int count = InversePairsCore(data, copy, 0, len-1);
	delete [] copy;
	cout << count << endl;
}

int main(){
	int data[] = {7,5,6,4};
	int len = sizeof(data)/sizeof(data[0]);

	try{
		InversePairs(data, len);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
