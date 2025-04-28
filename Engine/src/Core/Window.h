#ifndef AERO3D_CORE_WINDOW_H_
#define AERO3D_CORE_WINDOW_H_

#include "SDL3/SDL.h"

#include "Graphics/GraphicsContext.h"

namespace aero3d {

class Window
{
public:
    static bool Init(const char* title, int width, int height);
    static void Shutdown();

    static void PollEvents(bool& running);
    static void SwapBuffers();

    static SDL_Window* GetSDLWindow();

private:
    static SDL_Window* s_Window;
    static GraphicsContext* s_Context;

};

} // namespace aero3d

#endif // AERO3D_CORE_WINDOW_H_