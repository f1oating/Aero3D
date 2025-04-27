#ifndef AERO3D_CORE_APPLICATION_H_
#define AERO3D_CORE_APPLICATION_H_

#include <memory>

#include "Utils/API.h"

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
    bool m_IsRunning = false;
};

} // namespace aero3d

#endif // AERO3D_CORE_APPLICATION_H_