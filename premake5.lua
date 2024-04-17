workspace "Hiper"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Hiper/vendor/GLFW/include"
IncludeDir["Glad"] = "Hiper/vendor/Glad/include"
IncludeDir["ImGui"] = "Hiper/vendor/imgui"

include "Hiper/vendor/GLFW"
include "Hiper/vendor/Glad"
include "Hiper/vendor/imgui"

project "Hiper"

	location "Hiper"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hppch.h"
	pchsource "Hiper/src/hppch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"

	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"HP_PLATFORM_WINDOWS",
			"HP_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "HP_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HP_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HP_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"

	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Hiper/vendor/spdlog/include",
		"Hiper/src"
	}

	links
	{
		"Hiper"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"HP_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HP_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HP_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HP_DIST"
		runtime "Release"
		optimize "On"