/// \file DicesProbability.cpp
/*
  ------------------------------------
  Create date : 2015-02-08 07:13
  Modified date: 2015-02-08 07:41
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include <string.h>
#include <math.h>
#include "../libs/myException.cpp"

#define g_nMaxValue 6 //单个骰子最大点数

using namespace std;

void DicesProbability(int number){
	if(number < 1)
		throw myException("dices must more than 0");

	//一个一个骰子进行循环 需要知道上次的结果，所以需要2个数组,这样方便不需要IF判断
	int *pSum[2];
	pSum[0] = new int[number * g_nMaxValue + 1];
	pSum[1] = new int[number * g_nMaxValue + 1];
	memset(pSum[0], 0, (number*g_nMaxValue+1)*sizeof(pSum[0][0]) );
	memset(pSum[1], 0, (number*g_nMaxValue+1)*sizeof(pSum[1][0]) );

	int flag = 0;
	for(int i = 1; i <= g_nMaxValue; ++i) //第一个骰子
		pSum[flag][i] = 1;

	for(int i = 2; i <= number; ++i){	//计算剩下骰子
		for(int j = i; j <= i * g_nMaxValue; ++j){ //一个晒子可能的所有值
			pSum[1-flag][j] = 0;
			for(int k = 1; k <= j && k <= g_nMaxValue; ++k) //第I个晒子可能出现点数
				pSum[1-flag][j] += pSum[flag][j-k];
		}

		flag ^= 1;
	}

	double total = pow(g_nMaxValue, number); //总共次数
	for(int i = number; i <= number * g_nMaxValue; ++i){
		double ratio = pSum[flag][i] / total;
		cout << i << ": " << ratio << endl;
	}

	delete [] pSum[0];
	delete [] pSum[1];
}

int main(){

	try{
		cout << "input numbers of dices: ";
		int number;
		cin >> number;
		DicesProbability(number);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
