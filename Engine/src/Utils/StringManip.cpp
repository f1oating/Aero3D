#include "Utils/StringManip.h"

inline std::string GetPathAfter(std::string_view path, std::string_view after)
{
    if (auto pos = path.find(after); pos != std::string_view::npos)
    {
        return std::string(path.substr(pos + after.length()));
    }
    return std::string(path);
}