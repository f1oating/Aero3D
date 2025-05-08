#include "Application.h"

#include "Utils/Log.h"
#include "Core/Window.h"
#include "IO/VFS.h"
#include "Graphics/RenderCommand.h"

#include "Graphics/Buffer.h"
#include "Platform/OpenGL/OpenGLVertexBuffer.h"

#include <glad/glad.h>

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

GLuint CreateShaderProgram()
{
    const char* vertexSrc = R"(
        #version 330 core
        layout(location = 0) in vec2 a_Position;
        out vec3 v_Color;
        void main()
        {
            gl_Position = vec4(a_Position, 0.0, 1.0);
            v_Color = vec3(1.0, 1.0, 1.0);
        }
    )";

    const char* fragmentSrc = R"(
        #version 330 core
        in vec3 v_Color;
        out vec4 FragColor;
        void main()
        {
            FragColor = vec4(v_Color, 1.0);
        }
    )";

    // Vertex Shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSrc, nullptr);
    glCompileShader(vertexShader);

    // Fragment Shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSrc, nullptr);
    glCompileShader(fragmentShader);

    // Shader Program
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Clean up
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
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

    unsigned int shaderProgram = CreateShaderProgram();

    BufferLayout layout(std::move(elements));
    std::shared_ptr<VertexBuffer> vb = RenderCommand::CreateVertexBuffer(layout, vertices, 6 * 4);
    std::shared_ptr<IndexBuffer> ib = RenderCommand::CreateIndexBuffer(indices, 12, 3);

    RenderCommand::SetViewport(0, 0, 800, 600);
    RenderCommand::SetClearColor(0.2f, 0.3f, 0.2f, 1.0f);

    while (m_IsRunning)
    {
        Window::PollEvents(m_IsRunning);
        RenderCommand::Clear();

        glUseProgram(shaderProgram);
        RenderCommand::DrawIndexed(vb, ib);

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