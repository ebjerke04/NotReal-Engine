workspace "NotReal-Engine"
    architecture "x64"

    configurations 
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "NR_PLATFORM_WINDOWS",
            "NR_BUILD_DLL"
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
        symbols "On"

    filter "configurations:Release"
        defines "NR_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "NR_DIST"
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
        "NotReal-Engine/src"
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
        symbols "On"

    filter "configurations:Release"
        defines "NR_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "NR_DIST"
        optimize "On"