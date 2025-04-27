#include "Graphics/OpenGL/OpenGLContext.h"

#include <glad/glad.h>

#include "Core/Window.h"
#include "Utils/Log.h"

namespace aero3d {

OpenGLContext::OpenGLContext()
    : m_Context(nullptr)
{
}

void OpenGLContext::Init()
{
    m_Context = SDL_GL_CreateContext(Window::GetSDLWindow());
    if (!m_Context) {
        LogMsg("OpenGL context creation failed.");
    }

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        LogMsg("Glad func loading creation failed.");
    }

    // Перевірка версії OpenGL
    SDL_Log("OpenGL %d.%d", GLVersion.major, GLVersion.minor);
    SDL_Log("Версія: %s", glGetString(GL_VERSION));
    SDL_Log("Вендор: %s", glGetString(GL_VENDOR));
    SDL_Log("Рендерер: %s", glGetString(GL_RENDERER));
}

void OpenGLContext::Shutdown()
{
    SDL_GL_DestroyContext(m_Context);
}

void OpenGLContext::SwapBuffers()
{
    SDL_GL_SwapWindow(Window::GetSDLWindow());
}

} // namespace aero3d