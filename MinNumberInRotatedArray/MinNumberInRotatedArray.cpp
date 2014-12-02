/// \file MinNumberInRotatedArray.cpp
/*
  ------------------------------------
  Create date : 2014-12-02 09:03
  Modified date: 2014-12-02 09:21
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>

#include "../libs/myException.cpp"

using namespace std;

int Min(int[], int);

int main(){
	int arr[] = {1, 1, 1, 1, 1};
	int len = sizeof(arr) / sizeof(arr[0]);

	try{
		int min = Min(arr, len);
		cout << min << endl;
	}catch(myException &e){
		cout << e.what() << endl;
	}
}

int minInOrder(int arr[], int len){
	int min = 0;

	for(int i = 1; i < len; ++i){
		if(arr[i] < arr[min])
			min = i;
	}

	return min;
}

int Min(int arr[], int len){
	if(arr == NULL || len < 0)
		throw myException("array invalid");

	int index1 = 0;
	int index2 = len - 1;
	int indexMid = index1;
	while(arr[index1] > arr[index2]){
		if(arr[index1] == arr[index2] &&
				arr[index1] == arr[indexMid]){
			indexMid = minInOrder(arr, len);
		}
		if(index2 - index1 == 1){
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;
		if(arr[index1] < arr[indexMid])
			index1 = indexMid;
		else if(arr[index2] > arr[indexMid])
			index2 = indexMid;
	}

	return arr[indexMid];
}
