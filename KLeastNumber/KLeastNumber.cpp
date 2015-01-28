/// \file KLeastNumber.cpp
/*
  ------------------------------------
  Create date : 2015-01-29 01:37
  Modified date: 2015-01-29 02:21
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include <set>
#include "../libs/myException.cpp"

using namespace std;

void KLeastNumber(int array[], int len, int k){
	if(array == NULL || len <= 0 || k <= 0)
		throw myException("params error");

	multiset<int, greater<int> > leastNumbers;	//大顶堆，设置K个结点个数，每次和堆顶比较，
	//这样到最后剩下的就是最小的K个数
	leastNumbers.clear();

	for(int i = 0; i < len; ++i){
		if((leastNumbers.size()) < k)
			leastNumbers.insert(array[i]);
		else{
			multiset<int, greater<int> >::iterator iterGreatest = leastNumbers.begin();
			if(array[i] < *iterGreatest){
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(array[i]);
			}
		}
	}

	multiset<int, greater<int> >::iterator iterLeastest = leastNumbers.end();
	for(int i = 0; i < k; ++i){
		cout << *iterLeastest << " ";
		--iterLeastest;
	}
	cout << endl;
}

int main(){
	int array[] = {4,5,1,6,2,7,3,8};
	int len = sizeof(array)/sizeof(array[0]);

	try{
		KLeastNumber(array, len, 4);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
