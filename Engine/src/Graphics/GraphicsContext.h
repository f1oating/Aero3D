#ifndef AERO3D_GRAPHICS_GRAPHICSCONTEXT_H_
#define AERO3D_GRAPHICS_GRAPHICSCONTEXT_H_

#include <memory>

#include "Utils/API.h"

namespace aero3d {

class A3D_API GraphicsContext
{
public:
    virtual ~GraphicsContext() = default;

    virtual void Init() = 0;
    virtual void Shutdown() = 0;

    virtual void SwapBuffers() = 0;

    static std::shared_ptr<GraphicsContext> Create();
};

} // namespace aero3d

#endif // AERO3D_GRAPHICS_GRAPHICSCONTEXT_H_