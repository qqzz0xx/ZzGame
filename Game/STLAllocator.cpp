#include "STLAllocator.h"

DataChunk g_FrameDataChunk;
DataChunk g_GlobalDataChunk;
DataChunk * HeapAllocator::Instance()
{
	return nullptr;
}

DataChunk * FrameAllocator::Instance()
{
	return &g_FrameDataChunk;
}

DataChunk * GlobalAllocator::Instance()
{
	return &g_GlobalDataChunk;
}

DataChunk * FrameAllocator()
{
	return &g_FrameDataChunk;
}

DataChunk * GlobalAllocator()
{
	return &g_GlobalDataChunk;
}

bool TestSTLAllocator()
{
	return false;
}
