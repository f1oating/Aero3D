#include "Graphics/GraphicsContext.h"

#include <memory>
#include <string.h>

#include "Core/Configuration.h"
#include "Platform/OpenGL/OpenGLContext.h"
#include "Utils/Assert.h"

namespace aero3d {

std::unique_ptr<GraphicsContext> GraphicsContext::Create(const char* api)
{
    if (strcmp(api, "OpenGL") == 0) return std::make_unique<OpenGLContext>();
    else Assert(ERROR_INFO, false, "This Rendering API not yet supported.");

    return nullptr;
}

} // namespace aero3d