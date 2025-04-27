#ifndef AERO3D_GRAPHICS_OPENGL_OPENGLCONTEXT_H_
#define AERO3D_GRAPHICS_OPENGL_OPENGLCONTEXT_H_

#include "SDL3/SDL.h"

#include "Graphics/GraphicsContext.h"

namespace aero3d {

class OpenGLContext : public GraphicsContext
{
public:
    OpenGLContext();

    virtual void Init() override;
    virtual void Shutdown() override;

    virtual void SwapBuffers() override;

private:
    SDL_GLContext m_Context;

};

} // namespace aero3d

#endif // AERO3D_GRAPHICS_OPENGL_OPENGLCONTEXT_H_