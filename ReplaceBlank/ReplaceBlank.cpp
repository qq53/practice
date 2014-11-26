/// \file ReplaceBlank.cpp
/*
  ------------------------------------
  Create date : 2014-11-23 14:57
  Modified date: 2014-11-26 09:42
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include <string.h>

using namespace std;

/*
 * 替换字符串中的空格成%20,用于html编码，保证传输安全
 * 若按照一边替一边移动整个字符串效率会很低，提前统计出
 * 空格个数，知道新字符串的长度，然后从后到前类似“尾插”那样
 * 替换，只需O(n)就可以
*/
void Replace(char *, int);

int main(void){

	char str[100];
	memset(str, 0 ,100);
	cout << "Enter string:";
	cin.get(str, 100);

	Replace(str, 100);

	return 0;
}

void Replace(char *str, int n){
	if(!str || n <= 0)
		return ;
	int blank = 0;
	int i;
	for(i = 0; str[i] != '\0'; ++i){
		if(str[i] == ' ')
			++blank;
	}
	int originalLen = i;
	int newLen = originalLen + blank * 2;
	char newStr[newLen + 1];
	int j = newLen;
	for(; i >= 0; --i){
		if(str[i] == ' '){
			newStr[j] = '0';
			newStr[--j] = '2';
			newStr[--j] = '%';
		}else
			newStr[j] = str[i]; 
		--j;
	}
	cout << newStr << endl;
}
