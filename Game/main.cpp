#include "DataChunk.h";
#include "Construct.h"
#include "STLAllocator.h"
#include "Math.h"
#include "Log.h"
#include <vector>
int main()
{
	std::vector<int, STLAllocator<int>> HeapVec;
	HeapVec.push_back(1);
	float val = SqrtI(2.0f);
	LOG("%f\n", val);

	return 0;
}