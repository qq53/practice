/// \file PrintMartixOfClockwise.cpp
/*
  ------------------------------------
  Create date : 2015-01-20 21:41
  Modified date: 2015-01-21 00:23
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include "../libs/myException.cpp"

using namespace std;

void PrintMartixOfClockwise(int **array, int rows, int columns){
	int x = 0, y = 0;
	int count = 0;
	int (*martix)[columns] = (int(*)[columns])array;

	if(rows == 1){
		for(; y < columns; ++y)
			cout << martix[0][y] << " ";
		cout << endl;
		return;
	}
	if(columns == 1){
		for(; x < rows; ++x)
			cout << martix[x][0] << " ";
		cout << endl;
		return;
	}
	while(x >= count && x < rows-count && y >= count && y <= columns-count){
		for(; y < columns - count; ++y){
			cout << martix[x][y] << " ";
		}
		for(++x, --y; x < rows - count; ++x){
			cout << martix[x][y] << " ";
		}
		for(--y, --x; y >= count; --y){
			cout << martix[x][y] << " ";
		}
		for(--x, ++y; x > count; --x){
			cout << martix[x][y] << " ";
		}
		++count;
		++x;
		++y;
		cout << endl;
	}
}

int main(){
	int r = 4, c = 4;
	int martix[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

	try{
		PrintMartixOfClockwise((int**)martix, r, c);
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
