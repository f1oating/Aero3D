#include "Utils/Log.h"

#include <iostream>
#include <chrono>
#include <format>

#include "Utils/StringManip.h"

namespace aero3d {

inline void PrintTimestamp()
{
    auto now = std::chrono::system_clock::now();
    auto now_sec = std::chrono::floor<std::chrono::seconds>(now);
    std::cout << std::format("{}[{:%H:%M:%S}]: {}", WHITE, now_sec, RESET);
}

inline void PrintFileInfo(std::string_view path, std::string_view func, int line)
{
    std::cout << std::format("{}[{}] ({}) Line: ({}): {}",
        RED,
        GetPathAfter(path.data(), "src"),
        ExtractClassAndFunctionName(func),
        line,
        RESET);
}

void LogMsg(std::string_view msg)
{
    PrintTimestamp();
    std::cout << std::format("{}{}{}\n",
        GREEN,
        msg,
        RESET);
}

void LogErr(std::string_view msg,
    const std::source_location& location)
{
    PrintTimestamp();
    PrintFileInfo(location.file_name(), location.function_name(), location.line());
    std::cout << std::format("{}{}{}\n",
        RED,
        msg,
        RESET);
}

void LogErr(std::string_view msg, std::string_view file,
    std::string_view func, int line)
{
    PrintTimestamp();
    PrintFileInfo(file, func, line);
    std::cout << std::format("{}{}{}\n",
        RED,
        msg,
        RESET);
}

} // namespace aero3d