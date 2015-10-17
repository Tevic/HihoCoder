#pragma once
#include "../Head.h"

template<class T>
class MaxStack
{
public:
	MaxStack();
	~MaxStack();
	void Push(T t);
	void Pop();
	T MaxElem();
	size_t Size();
	bool Empty();
	T Top();

private:
	stack<T> stTotal;
	stack<T> stMax;
};

