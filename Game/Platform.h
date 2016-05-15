#pragma once


// ȷ��Ŀ��ƽ̨
// Windowsƽ̨
#if (defined(_WIN32) || defined(_WIN64))
#if _MSC_VER >= 1400
#ifndef _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#endif
#ifndef _CRT_NON_CONFORMING_SWPRINTFS
#define _CRT_NON_CONFORMING_SWPRINTFS
#endif
#endif
#define PLATFORM_WINDOWS

//	#error "Windows Platform"
#endif

// Androidƽ̨
#if defined(ANDROID_API)
#define PLATFORM_ANDROID
#define OS_CLIENT
#define LOG_OPTION_ANDROID
//	#error "Android Platform"
#endif

// Macƽ̨
#if defined(__APPLE__)
#define PLATFORM_MAC
#define OS_CLIENT
#define LOG_OPTION_CONSOLE
//	#error "Mac Platform"
#endif

// Linuxƽ̨
#if defined(LINUX)
#define PLATFORM_LINUX
#define OS_SERVER
//	#error "Linux Platform"
#endif

#define INLINE	inline


