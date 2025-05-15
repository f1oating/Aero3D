#ifndef AERO3D_UTILS_STRINGMANIP_H_
#define AERO3D_UTILS_STRINGMANIP_H_

#include <string>

#include "Utils/API.h"

namespace aero3d {

extern A3D_API std::string GetPathAfter(const char* path, const char* after);
extern A3D_API std::string ExtractClassAndFunctionName(const char* prettyFunctionName);

} // namespace aero3d

#endif // AERO3D_UTILS_STRINGMANIP_H_