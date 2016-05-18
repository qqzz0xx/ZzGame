#pragma once
#include "pch.h"
class Timer
{
public:
	Timer();
	static uint32 GetTimeTick();
	static void Sleep(uint32 time);
};

