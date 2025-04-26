#include "Core/Window.h"

#include <GLFW/glfw3.h>

#include "Utils/Log.h"

GLFWwindow* s_Window = nullptr;

Window::Window()
{
}

Window::~Window()
{
}

void Window::Init(const char* title, int width, int height, bool fullscreen)
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

    s_Window = glfwCreateWindow(fullscreen ? w : width, fullscreen ? h : height, title, fullscreen ? primary : NULL, NULL);
    if (s_Window == NULL) {
        glfwTerminate();
        // Add assertion
    }

    glfwMakeContextCurrent(s_Window);
}

void Window::Shutdown()
{
    LogMsg("Window Shutdown");

    glfwDestroyWindow(s_Window);
}

void Window::ProcessMessages()
{
    glfwPollEvents();
}

void Window::SwapBuffer()
{
    glfwSwapBuffers(s_Window);
}

bool Window::IsClosing()
{
    return glfwWindowShouldClose(s_Window);
}

void* Window::GetHandle()
{
    return s_Window;
}