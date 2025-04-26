#include "Utils/StringManip.h"

const char* GetPathAfter(const char* path, const char* after) 
{
    const char* src_pos = strstr(path, after);
    if (src_pos == nullptr) {
        return nullptr;
    }
    return (char*)(src_pos + 4);
}