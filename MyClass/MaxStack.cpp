#include "MaxStack.h"

template<class T>
MaxStack<T>::MaxStack()
{
}

template<class T>
MaxStack<T>::~MaxStack()
{
}

template<class T>
void MaxStack<T>::Push(T t)
{
	stTotal.push(t);
	if (stMax.empty()||t>= stMax.top())
	{
		stMax.push(t);
	}
}

template<class T>
void MaxStack<T>::Pop()
{
	if (!stTotal.empty())
	{
		if (stMax.top()==stTotal.top())
		{
			stMax.pop();
		}
		stTotal.pop();
	}
}

template<class T>
size_t MaxStack<T>::Size()
{
	return stTotal.size() + stMax.size();
}

template<class T>
bool MaxStack<T>::Empty()
{
	return stTotal.empty() && stMax.empty();
}


template<class T>
T MaxStack<T>::Top()
{
	return stTotal.top();
}


template<class T>
T MaxStack<T>::MaxElem()
{
	if (!stMax.empty())
	{
		return stMax.top();
	}
	return INT_MIN;
}

