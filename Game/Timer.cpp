#include "Timer.h"

#ifdef PLATFORM_WINDOWS
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#elif defined(PLATFORM_ANDROID) 
#include <time.h>
#elif defined(PLATFORM_LINUX)
#include <sys/time.h>
#include <unistd.h>
#else
#include <sys/time.h>
#include <unistd.h>

#endif

Timer::Timer()
{
}

uint32 Timer::GetTimeTick()
{
#ifdef PLATFORM_WINDOWS
	return timeGetTime();
#elif defined(PLATFORM_ANDROID)
	uint32 uptime = 0;
	struct timespec on;
	if (clock_gettime(CLOCK_MONOTONIC, &on) == 0)
		uptime = on.tv_sec * 1000 + on.tv_nsec / 1000000;

	return uptime;
#elif defined(PLATFORM_LINUX)
	uint32 uptime = 0;
	struct timeval on;
	if (gettimeofday(&on, NULL) == 0)
		uptime = on.tv_sec * 1000 + on.tv_usec / 1000;

	return uptime;

#else

	uint32 uptime = 0;
	struct timeval on;
	if (gettimeofday(&on, NULL) == 0)
		uptime = (uint32)on.tv_sec * 1000 + (uint32)on.tv_usec / 1000;

	return uptime;


#endif
}

void Timer::Sleep(uint32 time)
{
#ifdef PLATFORM_WINDOWS
	Sleep(time * 1000);
#else
	sleep(time);
#endif
}

