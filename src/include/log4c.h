#ifndef LOG4C_H
#define LOG4C_H

#include <stdio.h>
#include <string.h>

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

enum Log4CLevel {
  LOG4C_ALL     = 0,
  LOG4C_TRACE   = 1,
  LOG4C_DEBUG   = 2,
  LOG4C_INFO    = 3,
  LOG4C_WARNING = 4,
  LOG4C_ERROR   = 5,
  LOG4C_OFF     = 6
};

static const char* LOG_NAME[] = {"ALL",
                                 "TRACE",
                                 "DEBUG",
                                 "INFO",
                                 "WARN",
                                 "ERROR",
                                 "OFF"};

extern int log4c_level;

#define LOG(level, fmt, ...) \
  if (level >= log4c_level) { \
    fprintf(stderr, \
            "[%5s] %s @ %-15s#%4d: " fmt "\n", \
            LOG_NAME[level], \
            __func__, \
            __FILENAME__, \
            __LINE__, \
            ##__VA_ARGS__); \
  }

#endif
