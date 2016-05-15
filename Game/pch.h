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
#include <hash_set>
#include <hash_map>

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

#define STL_TEMPLATE_MEMBER(_Ty) \
	typedef _Ty value_type;\
	typedef value_type *pointer;\
	typedef value_type &reference;\
	typedef const value_type *const_pointer;\
	typedef const value_type &const_reference;\
	typedef size_t size_type;\
	typedef int difference_type;

#define DECLARE_STL_TEMPLATE_MEMBER STL_TEMPLATE_MEMBER(_Ty)

template<class _Ty>
bool TYPE_TRAITS_IS_BUILT_IN_TYPE(_Ty ty)
{
	return false;
}


