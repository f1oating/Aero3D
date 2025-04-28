#include "Utils/Log.h"

#include <stdio.h>
#include <time.h>
#include <stdarg.h>

#include "Utils/StringManip.h"

#ifdef A3D_PLATFORM_WINDOWS
    #define A3D_LOCALTIME(a, b) localtime_s(b, a)
#else
    #define A3D_LOCALTIME(a, b) localtime_r(a, b)
#endif

namespace aero3d {

inline void PrintTimestamp()
{
    time_t now = time(NULL);
    tm localTime;

    A3D_LOCALTIME(&now, &localTime);

    printf("%s[%02d:%02d:%02d]: %s",
        WHITE,
        localTime.tm_hour,
        localTime.tm_min,
        localTime.tm_sec,
        RESET
    );
}

inline void PrintFileInfo(const char* path, const char* func, int line)
{
    printf("%s[%s] (%s) Line: (%d): %s",
        RED,
        GetPathAfter(path, "src"),
        ExtractClassAndFunctionName(func),
        line,
        RESET);
}

void LogMsg(const char* fmt, ...)
{
    PrintTimestamp();
    char buffer[1024];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    printf("%s %s %s\n", GREEN, buffer, RESET);
}

void LogErr(const char* file, const char* func, int line, 
    const char* fmt, ...)
{
    PrintTimestamp();
    PrintFileInfo(file, func, line);
    char buffer[1024];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    printf("%s %s %s\n", RED, buffer, RESET);
}

} // namespace aero3d