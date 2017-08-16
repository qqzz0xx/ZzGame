#include "Battle.h"
#include "STLAllocator.h"
#include "Timer.h"
#include "GlobalVar.h"
#include "Log.h"

void Battle::EnterFrame()
{
	FrameAllocator::Instance()->RecycleBlocks();
}

void Battle::FrameTick()
{
	
}

void Battle::ExitFrame()
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
		EnterFrame();
		FrameTick();
		ExitFrame();
		mSumTime -= GV.BattleUpdateMillisecond;
	}
	mPrevTime = mCurTime;
}

void Battle::Destroy()
{
}
