#include "Graphics/GraphicsContext.h"

#include <memory>
#include <string>

#include "Core/Configuration.h"
#include "Platform/OpenGL/OpenGLContext.h"
#include "Utils/Assert.h"

namespace aero3d {

std::unique_ptr<GraphicsContext> GraphicsContext::Create()
{
    std::string api = Configuration::GetValue("RenderAPI");

    if (api == "OpenGL") return std::make_unique<OpenGLContext>();
    else Assert("This Rendering API not yet supported.", false);

    return nullptr;
}

} // namespace aero3d