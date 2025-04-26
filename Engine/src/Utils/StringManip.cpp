#include "Utils/StringManip.h"

namespace aero3d {

std::string GetPathAfter(std::string_view path, std::string_view after)
{
    if (auto pos = path.find(after); pos != std::string_view::npos)
    {
        return std::string(path.substr(pos + after.length()));
    }
    return std::string(path);
}

std::string ExtractClassAndFunctionName(std::string_view prettyFunctionName)
{
    size_t paramsPos = prettyFunctionName.find('(');
    if (paramsPos != std::string::npos)
    {
        prettyFunctionName = prettyFunctionName.substr(0, paramsPos);
    }

    size_t spacePos = prettyFunctionName.rfind(' ');
    if (spacePos != std::string::npos)
    {
        prettyFunctionName = prettyFunctionName.substr(spacePos + 1);
    }

    return std::string(prettyFunctionName);
}

} // namespace aero3d