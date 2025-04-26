#include "Core/Window.h"

#include "Platform/Windows/WindowsWindow.h"

std::unique_ptr<Window> Window::Create()
{
    return std::make_unique<WindowsWindow>();
}