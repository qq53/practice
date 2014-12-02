/// \file QuickSort.cpp
/*
  ------------------------------------
  Create date : 2014-12-02 02:19
  Modified date: 2014-12-02 02:44
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include <stdlib.h>

#include "../libs/myException.cpp"

using namespace std;

void QuickSort(int[], int, int);

int main(){
	int arr[] = {5, 6, 9, 10, 12, 13, 1, 0};
	int len = sizeof(arr) / sizeof(arr[0]);

	cout << "Before Sort:" << endl;
	for(int i = 0; i < len; ++i)
		cout << arr[i] << " ";
	cout << endl;

	QuickSort(arr, 0, len - 1);

	cout << "After Sort:" << endl;
	for(int i = 0; i < len; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

int Random(int a, int b){
	int c;
	while( (c=(rand()%(b+1))) < a)
		;
	return c;
}

void Swap(int *p1, int *p2){
	if(*p1 != *p2){
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
}

int Partition(int arr[], int start, int end){
	if(arr == NULL || start < 0 || end < start)
		throw myException("array invalid");

	int index = Random(start, end);
	Swap(&arr[index], &arr[end]);

	int bigidx = start - 1;
	for(int idx = start; idx < end; ++idx){
		if(arr[idx] < arr[end]){
			++bigidx;
			if(bigidx != idx)
				Swap(&arr[bigidx], &arr[idx]);
		}
	}

	++bigidx;
	Swap(&arr[bigidx], &arr[end]);
	
	return bigidx;
}

void QuickSort(int arr[], int start, int end){
	if(start == end)
		return;

	try{
		int index = Partition(arr, start, end);
		if(index > start)
			QuickSort(arr, start, index - 1);
		if(index < end)
			QuickSort(arr, index + 1, end);
	}catch(myException &e){
		cout << e.what() << endl;
	}
}
