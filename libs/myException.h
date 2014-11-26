/// \file myException.h
/*
  ------------------------------------
  Create date : 2014-11-26 08:24
  Modified date: 2014-11-26 08:55
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <string>
#include <exception>

class myException : public std::exception{
	public:
		myException(const std::string &msg = "") throw();
		virtual ~myException() throw();
		const char* what() const throw();
	private:
		std::string errorMsg;
};
