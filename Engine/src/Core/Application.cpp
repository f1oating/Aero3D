#include "Application.h"

#include "Utils/Log.h"
#include "Core/Window.h"
#include "IO/VFS.h"
#include "Graphics/RenderCommand.h"

#include "Graphics/Buffer.h"
#include "Graphics/Shader.h"
#include "Platform/OpenGL/OpenGLVertexBuffer.h"

namespace aero3d {

Application::Application()
    : m_IsRunning(false)
{
}

Application::~Application()
{
}

bool Application::Init()
{
    LogMsg("Application Initialize.");

    if (!Window::Init("Aero3D", 800, 600))
    {
        return false;
    }

    if (!VFS::Init())
    {
        return false;
    }

    if (!RenderCommand::Init())
    {
        return false;
    }

    m_IsRunning = true;

    return true;
}

void Application::Run()
{
    float vertices[] = {
        0.0f,  0.5f,
       -0.5f, -0.5f,
        0.5f, -0.5f
    };

    unsigned int indices[] = {
        0, 1, 2
    };

    std::vector<LayoutElement> elements = {
        { "a_Position", ElementType::FLOAT2 }
    };

    BufferLayout layout(std::move(elements));
    std::shared_ptr<VertexBuffer> vb = RenderCommand::CreateVertexBuffer(layout, vertices, 6 * 4);
    std::shared_ptr<IndexBuffer> ib = RenderCommand::CreateIndexBuffer(indices, 12, 3);

    std::shared_ptr<Shader> shader = RenderCommand::CreateShader(L"vertex.glsl", L"pixel.glsl");

    RenderCommand::SetViewport(0, 0, 800, 600);
    RenderCommand::SetClearColor(0.2f, 0.3f, 0.2f, 1.0f);

    while (m_IsRunning)
    {
        Window::PollEvents(m_IsRunning);
        RenderCommand::Clear();

        shader->Bind();
        RenderCommand::DrawIndexed(vb, ib);
        shader->Unbind();

        Window::SwapBuffers();
    }
}

void Application::Shutdown()
{
    LogMsg("Application Shutdown.");

    RenderCommand::Shutdown();
    VFS::Shutdown();
    Window::Shutdown();
}

} // namespace aero3d