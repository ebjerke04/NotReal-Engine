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

include "NotReal-Engine/vendor/GLFW"
include "NotReal-Engine/vendor/Glad"
include "NotReal-Engine/vendor/imgui"

project "NotReal-Engine"
    location "NotReal-Engine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "nrpch.pch"
    pchsource "NotReal-Engine/src/nrpch.cpp"

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
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"
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
        staticruntime "On"
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

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "NR_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "NR_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "NR_DIST"
        buildoptions "/MD"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

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
        "%{IncludeDir.glm}"
    }

    links
    {
        "NotReal-Engine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
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
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "NR_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "NR_DIST"
        buildoptions "/MD"
        optimize "On"