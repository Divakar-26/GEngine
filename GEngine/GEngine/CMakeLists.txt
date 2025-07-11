add_library(GEngine
    src/Application.cpp
)


target_include_directories(GEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_definitions(GEngine PUBLIC GE_PLATFORM_LINUX GE_BUILD_DLL)

