cmake_minimum_required(VERSION 3.10)
project(GEngine)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(external/spdlog)
add_subdirectory(external/glfw)
add_subdirectory(GEngine)
add_subdirectory(Sandbox)

