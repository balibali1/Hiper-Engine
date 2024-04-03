#pragma once

#ifdef HP_PLATFORM_WINDOWS
	#ifdef HP_BUILD_DLL
		#define HIPER_API __declspec(dllexport)
	#else
		#define HIPER_API __declspec(dllimport)
	#endif // HP_BUILD_DLL
#else
	#error Hiper only support Windows!
#endif // HP_PLATFORM_WINDOWS

#ifdef HP_ENABLE_ASSERTS
	#define HP_ASSERT(x, ...) { if(!(x)) { HP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HP_CORE_ASSERT(x, ...) { if(!(x)) { HP_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HP_ASSERT(x, ...)
	#define HP_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)