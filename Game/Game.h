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
	void Update();
	void StartUpdate();
	void FrameTick();
	void ExitUpdate();
	void Destroy();

private:
	uint32 mCurTime;
	uint32 mPrevTime;
	uint32 mFrameIntervalTime;
	uint32 mSumTime;
};

