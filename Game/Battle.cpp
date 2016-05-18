#include "Battle.h"
#include "STLAllocator.h"
#include "Timer.h"
#include "GlobalVar.h"
#include "Log.h"

void Battle::StartUpdate()
{
	FrameAllocator::Instance()->RecycleBlocks();
}

void Battle::FrameTick()
{
	
}

void Battle::ExitUpdate()
{
	FrameAllocator::Instance()->RecycleBlocks();
}

Battle::Battle()
{
	LOG("battle construct");
}


Battle::~Battle()
{
	LOG("battle destory");
}

bool Battle::Init()
{
	return false;
}

void Battle::Update()
{
	mCurTime = Timer::GetTimeTick();
	mSumTime += mCurTime - mPrevTime;
	if (mSumTime > GV.BattleUpdateMillisecond)
	{
		StartUpdate();
		FrameTick();
		ExitUpdate();
		mSumTime -= GV.BattleUpdateMillisecond;
	}
	mPrevTime = mCurTime;
}

void Battle::Destroy()
{
}
