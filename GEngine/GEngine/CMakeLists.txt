add_library(GEngine
    src/Application.cpp
    src/Log.cpp
    src/gepch.cpp
    src/Platform/Linux/LinuxWindow.cpp
)


target_include_directories(GEngine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/glfw/include)

target_compile_definitions(GEngine PUBLIC GE_BUILD_DLL GE_ENABLE_ASSERTS)

target_link_libraries(GEngine PUBLIC spdlog::spdlog)
target_link_libraries(GEngine PUBLIC glfw)

target_precompile_headers(GEngine PRIVATE include/GEngine/gepch.h)