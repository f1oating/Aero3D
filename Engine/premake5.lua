project "Engine"
	kind "SharedLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"src"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"A3D_PLATFORM_WINDOWS",
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