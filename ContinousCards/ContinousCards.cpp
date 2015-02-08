/// \file ContinousCards.cpp
/*
  ------------------------------------
  Create date : 2015-02-08 13:20
  Modified date: 2015-02-08 13:51
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include "../libs/myException.cpp"

using namespace std;

//判断是否数组是顺子
void ContinousCards(int *data, int len){
	if(data == NULL || len < 3)
		throw myException("params error");

	//1~10 J=10 Q=11 K=11 大小王=0 大小王可以当任何牌
	int cards[14];
	for(int i = 0; i < 14; ++i)
		cards[i] = 0;

	int begin = 13;
	for(int i = 0; i < len; ++i){
		++cards[data[i]];
		if(cards[data[i]] > 1){
			if(data[i] == 0){
				if(cards[0] > 2){
					cout << "boss cards can't more than 2" << endl;
					return;
				}
			}else{
				cout << "seem card" << endl;
				return;
			}
		}
		if(begin > data[i])
			begin = data[i];
	}

	int boss = cards[0];
	int count = 0;
	for(int i = begin; i < len; ++i){
		if(cards[i] == 0)
			--boss;
		if(boss >= 0)
			++count;
	}
	if(count == len)
		cout << "is continous cards" << endl;
	else
		cout << "isn't continous cards" << endl;

}

int main(){
	int arr1[] = {1,3,4,5,6,0,0};
	int len1 = sizeof(arr1)/sizeof(arr1[0]);
	int arr2[] = {1,2,3,5};
	int len2 = sizeof(arr2)/sizeof(arr2[0]);

	try{
		ContinousCards(arr1, len1);
		ContinousCards(arr2, len2);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
