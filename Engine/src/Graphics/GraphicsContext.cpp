#include "Graphics/GraphicsContext.h"

#include <memory>

#include "Platform/OpenGL/OpenGLContext.h"

namespace aero3d {

std::unique_ptr<GraphicsContext> GraphicsContext::Create()
{
    return std::make_unique<OpenGLContext>();
}

} // namespace aero3d