#include "MaxQueue.h"

template<class T>
MaxQueue<T>::MaxQueue()
{

}

template<class T>
MaxQueue<T>::~MaxQueue()
{
}

template<class T>
void MaxQueue<T>::EnQueue(T t)
{
	stIn.Push(t);
}

template<class T>
void MaxQueue<T>::DeQueue()
{
	if (!stOut.Empty())
	{
		stOut.Pop();
	}
	else
	{
		while (!stIn.Empty())
		{
			stOut.Push(stIn.Top());
			stIn.Pop();
		}
		if (!stOut.Empty())
		{
			stOut.Pop();
		}
	}
}

template<class T>
size_t MaxQueue<T>::Size()
{
	return stIn.Size() + stOut.Size();
}

template<class T>
T MaxQueue<T>::MaxElem()
{
	return max(stIn.MaxElem(),stOut.MaxElem());
}