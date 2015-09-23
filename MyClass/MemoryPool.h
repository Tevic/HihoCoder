#pragma once
#include "../Head.h"

class MemoryPool
{
public:
	MemoryPool(int nCount);
	~MemoryPool();
	void* Alloc();
	void Free(void* pBlock);
	int GetFreeBlockCount();
	int GetUsedBlockCount();
private:
	list<void*> freeList;
	unordered_set<void*> usedList;
	int iBlockSize = 4;
};

