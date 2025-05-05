#include "Core/Application.h"

int main()
{
    aero3d::Application app;
    if (app.Init())
    {
        app.Run();
    }

    app.Shutdown();
    
    return 0;
}