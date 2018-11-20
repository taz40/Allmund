workspace "Allmund"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir =  "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Allmund"
	location "Allmund"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		
		"%{prj.name}/vendor/glm",
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/GLFW/include",
		"%{prj.name}/vendor/GLEW/include",
	}

	defines{
		"GLM_ENABLE_EXPERIMENTAL",
	}

	libdirs {
		"%{prj.name}/vendor/GLFW/lib-vc2015",
		"%{prj.name}/vendor/GLEW/lib/Release/x64"
	}

	links {
		"glew32s.lib",
		"glfw3.lib",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.17134.0"

		defines{
			"GLEW_STATIC",
			"AM_BUILD_DLL",
			"AM_PLATFORM_WINDOWS",
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "AM_DEBUG_BUILD"
			symbols "On"

		filter "configurations:Release"
			defines "AM_RELEASE_BUILD"
			optimize "On"

		filter "configurations:Dist"
			defines "AM_DIST_BUILD"
			optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		
		"Allmund/vendor/glm",
		"Allmund/vendor/spdlog/include",
		"Allmund/src"
	}

	links {
		"Allmund"
	}

	defines{
		"GLM_ENABLE_EXPERIMENTAL",
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "10.0.17134.0"

		defines{
			"GLEW_STATIC",
			"AM_PLATFORM_WINDOWS",
		}

		filter "configurations:Debug"
			defines "AM_DEBUG_BUILD"
			symbols "On"

		filter "configurations:Release"
			defines "AM_RELEASE_BUILD"
			optimize "On"

		filter "configurations:Dist"
			defines "AM_DIST_BUILD"
			optimize "On"

