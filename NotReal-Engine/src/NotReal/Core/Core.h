#pragma once

#include <memory>

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

namespace NotReal
{

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}