#include "Utils/Assert.h"

#include "Utils/Log.h"

namespace aero3d {

void Assert(std::string_view msg, bool expression,
    const std::source_location& location)
{
    if (!expression) LogErr(location.file_name(), location.function_name(), location.line(), msg.data()); std::abort();
}

} // namespace aero3d