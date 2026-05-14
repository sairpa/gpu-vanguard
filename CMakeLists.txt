cmake_minimum_required(VERSION 4.3 FATAL_ERROR)
project("GPU VANGUARD" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES *.cpp)

include(FetchContent)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v5.0.0
)
FetchContent_MakeAvailable(ftxui)


add_executable(gv ${SOURCES})

target_link_libraries(gv PRIVATE ftxui::component ftxui::dom ftxui::screen)