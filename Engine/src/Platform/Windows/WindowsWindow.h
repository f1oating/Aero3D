#ifndef AERO3D_PLATFORM_WINDOWS_WINDOWSWINDOW_H_
#define AERO3D_PLATFORM_WINDOWS_WINDOWSWINDOW_H_

#include "Core/Window.h"

class WindowsWindow : public Window
{
public:
    WindowsWindow();
    ~WindowsWindow();

    virtual void Init(const char* title, int width, int height, bool fullscreen) override;
    virtual void Shutdown() override;

    virtual void ProcessMessages() override;
    virtual void SwapBuffer() override;

    virtual bool IsClosing() override;

    virtual void* GetHandle() override;

private:
    struct GLFWwindow* m_Window;
};

#endif // AERO3D_PLATFORM_WINDOWS_WINDOWSWINDOW_H_