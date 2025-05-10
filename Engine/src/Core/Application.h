#ifndef AERO3D_CORE_APPLICATION_H_
#define AERO3D_CORE_APPLICATION_H_

#include "Utils/API.h"
#include "Core/Configuration.h"

namespace aero3d {

struct ApplicationInfo
{
    std::string WindowTitle;
    int WindowWidth;
    int WindowHeight;
    std::string RenderAPI;
};

class A3D_API Application
{
public:
    Application();
    ~Application();

    bool Init();
    void Run();
    void Shutdown();

private:
    Configuration m_Configuration;
    ApplicationInfo m_ApplicationInfo;
    bool m_IsRunning;

};

} // namespace aero3d

#endif // AERO3D_CORE_APPLICATION_H_