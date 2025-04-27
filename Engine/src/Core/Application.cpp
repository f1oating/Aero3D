#include "Application.h"

#include "Utils/Log.h"
#include "Core/Window.h"

namespace aero3d {

Application::Application()
{
}

Application::~Application()
{
}

void Application::Init()
{
    LogMsg("Application Initialize.");

    Window::Init("Aero3D", 800, 600);

    m_IsRunning = true;
}

void Application::Run()
{
    while (m_IsRunning)
    {
        Window::PollEvents(m_IsRunning);
    }
}

void Application::Shutdown()
{
    LogMsg("Application Shutdown.");

    Window::Shutdown();
}

} // namespace aero3d