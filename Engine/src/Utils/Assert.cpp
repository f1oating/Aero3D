#include "Utils/Assert.h"

#include "Utils/Log.h"

namespace aero3d {

void Assert(std::string_view msg, bool expression,
    const std::source_location& location)
{
    if (!expression) LogErr(msg, location); std::abort();
}

} // namespace aero3d