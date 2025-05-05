#ifndef AERO3D_GRAPHICS_GRAPHICSCONTEXT_H_
#define AERO3D_GRAPHICS_GRAPHICSCONTEXT_H_

#include <memory>

#include "SDL3/SDL.h"

namespace aero3d {

class GraphicsContext
{
public:
    virtual ~GraphicsContext() = default;

    virtual bool Init(SDL_Window* window) = 0;
    virtual void Shutdown() = 0;

    virtual void SwapBuffers(SDL_Window* window) = 0;

    static std::unique_ptr<GraphicsContext> Create();
};

} // namespace aero3d

#endif // AERO3D_GRAPHICS_GRAPHICSCONTEXT_H_