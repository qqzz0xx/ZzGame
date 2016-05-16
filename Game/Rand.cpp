#include "Rand.h"

static RandFactor g_RandFactor;

RandFactor::RandFactor()
{
	mCount = 0;
	mSeed = 0xF0F0F0F0;
	mCurSeed = mSeed;
}

void RandFactor::SRand(uint32 seed)
{
	mCurSeed = mSeed = seed;
	mCount = 0;
}

int RandFactor::Rand(void)
{
	mCount++;

	mCurSeed = mCurSeed * 214013L + 2531011L;
	return ((int)mCurSeed >> 16) & 0x7fff;
}

void RandFactor::DumpValue(uint32 & seed, uint32 & count)
{
	seed = mSeed;
	count = mCount;
}

void RandSeed(uint32 seed)
{
	g_RandFactor.SRand(seed);
}

int Rand()
{
	return g_RandFactor.Rand();
}

int RandInt(int lower, int upper)
{
	return lower + Rand() % (upper + 1 - lower);
}

int RandSimulate(uint32 seed, uint32 count)
{
	int sd = seed;
	while (count--)
	{
		sd = sd * 214013L + 2531011L;
	}

	return ((int)sd >> 16) & 0x7fff;
}
