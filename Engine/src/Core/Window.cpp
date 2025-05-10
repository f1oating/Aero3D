#include "Core/Window.h"

#include <memory>

#include "Utils/Log.h"
#include "Core/Configuration.h"

namespace aero3d {

SDL_Window* Window::s_Window = nullptr;
std::unique_ptr<GraphicsContext> Window::s_Context = nullptr;

bool Window::Init(const char* title, int width, int height)
{
    LogMsg("Window Initialize.");

    if (!SDL_InitSubSystem(SDL_INIT_VIDEO)) {
        LogErr(ERROR_INFO, "SDL Init Failed. SDL Error: %s", SDL_GetError());
        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    s_Window = SDL_CreateWindow(Configuration::GetValue("WindowTitle").c_str(),
        std::stoi(Configuration::GetValue("WindowWidth")), std::stoi(Configuration::GetValue("WindowHeight")),
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    if (!s_Window) {
        LogErr(ERROR_INFO, "SDL Create Window Failed. SDL Error: %s", SDL_GetError());
        return false;
    }

    s_Context = GraphicsContext::Create();
    if (!s_Context->Init(s_Window))
    {
        return false;
    }

    return true;
}

void Window::Shutdown()
{
    LogMsg("Window Shutdown.");
    if (s_Window) {
        SDL_DestroyWindow(s_Window);
    }
    if (s_Context)
    {
        s_Context->Shutdown();
    }
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

void Window::PollEvents(bool& running)
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            running = false;
        }
    }
}

void Window::SwapBuffers()
{
    s_Context->SwapBuffers(s_Window);
}

SDL_Window* Window::GetSDLWindow()
{
    return s_Window;
}

} // namespace aero3d