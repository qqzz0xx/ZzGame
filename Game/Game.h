#pragma once
#include "pch.h"
#include "Singleton.h"
#include "CoreLocator.h"
class Game : public Singleton<Game>
{
public:
	Game();
	CoreLocator *mLocator;
	void Run();
private:
	bool Init();

	void EnterFrame();
	void FrameTick();
	void ExitFrame();
	void Destroy();

private:
	uint32 mCurTime;
	uint32 mPrevTime;
	uint32 mFrameIntervalTime;
	uint32 mSumTime;
};

