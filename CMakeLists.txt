cmake_minimum_required(VERSION 4.3 FATAL_ERROR)
project("GPU VANGUARD" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES *.cpp)


add_executable(gv ${SOURCES})