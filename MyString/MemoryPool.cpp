#include "MemoryPool.h"

MemoryPool::MemoryPool(int nCount)
{
	if (nCount <= 0)
	{
		return;
	}
	for (size_t i = 0; i < nCount; i++)
	{
		char* pBlock = new char[iBlockSize];
		freeList.push_back(pBlock);
	}
}

MemoryPool::~MemoryPool()
{
	for (auto pBlock : freeList)
	{
		delete[] pBlock;
	}
	for (auto pBlock : usedList)
	{
		delete[] pBlock;
	}
}

void* MemoryPool::Alloc()
{
	if (freeList.size()>0)
	{
		void* pBlock = *freeList.begin();
		freeList.pop_front();
		usedList.insert(pBlock);
		return pBlock;
	}
	else
	{
		return nullptr;
	}
}

void MemoryPool::Free(void* pBlock)
{
	auto pBlockFind = usedList.find(pBlock);
	if (pBlockFind != usedList.end())
	{
		freeList.push_back(*pBlockFind);
		usedList.erase(pBlockFind);
	}
}

int MemoryPool::GetFreeBlockCount()
{
	return freeList.size();
}

int MemoryPool::GetUsedBlockCount()
{
	return usedList.size();
}