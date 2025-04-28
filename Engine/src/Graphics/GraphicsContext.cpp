#include "Graphics/GraphicsContext.h"

#include "Graphics/OpenGL/OpenGLContext.h"

namespace aero3d {

GraphicsContext* GraphicsContext::Create()
{
    return new OpenGLContext();
}

} // namespace aero3d