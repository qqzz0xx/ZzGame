#pragma once
#include "Platform.h"
#ifdef PLATFORM_WINDOWS

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif

#ifndef WINVER
#define WINVER 0x0500
#endif

#ifndef _WIN32_IE
#define _WIN32_IE 0x0500
#endif

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0410
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#endif

// CRT
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <clocale>
#include <malloc.h>
#include <mbstring.h>
#include <string.h>
#include <tchar.h>

// STL containers
#include <vector>
#include <map>
#include <string>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

// STL algorithms & functions
#include <algorithm>
#include <functional>
#include <limits>

#elif defined(PLATFORM_LINUX) || defined(PLATFORM_ANDROID)
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <errno.h>
#include <new>
#include <math.h>

#elif defined(PLATFORM_MAC)

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <errno.h>
#include <new>
#include <math.h>

#endif

#ifdef PLATFORM_WINDOWS
#define EXPORT_API __declspec(dllexport)
#undef snprintf
#undef SNPRINTF
#undef STDCALL
#define snprintf _snprintf
#define SNPRINTF _vsnprintf
#define STDCALL	__stdcall
#else
#define EXPORT_API
#define snprintf snprintf
#define SNPRINTF vsnprintf
#define STDCALL
#endif

// type
typedef unsigned char		uint8;
typedef unsigned short		uint16;
typedef unsigned int		uint32;
#ifdef PLATFORM_WINDOWS
typedef unsigned __int64	uint64;
#else
typedef unsigned long long	uint64;
#endif
typedef signed char			int8;
typedef signed short		int16;
typedef signed int			int32;
#ifdef PLATFORM_WINDOWS
typedef signed __int64		int64;
#else
typedef long long			int64;
#endif
typedef unsigned char		uchar;
typedef unsigned short		ushort;
typedef unsigned int		uint;
typedef unsigned long		ulong;

// 浮点定点转换
#define POINT_UNIT			10000
#define FLOAT2FIXED(x)		((int64)(x * (float)POINT_UNIT))
#define FIXED2FLOAT(x)		((float)x / (float)POINT_UNIT)


