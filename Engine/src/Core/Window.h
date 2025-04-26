#ifndef AERO3D_CORE_WINDOW_H_
#define AERO3D_CORE_WINDOW_H_

#include "Utils/API.h"

class A3D_API Window
{
public:
    Window();
    ~Window();

    void Init(const char* title, int width, int height, bool fullscreen);
    void Shutdown();

    void ProcessMessages();
    void SwapBuffer();

    bool IsClosing();

    void* GetHandle();

};

#endif // AERO3D_CORE_WINDOW_H_