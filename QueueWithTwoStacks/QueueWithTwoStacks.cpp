/// \file QueueWithTwoStacks.cpp
/*
  ------------------------------------
  Create date : 2014-11-30 14:54
  Modified date: 2014-11-30 15:16
  Author : Sen1993
  Email : gsen1993@gmail.com
  ------------------------------------
*/
#include <iostream>
#include <stack>

#include "../libs/myException.cpp"

using namespace std;

template <typename T> class stackQueue{
	public:
		stackQueue();
		~stackQueue();

		void EnQueue(const T &);
		T OutQueue();

	private:
		stack<T> stack1;
		stack<T> stack2;
};

int main(){
	stackQueue<int> sq;

	try{
		sq.EnQueue(1);
		sq.EnQueue(2);
		cout << sq.OutQueue() << endl;
		sq.EnQueue(3);
		cout << sq.OutQueue() << endl;
		cout << sq.OutQueue() << endl;
		cout << sq.OutQueue() << endl;
	}catch(myException &e){
		cout << e.what() << endl;
	}

	return 0;
}

template <typename T> stackQueue<T>::stackQueue(){
}
template <typename T> stackQueue<T>::~stackQueue(){
}

template<typename T> void stackQueue<T>::EnQueue(const T &v){
	stack1.push(v);
}

template<typename T> T stackQueue<T>::OutQueue(){
	if(stack2.size() <= 0){
		while(stack1.size() > 0){
			T& v = stack1.top();
			
			stack1.pop();
			stack2.push(v);
		}
	}
	if(stack2.size() <= 0)
		throw myException("queue is empty");

	T head = stack2.top();
	stack2.pop();

	return head;
}
