#include "logger.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>

//#define MESSAGE_DEBUG_ENABLED

FILE *logFile = 0;

void initLog(const char *filename)
{
	logFile = fopen(filename, "w");
}

void _printLog(const char *buf)
{
	if (logFile) {
		fprintf(logFile, "%s", buf);
		fflush(logFile);
	}
#if MESSAGE_DEBUG_ENABLED == 1
	fprintf(stderr, "%s", buf);
#endif
}

void mylog(const char *fmt, ...)
{
	char buffer[2048];
	va_list args;
	va_start (args, fmt);

	vsprintf(buffer, fmt, args);

	_printLog(buffer);

	va_end(args);
}

