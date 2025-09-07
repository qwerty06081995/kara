workspace "Kara3d"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}

IncludeDir["GLFW"] = "Kara3d/vendor/GLFW/include"
IncludeDir["Glad"] = "Kara3d/vendor/Glad/include"
IncludeDir["ImGui"] = "Kara3d/vendor/imgui"

include "Kara3d/vendor/GLFW"
include "Kara3d/vendor/Glad"
include "Kara3d/vendor/imgui"

project "Kara3d"
    location "Kara3d"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "krpch.h"
    pchsource "Kara3d/src/krpch.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib",
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "KR_PLATFORM_WINDOWS",
            "KR_BUILD_DLL",
            "GLFW_INCLUDE_NONE",
            "_WINDLL",
        }

        postbuildcommands {
            "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
        }

    filter "configurations:Debug"
        defines "KR_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "KR_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "KR_DIST"
        buildoptions "/MD"
        optimize "On"

    filter "action:vs*"
        buildoptions { "/utf-8" }

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {
        "Kara3d/vendor/spdlog/include",
        "Kara3d/src"
    }

    links{
        "Kara3d"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.22621.0"

        defines {
            "KR_PLATFORM_WINDOWS",
            "_WINDLL",
        }

    filter "configurations:Debug"
		defines "KR_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "KR_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "KR_DIST"
		buildoptions "/MD"
		optimize "On"

    filter "action:vs*"
        buildoptions { "/utf-8" }