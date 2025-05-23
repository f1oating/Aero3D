project "Engine"
	kind "SharedLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/Core/**.h",
		"src/Core/**.cpp",
		"src/EventSystem/**.h",
		"src/EventSystem/**.cpp",
		"src/Graphics/**.h",
		"src/Graphics/**.cpp",
		"src/Platform/OpenGL/**.h",
		"src/Platform/OpenGL/**.cpp",
		"src/IO/**.h",
		"src/IO/**.cpp",
		"src/Scene/**.h",
		"src/Scene/**.cpp",
		"src/Utils/**.h",
		"src/Utils/**.cpp",
		"src/Vendor/**.h",
		"src/Vendor/**.cpp",
	}

	includedirs
	{
		"src",
		"src/Vendor",
		"%{IncludeDir.sdl}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.glm}",
	}

	links
	{
		"%{WindowsLibrary.sdl}",
		"%{WindowsLibrary.glad}"
	}

	filter "system:windows"
		systemversion "latest"

		files
		{
			"src/Platform/Windows/**.h",
			"src/Platform/Windows/**.cpp",
		}

		defines
		{
			"A3D_PLATFORM_WINDOWS",
			"A3D_BUILD_DLL"
		}

        postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"%{wks.location}/bin/" .. outputdir .. "/Sandbox/\"")
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