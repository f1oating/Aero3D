#include "Platform/Windows/WindowsWindow.h"

#include <GLFW/glfw3.h>

#include "Utils/Log.h"

WindowsWindow::WindowsWindow()
    : m_Window(nullptr)
{
}

WindowsWindow::~WindowsWindow()
{
}

void WindowsWindow::Init(const char* title, int width, int height, bool fullscreen)
{
    LogMsg("Window Initialize");

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    GLFWmonitor* primary = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(primary);
    unsigned int w = mode->width;
    unsigned int h = mode->height;

    m_Window = glfwCreateWindow(fullscreen ? w : width, fullscreen ? h : height, title, fullscreen ? primary : NULL, NULL);
    if (m_Window == NULL) {
        glfwTerminate();
        // Add assertion
    }

    glfwMakeContextCurrent(m_Window);
}

void WindowsWindow::Shutdown()
{
    LogMsg("Window Shutdown");

    glfwDestroyWindow(m_Window);
}

void WindowsWindow::ProcessMessages()
{
    glfwPollEvents();
}

void WindowsWindow::SwapBuffer()
{
    glfwSwapBuffers(m_Window);
}

bool WindowsWindow::IsClosing()
{
    return glfwWindowShouldClose(m_Window);
}

void* WindowsWindow::GetHandle()
{
    return m_Window;
}