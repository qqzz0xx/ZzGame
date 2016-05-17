#include "Log.h"

const char* PREFIX[3] = { "INFO: ", "WARNING: ", "ERROR: " };

void Log(const char * szFormat, ...)
{
	va_list args;
	va_start(args, szFormat);
	LogV(LOG_LEVE_INFO, szFormat, args);
	va_end(args);
}

void LogWarning(const char * szFormat, ...)
{
	va_list args;
	va_start(args, szFormat);
	LogV(LOG_LEVE_WARNING, szFormat, args);
	va_end(args);
}

void LogError(const char * szFormat, ...)
{
	va_list args;
	va_start(args, szFormat);
	LogV(LOG_LEVE_ERROR, szFormat, args);
	va_end(args);
}

void LogV(int level, const char* szFormat, va_list agrs)
{
	char buf[1024];
	const char* pre = PREFIX[level];
	strcpy(buf, pre);
	size_t preLen = strlen(pre);
	snprintf(&buf[preLen], 1023 - preLen, szFormat, agrs);
	buf[1023] = 0;
	printf(buf);
}