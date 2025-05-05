#include "Utils/StringManip.h"

#include <string.h>

namespace aero3d {

const char* GetPathAfter(const char* path, const char* after)
{
    const char* found = strstr(path, after);
    if (found != NULL)
    {
        return found + strlen(after);
    }
    return path;
}

const char* ExtractClassAndFunctionName(const char* prettyFunctionName)
{
    const char* paramsPos = strchr(prettyFunctionName, '(');
    size_t length = strlen(prettyFunctionName);

    if (paramsPos != NULL)
    {
        length = paramsPos - prettyFunctionName;
    }

    char* result = (char*)malloc(length + 1);

    if (result == NULL)
    {
        return NULL;
    }

    if (strncpy_s(result, length + 1, prettyFunctionName, length) != 0)
    {
        free(result);
        return NULL;
    }

    result[length] = '\0';

    const char* spacePos = strrchr(result, ' ');
    if (spacePos != NULL)
    {
        memmove(result, spacePos + 1, strlen(spacePos));
    }

    return result;
}

} // namespace aero3d