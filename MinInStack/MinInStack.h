/// \file MinInStack.h
/*
  ------------------------------------
  Create date : 2015-01-21 15:30
  Modified date: 2015-01-21 18:44
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <stack>

template <typename T> class StackWithMin{
private:
	std::stack<T> m_data;
	std::stack<T> m_min;

public:
	StackWithMin(){}
	virtual ~StackWithMin(){}

	void push(const T& value);
	void pop();

	T& top();
	const T& top() const;

	const T& min() const;

	bool empty() const;
	size_t size() const;
};

template <typename T> void StackWithMin<T>::push(const T& value){
	m_data.push(value);

	if(m_min.size() == 0 || value < m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());
}

template <typename T> void StackWithMin<T>::pop(){
	if(m_data.size() <= 0 || m_min.size() <= 0)
		throw myException("stack no element");

	m_data.pop();
	m_min.pop();
}

template <typename T> T& StackWithMin<T>::top(){
	return m_data.top();
}

template <typename T> const T& StackWithMin<T>::top() const{
	return m_data.top();
}

template <typename T> const T& StackWithMin<T>::min() const{
	if(m_min.size() <= 0)
		throw myException("no min");
	return m_min.top();
}

template <typename T> bool StackWithMin<T>::empty() const{
	return m_data.empty();
}

template <typename T> size_t StackWithMin<T>::size() const{
	return m_data.size();
}
