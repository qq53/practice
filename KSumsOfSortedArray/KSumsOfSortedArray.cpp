/// \file KSumsOfSortedArray.cpp
/*
  ------------------------------------
  Create date : 2015-02-04 23:17
  Modified date: 2015-02-04 23:46
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include "../libs/myException.cpp"

using namespace std;

int firstIndex(int *data, int k, int start, int end){
	if(start == end){
		if(data[start] == k)
			return start;
		else
			return -1;
	}

	int middle = (start+end)/2;
	if(data[middle] == k){
		if(middle == 0 || data[middle-1] != k)
			return middle;
		else if(data[middle-1] < k)
			start = middle + 1;
		else
			end = middle - 1;
	}else if(data[middle] > k)
		end = middle - 1;
	else
		start = middle + 1;
	
	return firstIndex(data, k, start, end);
}

int lastIndex(int *data, int k, int start, int end){
	if(start == end){
		if(data[start] == k)
			return start;
		else
			return -1;
	}

	int middle = (start+end)/2;
	if(data[middle] == k){
		if(middle == 0 || data[middle+1] != k )
			return middle;
		else if(data[middle-1] > k)
			end = middle - 1;
		else
			start = middle + 1;
	}else if(data[middle] > k)
		end = middle - 1;
	else
		start = middle + 1;
	
	return lastIndex(data, k, start, end);
}

void KSumsOfSortedArray(int *data, int len, int k){
	if(data == NULL || len <= 0)
		throw myException("params error");

	int first = firstIndex(data, k, 0, len-1);
	int last = lastIndex(data, k, 0, len-1);
	
	int result = 0;
	if(first > -1 && last > -1)
		result = last - first + 1;
	
	for(int i = 0; i < len; ++i)
		cout << data[i] << " ";
	
	cout << endl << k << " has " << result << " times" << endl;
}

int main(){
	int array[] = {1,2,3,3,3,4,5,6};
	int len = sizeof(array)/sizeof(array[0]);
	int k = 3;

	try{
		KSumsOfSortedArray(array, len, k);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
