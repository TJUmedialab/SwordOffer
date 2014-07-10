#include <iostream>
#include <assert.h>
#include <stack>
using namespace std;

template <typename T>
class CQueue
{
public:
	CQueue();
	~CQueue();

	void appendTail(const T& node);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};

