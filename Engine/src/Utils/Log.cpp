#include "Utils/Log.h"

#include <stdio.h>
#include <time.h>

#include "Utils/StringManip.h"

inline void PrintTimestamp()
{
    time_t now = time(nullptr);
    tm* t = localtime(&now);
    printf("%02d:%02d:%02d: ", t->tm_hour, t->tm_min, t->tm_sec);
}

inline void PrintFileInfo(const char* path, const char* func, int line)
{
    printf("[%s] ::%s:: Line: (%d): ", GetPathAfter(path, "src"), func, line);
}

void LogMsg(const char* msg)
{
    printf("%s", GREEN);
    PrintTimestamp();
    printf("%s\n", msg);
    printf("%s", RESET);
}

void LogErr(const char* msg, const std::source_location& location)
{
    printf("%s", RED);
    PrintTimestamp();
    PrintFileInfo(location.file_name(), location.function_name(), location.line());
    printf("%s\n", msg);
    printf("%s", RESET);
}