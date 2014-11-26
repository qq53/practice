/// \file FindInPartiallySortedMatrix.cpp
/*
  ------------------------------------
  Create date : 2014-11-23 02:38
  Modified date: 2014-11-26 09:38
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>

using namespace std;

/* 给一个数字，要找出是否在一个特殊的矩阵，类似：
 * 1 2 8 9
 * 2 4 9 12
 * 4 7 10 13
 * 6 8 11 15
 * 行方向，左到右递增
 * 列方向， 上到下递增
 * 我们肯定需要一种策略来不断缩短查找范围，经思考，左下和右上的数字可以用来
 * 比较，即可缩小范围
*/

bool Find(int *, int, int, int);

/* lower left corner is a breach
 * the upper right corner is another one */
int main(void){
	int matrix[4][4] = {
		{1,2,8,9},
		{2,4,9,12},
		{4,7,10,13},
		{6,8,11,15}
	};

	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	int fn;
	cout << "Enter a number to find:";
	cin >> fn;
	if( Find((int *)matrix, 4, 4, fn) == true)
		cout << "Found";
	else
		cout << "Not Found";
	cout << endl;

	return 0;
}

bool Find(int *matrix, int rows, int cols, int fn){
	bool found;

	if(matrix && rows > 0 && cols > 0){
		int row = rows - 1;
		int col = 0;
		while( row >= 0 && col < cols){
			if( matrix[ row * cols + col ] == fn){
				found = true;
				break;
			}else if ( matrix[ row * cols + col ] > fn)
				--row;
			else
				++col;
		}
	}

	return found;
}
