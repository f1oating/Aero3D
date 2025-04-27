#include "Core/Window.h"

#include "Utils/Log.h"
#include "Utils/Assert.h"

namespace aero3d {

SDL_Window* Window::s_Window = nullptr;

void Window::Init(const char* title, int width, int height)
{
    LogMsg("Window Initialize.");

    if (!SDL_InitSubSystem(SDL_INIT_VIDEO)) {
        LogErr("SDL Init Failed");
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    s_Window = SDL_CreateWindow(title,
        width, height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    if (!s_Window) {
        SDL_Quit();
        LogErr("SDL Create Window Failed");
    }
}

void Window::Shutdown()
{
    LogMsg("Window Shutdown.");
    if (s_Window) {
        SDL_DestroyWindow(s_Window);
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

SDL_Window* Window::GetSDLWindow()
{
    return s_Window;
}

} // namespace aero3d