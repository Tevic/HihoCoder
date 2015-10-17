#include "MyString.h"
#include "MemoryPool.h"
#include "MaxQueue.cpp"
#include "MaxStack.cpp"
#include "../GlobalFunc.h"

int main()
{
	MaxQueue<int> maxQ;
	maxQ.EnQueue(1);
	cout << maxQ.MaxElem() << endl;
	maxQ.EnQueue(4);
	cout << maxQ.MaxElem() << endl;
	maxQ.EnQueue(2);
	cout << maxQ.MaxElem() << endl;
	maxQ.EnQueue(2);
	cout << maxQ.MaxElem() << endl;
	//maxQ.EnQueue(5);
	//cout << maxQ.MaxElem() << endl;
	maxQ.DeQueue();
	cout << maxQ.MaxElem() << endl;
	maxQ.DeQueue();
	cout << maxQ.MaxElem() << endl;
	return 0;
}