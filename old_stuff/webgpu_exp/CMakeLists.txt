cmake_minimum_required(VERSION 3.0...3.25)
project(
    LearnWebGPU # name of the project, which will also be the name of the visual studio solution if you use it
    VERSION 0.1.0 # any version number
    LANGUAGES CXX C # programming languages used by the project
)

add_subdirectory(webgpu)

add_executable(wgpu main.cpp)


set_target_properties(wgpu PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    COMPILE_WARNING_AS_ERROR ON
)
# MSVC Related changes
if (MSVC)
    target_compile_options(wgpu PRIVATE /W4 /WX) # For windows
else()
    target_compile_options(wgpu PRIVATE -Wall -Wextra -pedantic) # For fedora
endif()

target_link_libraries(wgpu PRIVATE webgpu)

target_copy_webgpu_binaries(wgpu)
