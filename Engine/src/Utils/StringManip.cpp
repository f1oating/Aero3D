#include "Utils/StringManip.h"

#include <string>

namespace aero3d {

std::string GetPathAfter(const char* path, const char* after)
{
    const char* found = strstr(path, after);
    if (found != nullptr)
    {
        return std::string(found + strlen(after));
    }
    return std::string(path);
}

std::string ExtractClassAndFunctionName(const char* prettyFunctionName)
{
    const char* paramsPos = strchr(prettyFunctionName, '(');
    size_t length = strlen(prettyFunctionName);

    if (paramsPos != nullptr)
    {
        length = paramsPos - prettyFunctionName;
    }

    std::string temp(prettyFunctionName, length);

    size_t spacePos = temp.rfind(' ');
    if (spacePos != std::string::npos)
    {
        return temp.substr(spacePos + 1);
    }

    return temp;
}

} // namespace aero3d