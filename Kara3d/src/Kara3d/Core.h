#pragma once


#ifdef KR_PLATFORM_WINDOWS
	#ifdef KR_BUILD_DLL
		#define KR_API __declspec(dllexport)
	#else
		#define KR_API __declspec(dllimport)
	#endif // KR_BUILD_DLL
#else 
#error KR on support Windows
#endif // KR_PLATFORM_WINDOWS
