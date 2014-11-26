/// \file myException.cpp
/*
  ------------------------------------
  Create date : 2014-11-26 08:46
  Modified date: 2014-11-26 08:55
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include "myException.h"

myException::myException(const std::string &msg) throw(){
	errorMsg = msg;
}

myException::~myException() throw()
{}

const char * myException::what() const throw(){
	return errorMsg.c_str();
}
