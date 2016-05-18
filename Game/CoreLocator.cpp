#include "CoreLocator.h"

bool CoreLocator::Init()
{
	mBattle->Init();
	return true;
}

void CoreLocator::Destroy()
{
	delete mBattle;
}

CoreLocator::CoreLocator()
{
	mBattle = new Battle();
}


CoreLocator::~CoreLocator()
{
	Destroy();
}
