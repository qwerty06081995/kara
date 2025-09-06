workspace "Kara3d"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Kara3d"
    location "Kara3d"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "KR_PLATFORM_WINDOWS",
            "KR_BUILD_DLL",
            "_WINDLL",
        }

        postbuildcommands {
            "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
        }

    filter "configurations:Debug"
        defines "KR_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "KR_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "KR_DIST"
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
        symbols "On"

    filter "configurations:Release"
        defines "KR_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "KR_DIST"
        optimize "On"

    filter "action:vs*"
        buildoptions { "/utf-8" }