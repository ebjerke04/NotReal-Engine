#pragma once

#define NR_ENABLE_ASSERTS

#ifdef NR_PLATFORM_WINDOWS
#ifdef NR_DYNAMIC_LINK
	#ifdef NR_BUILD_DLL
		#define NOTREAL_API __declspec(dllexport)
	#else
		#define NOTREAL_API __declspec(dllimport)
	#endif
#else
#define NOTREAL_API
#endif
#else
	#error Windows only, womp womp lil bro
#endif

#ifdef NR_ENABLE_ASSERTS
#define NR_ASSERT(x, ...) { if(!(x)) { NR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define NR_CORE_ASSERT(x, ...) { if(!(x)) { NR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define NR_ASSERT(x, ...)
#define NR_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define NR_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)