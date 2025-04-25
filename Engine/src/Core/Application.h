#ifndef AERO3D_CORE_APPLICATION_H_
#define AERO3D_CORE_APPLICATION_H_

#include "Utils/API.h"

class A3D_API Application
{
public:
    Application();
    ~Application();

    void Init();
    void Run();
    void Shutdown();

private:

};

#endif // AERO3D_CORE_APPLICATION_H_