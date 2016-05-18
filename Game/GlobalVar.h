#pragma once
#include "pch.h"
struct GlobalVar
{
	GlobalVar();

	uint32 GameUpdateMillisecond;
	uint32 BattleUpdateMillisecond;
};

extern GlobalVar GV;

