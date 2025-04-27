#include "Graphics/GraphicsContext.h"

#include "Graphics/OpenGL/OpenGLContext.h"

namespace aero3d {

std::shared_ptr<GraphicsContext> GraphicsContext::Create()
{
    return std::make_shared<OpenGLContext>();
}

} // namespace aero3d