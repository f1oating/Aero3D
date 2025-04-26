#ifndef AERO3D_CORE_WINDOW_H_
#define AERO3D_CORE_WINDOW_H_

#include <memory>

#include "Utils/API.h"

class A3D_API Window
{
public:
    virtual ~Window() = default;

    virtual void Init(const char* title, int width, int height, bool fullscreen) = 0;
    virtual void Shutdown() = 0;

    virtual void ProcessMessages() = 0;
    virtual void SwapBuffer() = 0;

    virtual bool IsClosing() = 0;

    virtual void* GetHandle() = 0;

    static std::unique_ptr<Window> Create();

};

#endif // AERO3D_CORE_WINDOW_H_