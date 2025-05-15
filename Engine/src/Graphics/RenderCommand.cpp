#include "Graphics/RenderCommand.h"

#include <string.h>

#include "Core/Configuration.h"
#include "Platform/OpenGL/OpenGLRenderAPI.h"

namespace aero3d {

std::unique_ptr<RenderAPI> RenderCommand::s_API = nullptr;

bool RenderCommand::Init(const char* api)
{
    if (strcmp(api, "OpenGL") == 0) s_API = std::make_unique<OpenGLRenderAPI>();
    else Assert(ERROR_INFO, false, "This Rendering API not yet supported.");

    return s_API->Init();
}

void RenderCommand::Shutdown()
{
    s_API->Shutdown();
}

void RenderCommand::SetViewport(int x, int y, int width, int height)
{
    s_API->SetViewport(x, y, width, height);
}

void RenderCommand::SetClearColor(float r, float g, float b, float a)
{
    s_API->SetClearColor(r, g, b, a);
}

void RenderCommand::Clear()
{
    s_API->Clear();
}

void RenderCommand::Draw(std::shared_ptr<VertexBuffer> vb, size_t count)
{
    s_API->Draw(vb, count);
}

void RenderCommand::DrawIndexed(std::shared_ptr<VertexBuffer> vb, std::shared_ptr<IndexBuffer> ib)
{
    s_API->DrawIndexed(vb, ib);
}

std::shared_ptr<VertexBuffer> RenderCommand::CreateVertexBuffer(BufferLayout& layout, const void* data, size_t size)
{
    return s_API->CreateVertexBuffer(layout, data, size);
}

std::shared_ptr<IndexBuffer> RenderCommand::CreateIndexBuffer(const void* data, size_t size, size_t count)
{
    return s_API->CreateIndexBuffer(data, size, count);
}

std::shared_ptr<ConstantBuffer> RenderCommand::CreateConstantBuffer(const void* data, size_t size)
{
    return s_API->CreateConstantBuffer(data, size);
}

std::shared_ptr<Shader> RenderCommand::CreateShader(std::string vertexPath, std::string pixelPath)
{
    return s_API->CreateShader(vertexPath, pixelPath);
}

std::shared_ptr<Texture> RenderCommand::CreateTexture(std::string path)
{
    return s_API->CreateTexture(path);
}

RenderAPI::API RenderCommand::GetAPI()
{
    return s_API->GetAPI();
}

} // namespace aero3d