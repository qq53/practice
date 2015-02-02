/// \file InversePairs.cpp
/*
  ------------------------------------
  Create date : 2015-02-02 23:35
  Modified date: 2015-02-02 23:38
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include "../libs/myException.cpp"

using namespace std;

//求数组中逆序对（前面的数比后面数大的对）的个数 比如7,5,6,4这个数组有5个逆序对
void InversePairs(int *data, int len){
	if(data == NULL || len <= 0)
		throw myException("params error");

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
