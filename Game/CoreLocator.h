#pragma once
#include "Battle.h"
class CoreLocator
{
public:
	Battle* mBattle;
	bool Init();
	void Destroy();
	CoreLocator();
	~CoreLocator();

};

