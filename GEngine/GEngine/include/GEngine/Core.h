#pragma once

// Platform detection
#if defined(_WIN32) || defined(_WIN64)
    #define GE_PLATFORM_WINDOWS
#elif defined(__linux__)
    #define GE_PLATFORM_LINUX
#else
    #error "Unknown platform!"
#endif

// DLL export/import
#ifdef GE_PLATFORM_WINDOWS
    #ifdef GE_BUILD_DLL
        #define GE_API __declspec(dllexport)
    #else
        #define GE_API __declspec(dllimport)
    #endif
#elif defined(GE_PLATFORM_LINUX)
    #define GE_API __attribute__((visibility("default")))
#else
    #define GE_API
#endif
