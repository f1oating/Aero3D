#include "Graphics/OpenGL/OpenGLContext.h"

#include <glad/glad.h>

#include "Utils/Log.h"

namespace aero3d {

OpenGLContext::OpenGLContext()
    : m_Context(nullptr)
{
}

bool OpenGLContext::Init(SDL_Window* window)
{
    LogMsg("OpenGL Graphics Context Initialize.");

    m_Context = SDL_GL_CreateContext(window);
    if (!m_Context) {
        LogErr(ERROR_INFO, "OpenGL context creation failed. SDL Error: %s", SDL_GetError());
        return false;
    }

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        LogErr(ERROR_INFO, "Glad func loading failed");
        return false;
    }

    LogMsg("OpenGL %d.%d:", GLVersion.major, GLVersion.minor);
    LogMsg("\tVersion: %s", glGetString(GL_VERSION));
    LogMsg("\tVendor: %s", glGetString(GL_VENDOR));
    LogMsg("\tRenderer: %s", glGetString(GL_RENDERER));

    return true;
}

void OpenGLContext::Shutdown()
{
    LogMsg("OpenGL Graphics Context Shutdown.");
    if (m_Context)
    {
        SDL_GL_DestroyContext(m_Context);
    }
}

void OpenGLContext::SwapBuffers(SDL_Window* window)
{
    SDL_GL_SwapWindow(window);
}

} // namespace aero3d