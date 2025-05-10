#ifndef AERO3D_GRAPHICS_RENDERAPI_H_
#define AERO3D_GRAPHICS_RENDERAPI_H_

#include <memory>

#include "Graphics/Buffer.h"
#include "Graphics/ConstantBuffer.h"
#include "Graphics/Shader.h"
#include "Graphics/Texture.h"

namespace aero3d {

enum class API
{
    None,
    OpenGL,
    Vulkan,
    DirectX11,
    DirectX12
};

class RenderAPI
{
public:
    RenderAPI() : m_API(API::None) {}
    virtual ~RenderAPI() = default;

    virtual bool Init() = 0;
    virtual void Shutdown() = 0;

    virtual void SetViewport(int x, int y, int width, int height) = 0;

    virtual void SetClearColor(float r, float g, float b, float a) = 0;
    virtual void Clear() = 0;

    virtual void Draw(std::shared_ptr<VertexBuffer> vb, size_t count) = 0;
    virtual void DrawIndexed(std::shared_ptr<VertexBuffer> vb, std::shared_ptr<IndexBuffer> ib) = 0;

    virtual std::shared_ptr<VertexBuffer> CreateVertexBuffer(BufferLayout& layout, const void* data, size_t size) = 0;
    virtual std::shared_ptr<IndexBuffer> CreateIndexBuffer(const void* data, size_t size, size_t count) = 0;
    virtual std::shared_ptr<ConstantBuffer> CreateConstantBuffer(const void* data, size_t size) = 0;

    virtual std::shared_ptr<Shader> CreateShader(const char* vertexPath, const char* pixelPath) = 0;
    virtual std::shared_ptr<Texture> CreateTexture(const char* path) = 0;

    API GetAPI() { return m_API; }

protected:
    API m_API;

};

} // namespace aero3d

#endif // AERO3D_GRAPHICS_RENDERAPI_H_