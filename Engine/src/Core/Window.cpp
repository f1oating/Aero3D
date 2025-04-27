#include "Core/Window.h"

#include "Utils/Log.h"
#include "Utils/Assert.h"

namespace aero3d {

Window::Window()
{
}

Window::~Window()
{
}

void Window::Init(const char* title, int width, int height, bool fullscreen)
{
    LogMsg("Window Initialize.");
}

void Window::Shutdown()
{
    LogMsg("Window Shutdown.");
}

void Window::ProcessMessages()
{
}

void Window::SwapBuffer()
{
}

bool Window::IsClosing()
{
    return false;
}

void* Window::GetHandle()
{
    return nullptr;
}

} // namespace aero3d