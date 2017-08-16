#pragma once
#include "pch.h"
class Battle
{
private:
	void EnterFrame();
	void FrameTick();
	void ExitFrame();
public:
	Battle();
	~Battle();
	bool Init();
	void Update();
	void Destroy();
private:
	uint32 mCurTime;
	uint32 mPrevTime;
	uint32 mFrameIntervalTime;
	uint32 mSumTime;
};

