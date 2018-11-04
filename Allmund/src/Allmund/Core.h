#pragma once

#ifdef AM_PLATFORM_WINDOWS
	#ifdef AM_BUILD_DLL
		#define ALLMUND_API __declspec(dllexport)
	#else
		#define ALLMUND_API __declspec(dllimport)
	#endif
#else
	#error Allmunt only supports windows!
#endif