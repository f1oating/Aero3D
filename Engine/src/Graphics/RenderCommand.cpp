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

} // namespace aero3d