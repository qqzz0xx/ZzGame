#pragma once
#include "pch.h"
#include <stdarg.h>

#define LOG_LEVE_INFO 0
#define LOG_LEVE_WARNING 1
#define LOG_LEVE_ERROR 2

#define LOG Log
#define LOGW LogWarning
#define LOGE LogError

void Log(const char* szFormat, ...);
void LogWarning(const char *szFormat, ...);
void LogError(const char *szFormat, ...);
void LogV(int level, const char* szFormat, va_list);