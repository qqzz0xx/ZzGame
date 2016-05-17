#pragma once
#include "pch.h"
class DataChunk
{
private:
	enum
	{
		kDataSize = 1024
	};
private:
	struct DataBlock
	{
		DataBlock* next;
		size_t use;
		uint8 data[0];
	};

	DataBlock* mCurBlock;
	DataBlock* mRecycleBlock;
	size_t mDataSize;
	size_t mMaxAllocSize;
	size_t mMaxUseSize;
	size_t mUseSize;
	size_t mAllocSize;
	DataBlock* AllocBlocks();
public:
	DataChunk();
	~DataChunk();
	bool Init(size_t dataSize) { mDataSize = dataSize; return true; }
	void* Alloc(size_t n);
	void FreeBlocks();
	void RecycleBlocks();

	size_t GetMaxAllocSize() const { return mMaxAllocSize; }
	size_t GetMaxUseSize() const { return mMaxUseSize; }
	size_t GetAllocSize() const { return mAllocSize; }
	size_t GetUseSize() const { return mUseSize; }
};

