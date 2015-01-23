/// \file SequenceOfBST.cpp
/*
  ------------------------------------
  Create date : 2015-01-24 00:21
  Modified date: 2015-01-24 00:37
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>
#include "../libs/myException.cpp"

using namespace std;

bool VerifySequenceOfBST(int *seq, int len){
	if(seq == NULL || len <= 0)
		throw myException("param error");

	int root = seq[len-1];

	int i;
	for(i = 0; i < len-1; ++i)
		if(seq[i] > root)
			break;
	int j;
	for(j = i; j < len-1; ++j)
		if(seq[j] < root)
			return false;

	bool left = true;
	if(i > 0)
		left = VerifySequenceOfBST(seq, i);

	bool right = true;
	if(j < len-1)
		right = VerifySequenceOfBST(seq + i, len-i-1);

	return (left && right);
}

int main(){
	int seq1[] = {4,5,2,6,7,3,1};
	int len1 = sizeof(seq1)/sizeof(seq1[0]);
	int seq2[] = {7,4,6,5};
	int len2 = sizeof(seq2)/sizeof(seq2[0]);
	try{
		cout << VerifySequenceOfBST(seq1, len1) << endl;
		cout << VerifySequenceOfBST(seq2, len2) << endl;
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}
