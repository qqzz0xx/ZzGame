#include "Game.h"
#include "Timer.h"
#include "GlobalVar.h"
#include "Log.h"

void Game::Run()
{
	if (!Init()) return;

	do {
		mCurTime = Timer::GetTimeTick();
		mSumTime += mCurTime - mPrevTime;
		if (mSumTime > GV.GameUpdateMillisecond)
		{
			EnterFrame();
			FrameTick();
			ExitFrame();
			mSumTime -= GV.GameUpdateMillisecond;
		}
		else
		{
			Timer::Sleep(1);
		}
		mPrevTime = mCurTime;

	} while (true);

	Destroy();
}

Game::Game()
{
	mLocator = new CoreLocator();
}

bool Game::Init()
{
	mLocator->Init();
	return true;
}

void Game::EnterFrame()
{
}

void Game::ExitFrame()
{
}

void Game::FrameTick()
{
	
}


void Game::Destroy()
{
	delete mLocator;
}
