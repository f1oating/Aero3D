#ifndef AERO3D_CORE_APPLICATION_H_
#define AERO3D_CORE_APPLICATION_H_

#include <memory>

#include "Utils/API.h"
#include "Core/Window.h"

namespace aero3d {

class A3D_API Application
{
public:
    Application();
    ~Application();

    void Init();
    void Run();
    void Shutdown();

private:
    Window m_Window;

};

} // namespace aero3d

#endif // AERO3D_CORE_APPLICATION_H_