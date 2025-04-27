IncludeDir = {}
IncludeDir["sdl"] = "%{wks.location}/Dependencies/SDL3/include"
IncludeDir["glad"] = "%{wks.location}/Dependencies/glad/include"

WindowsLibrary = {}
WindowsLibrary["sdl"] = "%{wks.location}/Dependencies/SDL3/lib/windows/SDL3.lib"
WindowsLibrary["glad"] = "%{wks.location}/Dependencies/glad/lib/windows/glad.lib"

WindowsDllDir = "%{wks.location}/Dependencies/DLLs"