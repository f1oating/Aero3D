#ifndef AERO3D_GRAPHICS_RENDERAPI_H_
#define AERO3D_GRAPHICS_RENDERAPI_H_

#include "Graphics/Buffer.h"

namespace aero3d {

enum class API
{
    OpenGL,
    Vulkan,
    DirectX11,
    DirectX12
};

class RenderAPI
{
public:
    virtual bool Init() = 0;
    virtual void Shutdown() = 0;

    virtual void SetViewport(int x, int y, int width, int height) = 0;

    virtual bool SetClearColor(float r, float g, float b, float a) = 0;
    virtual void Clear() = 0;

    virtual void Draw(VertexBuffer vb) = 0;
    virtual void DrawIndexed(VertexBuffer vb, IndexBuffer ib) = 0;

    API GetAPI() { return m_API; }

private:
    API m_API;

};

} // namespace aero3d

#endif // AERO3D_GRAPHICS_RENDERAPI_H_