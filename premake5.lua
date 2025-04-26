workspace "Aero3D"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Dependencies.lua"
group "Dependencies"
	include "Dependencies/glfw"

group ""

include "Engine"
include "Sandbox"