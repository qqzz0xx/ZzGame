#include "DataChunk.h"

#include "pch.h"

DataChunk::DataChunk()
{
	mDataSize = kDataSize;
	mCurBlock = NULL;
	mRecycleBlock = NULL;
	mMaxAllocSize = 0;
	mMaxUseSize = 0;
	mAllocSize = 0;
	mUseSize = 0;
}

DataChunk::~DataChunk()
{
	FreeBlocks();
}

DataChunk::DataBlock * DataChunk::AllocBlocks()
{
	if (mRecycleBlock)
	{
		DataBlock* ret = mRecycleBlock;
		mRecycleBlock = mRecycleBlock->next;
		return ret;
	}
	else
	{
		size_t mallocSize = sizeof(DataBlock) + mDataSize;
		mAllocSize += mAllocSize;
		mMaxAllocSize = __max(mMaxAllocSize, mAllocSize);
		return (DataBlock*)malloc(mallocSize);
	}
}

void* DataChunk::Alloc(size_t n)
{
	assert(n <= mDataSize);
	
	if (mCurBlock == NULL || mCurBlock->use + n > mDataSize)
	{
		DataBlock* block = AllocBlocks();
		block->use = 0;
		block->next = mCurBlock;
		mCurBlock = block;
	}

	void* ret = (void*)mCurBlock->data[mCurBlock->use];
	mCurBlock->use += n;
	mUseSize += n;
	mMaxUseSize = __max(mMaxUseSize, mUseSize);

	return ret;
}

void DataChunk::FreeBlocks()
{
	while (mCurBlock)
	{
		DataBlock* block = mCurBlock;
		mCurBlock = mCurBlock->next;
		free(block);
	}
	while (mRecycleBlock)
	{
		DataBlock* block = mRecycleBlock;
		mRecycleBlock = mRecycleBlock->next;
		free(block);
	}
	mAllocSize = 0;
	mUseSize = 0;
}

void DataChunk::RecycleBlocks()
{
	while (mCurBlock)
	{
		DataBlock* block = mCurBlock;
		mRecycleBlock = block;
		mRecycleBlock->next = mCurBlock->next;
		mCurBlock = mCurBlock->next;
	}
	mUseSize = 0;
}
