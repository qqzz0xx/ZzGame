#include "Math.h"

int64 SqrtI(int64 value)
{
	if (value < 0) value = -value;
	uint64 ret_max = value;
	uint64 ret_next = value;
	uint64 precision = 4;
	do {
		ret_max = ret_next;
		ret_next = (ret_next + value / ret_next) / 2;
	} while (ret_max - ret_next > 4);

	return ret_next;
}

float SqrtF(float value)
{
	return FIXED2FLOAT( SqrtI((int64)(value * POINT_UNIT * POINT_UNIT)) );
}

int64 RSqrtI(int64 value)
{
	return 1 / SqrtI(value);
}

int64 LerpI(int64 from, int64 to, int64 factor)
{
	return from * (POINT_UNIT - factor) + to * factor;
}

int64 LerpF(int64 from, int64 to, float factor)
{
	int64 ifactor = FLOAT2FIXED(factor);
	return Lerp(from, to, ifactor);
}
