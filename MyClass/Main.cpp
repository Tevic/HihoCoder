#include "MyString.h"
#include "MemoryPool.h"
#include "../GlobalFunc.h"

int main()
{
	MemoryPool mp(111);
	void* p=mp.Alloc();
	return 0;
}