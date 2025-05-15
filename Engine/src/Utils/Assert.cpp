#include "Utils/Assert.h"

#include <cstdlib>

#include "Utils/Log.h"

namespace aero3d {

void Assert(const char* file, const char* func, int line, bool exp,
    const char* msg)
{
    if (!exp) LogErr(file, func, line, msg); std::abort();
}

} // namespace aero3d