#include "Application.h"

#include "Utils/Log.h"

Application::Application()
{
}

Application::~Application()
{
}

void Application::Init()
{
    LogMsg("Application Initialize");

    m_Window.Init("Aero3D", 800, 600, false);
}

void Application::Run()
{
    while (!m_Window.IsClosing())
    {
        m_Window.ProcessMessages();

        m_Window.SwapBuffer();
    }
}

void Application::Shutdown()
{
    LogMsg("Application Shutdown");

    m_Window.Shutdown();
}