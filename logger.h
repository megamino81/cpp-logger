#ifndef __LOGGER_H__
#define __LOGGER_H__

#define MESSAGE_DEBUG_ENABLED 0

void initLog(const char *filename);
void mylog(const char *fmt, ...);

#endif
