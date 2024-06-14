workspace "MinecraftAdventure"
    architecture "x64"
    startproject "Game"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- ENGINE
project "Engine"
    location "Engine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/include/**.h",
        "%{prj.name}/src/**.cpp"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS",
        "_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING"
    }

    includedirs
    {
        "%{prj.name}/include",
        "ThirdParty/raylib/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        runtime "Release"
        optimize "On"

-- MINECRAFT
project "Minecraft"
    location "Minecraft"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/include/**.h",
        "%{prj.name}/src/**.cpp"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS",
        "_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING"
    }

    includedirs
    {
        "%{prj.name}/include",
        "Engine/include",
        "ThirdParty/raylib/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        runtime "Release"
        optimize "On"

-- GAME
project "Game"
    location "Game"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS",
        "_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING"
    }

    includedirs
    {
        "Engine/include",
        "ThirdParty/raylib/include"
    }

    links
    {
        "ThirdParty/raylib/lib/raylib.lib",
        "winmm.lib",
        "kernel32.lib",
        "gdi32.lib",
        "user32.lib",
        "shell32.lib",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        runtime "Release"
        optimize "On"