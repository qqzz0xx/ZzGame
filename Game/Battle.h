#pragma once
#include "pch.h"
class Battle
{
private:
	void StartUpdate();
	void FrameTick();
	void ExitUpdate();
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

