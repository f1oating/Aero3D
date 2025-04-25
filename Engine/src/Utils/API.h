#ifndef AERO3D_UTILS_API_H_
#define AERO3D_UTILS_API_H_

#ifdef A3D_PLATFORM_WINDOWS

    #ifdef A3D_BUILD_DLL
        #define A3D_API __declspec(dllexport)
    #else
        #define A3D_API __declspec(dllimport)
    #endif

#endif

#endif // AERO3D_UTILS_API_H_