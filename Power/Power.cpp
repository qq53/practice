/// \file Power.cpp
/*
  ------------------------------------
  Create date : 2014-12-08 15:40
  Modified date: 2014-12-08 15:54
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/

#include <iostream>

#include "../libs/myException.cpp"

using namespace std;

double Power(double base, int exponent);

int main(){
	try{
		cout << Power(6, 4) << endl;
	}catch(myException &e){
		cout << e.what(); << endl;
	}
	return 0;
}

bool equal(double a, double b){
	if( ( a - b > -0.0000001 ) &&
			( a - b < 0.0000001) )
		return true;
	else
		return false;
}

double PowerN(double base, unsigned int exponent){
	if(exponent == 0)
		return 1.0;
	if(exponent == 1)
		return base;

	double result = PowerN(base, exponent >> 1);
	result *= result;
	if(exponent & 1 == 1)
		result *= base;

	return result;
}

double Power(double base, int exponent){
	if(	equal(base, 0.0) )
		throw myException("base invalid");
	if( exponent < 0 )
		throw myException("exponent invalid");

	unsigned int absExponent = exponent;
	if ( exponent < 0 )
		absExponent = -exponent;

	double result = PowerN(base, exponent);
	if(exponent < 0)
		result = 1.0 / result;

	return result;
}
