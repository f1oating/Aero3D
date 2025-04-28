#include "Graphics/GraphicsContext.h"

#include "Platform/OpenGL/OpenGLContext.h"

namespace aero3d {

GraphicsContext* GraphicsContext::Create()
{
    return new OpenGLContext();
}

} // namespace aero3d