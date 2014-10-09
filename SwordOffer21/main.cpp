// stack with min
#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;

template <typename T>
class StackWithMin{
private:
       stack<T> data;
       stack<T> data_min;
public:
       void push(T value);
       void pop();
       T getMinValue();
};

template <typename T>
void StackWithMin<T> :: push(T value){
	data.push(value);
	if( data_min.size()==0 || data_min.top()>value ) {
		data_min.push(value);
	}else {
		data_min.push(data_min.top());
	}
}
template <typename T>
void StackWithMin<T> :: pop(){
	if( data.size() > 0 ) {
		data.pop();
		data_min.pop();
	}
} 

template <typename T>
T StackWithMin<T> :: getMinValue(){
	if ( data.size() > 0  ) {
		return data_min.top();
	}
}

int main()
{
	StackWithMin<int> a;
	a.push(100);
	cout << a.getMinValue() << endl;
	a.push(200);
	cout << a.getMinValue() << endl;
	a.push(40);
	cout << a.getMinValue() << endl;
	a.pop();
	cout << a.getMinValue() << endl;
	return 0;
}
