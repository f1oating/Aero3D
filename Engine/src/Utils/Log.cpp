#include "Utils/Log.h"

#include <stdio.h>
#include <time.h>

inline void PrintTimestamp()
{
    time_t now = time(nullptr);
    tm* t = localtime(&now);
    printf("%02d:%02d:%02d", t->tm_hour, t->tm_min, t->tm_sec);
}

void LogMsg(const char* msg)
{
    printf("%s", GREEN);
    PrintTimestamp();
    printf(": %s\n", msg);
    printf("%s", RESET);
}

void LogErr(const char* msg)
{
    printf("%s", RED);
    PrintTimestamp();
    printf(": %s\n", msg);
    printf("%s", RESET);
}