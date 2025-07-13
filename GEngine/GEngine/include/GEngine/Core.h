#pragma once

// --- Platform Detection ---
#if defined(_WIN32) || defined(_WIN64)
    #define GE_PLATFORM_WINDOWS
#elif defined(__linux__)
    #define GE_PLATFORM_LINUX
#else
    #error "Unknown platform!"
#endif

// --- DLL export/import macros ---
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

// --- Bit macro ---
#define BIT(x) (1 << x)

// --- Assertion Macros ---
#ifdef GE_ENABLE_ASSERTS
    #include "Log.h"

    #if defined(_MSC_VER)
        #define GE_DEBUGBREAK() __debugbreak()
    #else
        #include <signal.h>
        #define GE_DEBUGBREAK() raise(SIGTRAP)
    #endif

    #define GE_ASSERT(x, ...) \
        { if (!(x)) { GE_ERROR("Assertion Failed: {0}", __VA_ARGS__); GE_DEBUGBREAK(); } }

    #define GE_CORE_ASSERT(x, ...) \
        { if (!(x)) { GE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); GE_DEBUGBREAK(); } }
#else
    #define GE_ASSERT(x, ...)
    #define GE_CORE_ASSERT(x, ...)
#endif
