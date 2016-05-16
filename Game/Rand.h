#pragma once
#include "pch.h"
class RandFactor
{
public:
	RandFactor();

	void SRand(uint32 seed);
	int Rand(void);
	void DumpValue(uint32 &seed, uint32 &count);

private:
	uint32 mCount;
	uint32 mSeed;
	uint32 mCurSeed;

};

void RandSeed(uint32 seed);
int Rand();
int RandInt(int lower, int upper);
