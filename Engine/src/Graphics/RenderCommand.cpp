#include "Graphics/RenderCommand.h"

#include "Platform/OpenGL/OpenGLRenderAPI.h"

namespace aero3d {

std::unique_ptr<RenderAPI> RenderCommand::m_API = nullptr;

bool RenderCommand::Init()
{
    m_API = std::make_unique<OpenGLRenderAPI>();
    return m_API->Init();
}

void RenderCommand::Shutdown()
{
    m_API->Shutdown();
}

void RenderCommand::SetViewport(int x, int y, int width, int height)
{
    m_API->SetViewport(x, y, width, height);
}

void RenderCommand::SetClearColor(float r, float g, float b, float a)
{
    m_API->SetClearColor(r, g, b, a);
}

void RenderCommand::Clear()
{
    m_API->Clear();
}

void RenderCommand::Draw(std::shared_ptr<VertexBuffer> vb, size_t count)
{
    m_API->Draw(vb, count);
}

void RenderCommand::DrawIndexed(std::shared_ptr<VertexBuffer> vb, std::shared_ptr<IndexBuffer> ib)
{
    m_API->DrawIndexed(vb, ib);
}

std::shared_ptr<VertexBuffer> RenderCommand::CreateVertexBuffer(BufferLayout& layout, const void* data, size_t size)
{
    return m_API->CreateVertexBuffer(layout, data, size);
}

std::shared_ptr<IndexBuffer> RenderCommand::CreateIndexBuffer(const void* data, size_t size, size_t count)
{
    return m_API->CreateIndexBuffer(data, size, count);
}

std::shared_ptr<Shader> RenderCommand::CreateShader(std::wstring vertexPath, std::wstring pixelPath)
{
    return m_API->CreateShader(vertexPath, pixelPath);
}

} // namespace aero3d