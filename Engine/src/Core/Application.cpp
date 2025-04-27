#include "Application.h"

#include "Utils/Log.h"
#include "Core/Window.h"

namespace aero3d {

Application::Application()
    : m_IsRunning(false), m_Context(nullptr)
{
}

Application::~Application()
{
}

void Application::Init()
{
    LogMsg("Application Initialize.");

    Window::Init("Aero3D", 800, 600);
    m_Context = GraphicsContext::Create();
    m_Context->Init();

    m_IsRunning = true;
}

void Application::Run()
{
    while (m_IsRunning)
    {
        Window::PollEvents(m_IsRunning);
        m_Context->SwapBuffers();
    }
}

void Application::Shutdown()
{
    LogMsg("Application Shutdown.");

    m_Context->Shutdown();
    Window::Shutdown();
}

} // namespace aero3d