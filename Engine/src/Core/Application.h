#ifndef AERO3D_CORE_APPLICATION_H_
#define AERO3D_CORE_APPLICATION_H_

#include <memory>

#include "Utils/API.h"
#include "Core/Window.h"

class A3D_API Application
{
public:
    Application();
    ~Application();

    void Init();
    void Run();
    void Shutdown();

private:
    std::unique_ptr<Window> m_Window;

};

#endif // AERO3D_CORE_APPLICATION_H_