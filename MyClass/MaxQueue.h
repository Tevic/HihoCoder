#pragma once
#include "../Head.h"
#include "MaxStack.h"

template<class T>
class MaxQueue
{
public:
	MaxQueue();
	~MaxQueue();
	void EnQueue(T t);
	void DeQueue();
	size_t Size();
	T MaxElem();

private:
	MaxStack<T> stIn;
	MaxStack<T> stOut;
};
