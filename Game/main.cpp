#include "DataChunk.h";
#include "Construct.h"
#include "STLAllocator.h"
#include <vector>
int main()
{
	std::vector<int, STLAllocator<int>> HeapVec;
	HeapVec.push_back(1);
	exit(0);
}