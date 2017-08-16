#include "DataChunk.h";
#include "Construct.h"
#include "STLAllocator.h"
#include "Math.h"
#include "Log.h"
#include <vector>
#include "Game.h"
#include "Vector3I.h"
int main()
{
	std::vector<int, STLAllocator<int, GlobalAllocator>> HeapVec;
	HeapVec.push_back(1);
	Vector3I* p = (Vector3I*)GlobalAllocator::Instance()->Alloc(sizeof(Vector3I));
	Construct(p);

	auto p2 = New<Vector3I>();
	
	LOG("%d\n", p2->x);
	FrameAllocatorInst()->FreeBlocks();
	LOG("%d\n", p2->x);


	float val = SqrtI(2.0f);
	LOG("%f\n", val);

	Game::getInstance()->Run();


	return 0;
}