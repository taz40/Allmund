#pragma once

#ifdef AM_PLATFORM_WINDOWS
	#ifdef AM_BUILD_DLL
		#define ALLMUND_API __declspec(dllexport)
	#else
		#define ALLMUND_API __declspec(dllimport)
	#endif
	#define AM_DEFAULT_RENDER_API RenderAPI::DirectX
#else
	#error Allmund only supports windows!
#endif