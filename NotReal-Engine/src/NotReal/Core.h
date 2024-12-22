#pragma once

#ifdef NR_PLATFORM_WINDOWS
	#ifdef NR_BUILD_DLL
		#define NOTREAL_API __declspec(dllexport)
	#else
		#define NOTREAL_API __declspec(dllimport)
	#endif
#else
	#error Windows only, womp womp lil bro
#endif