#include <iostream>
#include <assert.h>
#include <stack>
using namespace std;

template <typename T>
class CQueue
{
public:
	void appendTail(const T& node);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};

template <typename T>
void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}

template <typename T>
T CQueue<T>::deleteHead()
{
	T temp;
	if ( stack2.empty() ) {
		while ( !stack1.empty() ) {
			temp = stack1.top();
			stack2.push(temp);
			stack1.pop();
		}
	}
	if ( stack2.empty() ) {
		cerr << "the list is empty, cannot out list\n";
		exit(0);
	}
	temp = stack2.top();
	stack2.pop();
	return temp;
}
int main(int argc, char* argv[])
{
	CQueue<int> m_queue;
	for (int i = 0; i < 10; i ++) {
		m_queue.appendTail(i);
	}
	for (int i = 0; i < 10; i ++) {
		cout << m_queue.deleteHead() << endl;
	}
	return 0;
}