#include "Application.h"

#include "Utils/Log.h"
#include "Core/Window.h"

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

    m_IsRunning = true;

    return true;
}

void Application::Run()
{
    while (m_IsRunning)
    {
        Window::PollEvents(m_IsRunning);

        Window::SwapBuffers();
    }
}

void Application::Shutdown()
{
    LogMsg("Application Shutdown.");

    Window::Shutdown();
}

} // namespace aero3d