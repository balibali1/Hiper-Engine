#pragma once

#ifdef HP_PLATFORM_WINDOWS
	#if HP_DYNAMIC_LINK
		#ifdef HP_BUILD_DLL
			#define HIPER_API __declspec(dllexport)
		#else
			#define HIPER_API __declspec(dllimport)
		#endif // HP_BUILD_DLL
	#else
		#define HIPER_API
	#endif
#else
	#error Hiper only support Windows!
#endif // HP_PLATFORM_WINDOWS

#ifdef HP_DEBUG
	#define HP_ENABLE_ASSERTS
#endif

#ifdef HP_ENABLE_ASSERTS
	#define HP_ASSERT(x, ...) { if(!(x)) { HP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HP_CORE_ASSERT(x, ...) { if(!(x)) { HP_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HP_ASSERT(x, ...)
	#define HP_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define HP_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
