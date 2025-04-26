#ifndef AERO3D_UTILS_ASSERT_H_
#define AERO3D_UTILS_ASSERT_H_

#include <source_location>
#include <string>

#include "Utils/API.h"

namespace aero3d {

extern A3D_API void Assert(std::string_view msg, bool expression, 
    const std::source_location& location = std::source_location::current());

} // namespace aero3d

#endif // AERO3D_UTILS_ASSERT_H_