project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    debugdir "%{wks.location}/%{prj.name}"

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "src",
        "%{wks.location}/Engine/src",
    }

    links
    {
        "Engine"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "A3D_PLATFORM_WINDOWS"
        }

        postbuildcommands {
            "{COPY} %{WindowsDllDir}/*.dll %{wks.location}/%{prj.name}"
        }

    filter "configurations:Debug"
        defines "A3D_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "A3D_RELEASE"
        runtime "Release"
        optimize "On"	

    filter "configurations:Dist"
        defines "A3D_DIST"
        runtime "Release"
        optimize "On"