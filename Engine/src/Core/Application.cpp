#include "Application.h"

#include "Utils/Log.h"
#include "Core/Window.h"
#include "IO/VFS.h"
#include "Graphics/RenderCommand.h"
#include "EventSystem/EventBus.h"

#include "Graphics/Buffer.h"
#include "Graphics/Shader.h"
#include "Graphics/ConstantBuffer.h"
#include "Graphics/Texture.h"

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

    if (!VFS::Init())
    {
        return false;
    }

    if (!EventBus::Init())
    {
        return false;
    }

    if (!Window::Init("Aero3D", 800,
        600, "OpenGL"))
    {
        return false;
    }

    if (!RenderCommand::Init("OpenGL"))
    {
        return false;
    }

    m_IsRunning = true;

    return true;
}

void Application::Run()
{
    EventBus::Subscribe(typeid(MyEvent), [](Event& event) {
        MyEvent& myEvent = static_cast<MyEvent&>(event);
        LogMsg("Event triggered with value: %d", myEvent.value);
    });

    MyEvent event(42);
    EventBus::Publish(event);

    float vertices[] = {
        0.0f,  0.5f,   0.5f, 1.0f,
       -0.5f, -0.5f,   0.0f, 0.0f,
        0.5f, -0.5f,   1.0f, 0.0f
    };

    unsigned int indices[] = {
        0, 1, 2
    };

    std::vector<LayoutElement> elements = {
        { "a_Position", ElementType::FLOAT2 },
        { "a_TexCoord", ElementType::FLOAT2 }
    };

    BufferLayout layout(std::move(elements));
    std::shared_ptr<VertexBuffer> vb = RenderCommand::CreateVertexBuffer(layout, vertices, 12 * 4);
    std::shared_ptr<IndexBuffer> ib = RenderCommand::CreateIndexBuffer(indices, 12, 3);

    struct UniformData {
        float color[3]; 
        float padding;
    };

    UniformData data;
    data.color[0] = 0.2f;
    data.color[1] = 0.3f;
    data.color[2] = 0.4f;
    data.padding = 0.0f;

    std::shared_ptr<Shader> shader = RenderCommand::CreateShader("res/shaders/vertex.glsl", "res/shaders/pixel.glsl");
    std::shared_ptr<Texture> texture = RenderCommand::CreateTexture("res/textures/texture.jpg");
    texture->Bind(0);

    std::shared_ptr<ConstantBuffer> cb = RenderCommand::CreateConstantBuffer(&data, sizeof(UniformData));

    RenderCommand::SetViewport(0, 0, 800, 600);
    RenderCommand::SetClearColor(0.2f, 0.3f, 0.2f, 1.0f);

    while (m_IsRunning)
    {
        Window::PollEvents(m_IsRunning);
        RenderCommand::Clear();

        shader->Bind();
        cb->Bind(0);

        data.color[0] = static_cast<float>(rand()) / RAND_MAX;
        data.color[1] = static_cast<float>(rand()) / RAND_MAX;
        data.color[2] = static_cast<float>(rand()) / RAND_MAX;

        cb->SetData(&data, sizeof(UniformData));
        RenderCommand::DrawIndexed(vb, ib);
        shader->Unbind();

        Window::SwapBuffers();
    }
}

void Application::Shutdown()
{
    LogMsg("Application Shutdown.");

    RenderCommand::Shutdown();
    Window::Shutdown();
    EventBus::Shutdown();
    VFS::Shutdown();
}

} // namespace aero3d