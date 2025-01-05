workspace "NotReal-Engine"
    architecture "x64"

    configurations 
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "NotReal-Engine/vendor/GLFW/include"
IncludeDir["Glad"] = "NotReal-Engine/vendor/Glad/include"
IncludeDir["ImGui"] = "NotReal-Engine/vendor/imgui"
IncludeDir["glm"] = "NotReal-Engine/vendor/glm"
IncludeDir["stb_image"] = "NotReal-Engine/vendor/stb_image"

include "NotReal-Engine/vendor/GLFW"
include "NotReal-Engine/vendor/Glad"
include "NotReal-Engine/vendor/imgui"

project "NotReal-Engine"
    location "NotReal-Engine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "nrpch.pch"
    pchsource "NotReal-Engine/src/nrpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/stb_image/**.h",
        "%{prj.name}/vendor/stb_image/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.stb_image}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "NR_PLATFORM_WINDOWS",
            "NR_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        buildoptions 
        {
            "/utf-8"
        }

    filter "configurations:Debug"
        defines "NR_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "NR_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "NR_DIST"
        runtime "Release"
        optimize "on"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "NotReal-Engine/vendor/spdlog/include",
        "NotReal-Engine/src",
        "NotReal-Engine/vendor",
        "%{IncludeDir.glm}"
    }

    links
    {
        "NotReal-Engine"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "NR_PLATFORM_WINDOWS",
        }

        buildoptions 
        {
            "/utf-8"
        }

    filter "configurations:Debug"
        defines "NR_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "NR_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "NR_DIST"
        runtime "Release"
        optimize "on"